
#include <cliext/vector>
#include <cmath>
#include <Windows.h>
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Threading;

public ref class HeatTransferForm : public Form {
private:
    PictureBox^ pictureBox;
    Button^ simulateButton;
    Label^ statusLabel;
    NumericUpDown^ waterTempInput;
    NumericUpDown^ heaterTempInput;
    NumericUpDown^ alphaInput;
    NumericUpDown^ dtInput;
    NumericUpDown^ dxInput;
    NumericUpDown^ dyInput;

    array<double, 2>^ temperature;
    const int gridWidth = 100;
    const int gridHeight = 100;

    double alpha = 0.01; // Коэффициент теплопроводности
    double dt = 0.1;    // Шаг по времени
    double dx = 1.0;   // Шаг по пространству
    double dy = 1.0;   // Шаг по пространству

    double initialWaterTemp = 0.0;
    double initialHeaterTemp = 100.0;
    bool isSimulating = false;

public:
    HeatTransferForm() {
        // Инициализация элементов
        this->Text = "Модель теплопередачи";
        this->Width = 800;
        this->Height = 700;

        pictureBox = gcnew PictureBox();
        pictureBox->Width = 600;
        pictureBox->Height = 400;
        pictureBox->Top = 20;
        pictureBox->Left = 100;
        pictureBox->BackColor = Color::White;
        this->Controls->Add(pictureBox);

        simulateButton = gcnew Button();
        simulateButton->Text = "Запустить моделирование";
        simulateButton->Top = 550;
        simulateButton->Left = 300;
        simulateButton->Click += gcnew EventHandler(this, &HeatTransferForm::OnSimulateButtonClick);
        this->Controls->Add(simulateButton);

        statusLabel = gcnew Label();
        statusLabel->Text = "Статус: Ожидание";
        statusLabel->Top = 600;
        statusLabel->Left = 300;
        this->Controls->Add(statusLabel);

        // Поля для ввода параметров
        Label^ waterTempLabel = gcnew Label();
        waterTempLabel->Text = "Начальная температура воды:";
        waterTempLabel->Top = 450;
        waterTempLabel->Left = 50;
        this->Controls->Add(waterTempLabel);

        waterTempInput = gcnew NumericUpDown();
        waterTempInput->Top = 470;
        waterTempInput->Left = 50;
        waterTempInput->Minimum = -50;
        waterTempInput->Maximum = 100;
        waterTempInput->Value = Decimal(initialWaterTemp);
        this->Controls->Add(waterTempInput);

        Label^ heaterTempLabel = gcnew Label();
        heaterTempLabel->Text = "Температура нагревателя:";
        heaterTempLabel->Top = 450;
        heaterTempLabel->Left = 250;
        this->Controls->Add(heaterTempLabel);

        heaterTempInput = gcnew NumericUpDown();
        heaterTempInput->Top = 470;
        heaterTempInput->Left = 250;
        heaterTempInput->Minimum = 0;
        heaterTempInput->Maximum = 500;
        heaterTempInput->Value = Decimal(initialHeaterTemp);
        this->Controls->Add(heaterTempInput);

        Label^ alphaLabel = gcnew Label();
        alphaLabel->Text = "Коэффициент теплопроводности:";
        alphaLabel->Top = 450;
        alphaLabel->Left = 450;
        this->Controls->Add(alphaLabel);

        alphaInput = gcnew NumericUpDown();
        alphaInput->Top = 470;
        alphaInput->Left = 450;
        alphaInput->DecimalPlaces = 2;
        alphaInput->Increment = Decimal(0.01);
        alphaInput->Minimum = Decimal(0.01);
        alphaInput->Maximum = Decimal(1.0);
        alphaInput->Value = Decimal(alpha);
        this->Controls->Add(alphaInput);

        Label^ dtLabel = gcnew Label();
        dtLabel->Text = "Шаг по времени:";
        dtLabel->Top = 500;
        dtLabel->Left = 50;
        this->Controls->Add(dtLabel);

        dtInput = gcnew NumericUpDown();
        dtInput->Top = 520;
        dtInput->Left = 50;
        dtInput->DecimalPlaces = 2;
        dtInput->Increment = Decimal(0.01);
        dtInput->Minimum = Decimal(0.01);
        dtInput->Maximum = Decimal(1.0);
        dtInput->Value = Decimal(dt);
        this->Controls->Add(dtInput);

        Label^ dxLabel = gcnew Label();
        dxLabel->Text = "Шаг по пространству (dx):";
        dxLabel->Top = 500;
        dxLabel->Left = 250;
        this->Controls->Add(dxLabel);

        dxInput = gcnew NumericUpDown();
        dxInput->Top = 520;
        dxInput->Left = 250;
        dxInput->DecimalPlaces = 1;
        dxInput->Increment = Decimal(0.1);
        dxInput->Minimum = Decimal(0.1);
        dxInput->Maximum = Decimal(10.0);
        dxInput->Value = Decimal(dx);
        this->Controls->Add(dxInput);

        Label^ dyLabel = gcnew Label();
        dyLabel->Text = "Шаг по пространству (dy):";
        dyLabel->Top = 500;
        dyLabel->Left = 450;
        this->Controls->Add(dyLabel);

        dyInput = gcnew NumericUpDown();
        dyInput->Top = 520;
        dyInput->Left = 450;
        dyInput->DecimalPlaces = 1;
        dyInput->Increment = Decimal(0.1);
        dyInput->Minimum = Decimal(0.1);
        dyInput->Maximum = Decimal(10.0);
        dyInput->Value = Decimal(dy);
        this->Controls->Add(dyInput);

        temperature = gcnew array<double, 2>(gridWidth, gridHeight);
        InitializeTemperature();
    }

    void InitializeTemperature() {
        for (int i = 0; i < gridWidth; i++) {
            for (int j = 0; j < gridHeight; j++) {
                temperature[i, j] = initialWaterTemp;
            }
        }

        // Задаем начальные условия - нагреватель в центре нижней части
        for (int i = 40; i <= 60; i++) {
            for (int j = 80; j <= 99; j++) {
                temperature[i, j] = initialHeaterTemp;
            }
        }

        // Добавляем температуры для металлических стенок (снизу, сверху, слева и справа)
        for (int i = 0; i < gridWidth; i++) {
            temperature[0, i] = initialWaterTemp; // Верхняя металлическая стенка
            temperature[gridHeight - 1, i] = initialWaterTemp; // Нижняя металлическая стенка
        }
        for (int i = 0; i < gridHeight; i++) {
            temperature[i, 0] = initialWaterTemp; // Левая металлическая стенка
            temperature[i, gridWidth - 1] = initialWaterTemp; // Правая металлическая стенка
        }
    }

    void OnSimulateButtonClick(Object^ sender, EventArgs^ e) {
        if (isSimulating) return;

        // Обновляем параметры
        initialWaterTemp = double(waterTempInput->Value);
        initialHeaterTemp = double(heaterTempInput->Value);
        alpha = double(alphaInput->Value);
        dt = double(dtInput->Value);
        dx = double(dxInput->Value);
        dy = double(dyInput->Value);

        InitializeTemperature();

        isSimulating = true;
        simulateButton->Enabled = false;
        statusLabel->Text = "Статус: Моделирование...";

        Thread^ simulationThread = gcnew Thread(gcnew ThreadStart(this, &HeatTransferForm::SimulateHeatTransfer));
        simulationThread->Start();
    }

    void SimulateHeatTransfer() {
        Graphics^ g = pictureBox->CreateGraphics();
        Bitmap^ bitmap = gcnew Bitmap(gridWidth, gridHeight);

        double wallHeatingFactor = 4.0; // Ускорение нагрева стенок

        for (int step = 0; step < 500; step++) {
            array<double, 2>^ newTemperature = gcnew array<double, 2>(gridWidth, gridHeight);

            // Рассчитываем новую температуру
            for (int i = 1; i < gridWidth - 1; i++) {
                for (int j = 1; j < gridHeight - 1; j++) {
                    double tx = (temperature[i + 1, j] - 2 * temperature[i, j] + temperature[i - 1, j]) / (dx * dx);
                    double ty = (temperature[i, j + 1] - 2 * temperature[i, j] + temperature[i, j - 1]) / (dy * dy);
                    newTemperature[i, j] = temperature[i, j] + alpha * dt * (tx + ty);
                }
            }

            // Ускоренное обновление температуры для металлических стенок
            for (int i = 0; i < gridWidth; i++) {
                newTemperature[0, i] = temperature[1, i] * wallHeatingFactor; // Верхняя стенка
                newTemperature[gridHeight - 1, i] = temperature[gridHeight - 2, i] * wallHeatingFactor; // Нижняя стенка
            }
            for (int j = 0; j < gridHeight; j++) {
                newTemperature[j, 0] = temperature[j, 1] * wallHeatingFactor; // Левая стенка
                newTemperature[j, gridWidth - 1] = temperature[j, gridWidth - 2] * wallHeatingFactor; // Правая стенка
            }

            // Ограничиваем температуру стенок до заданного предела
            double maxWallTemperature = initialHeaterTemp;
            for (int i = 0; i < gridWidth; i++) {
                newTemperature[0, i] = Math::Min(newTemperature[0, i], maxWallTemperature);
                newTemperature[gridHeight - 1, i] = Math::Min(newTemperature[gridHeight - 1, i], maxWallTemperature);
            }
            for (int j = 0; j < gridHeight; j++) {
                newTemperature[j, 0] = Math::Min(newTemperature[j, 0], maxWallTemperature);
                newTemperature[j, gridWidth - 1] = Math::Min(newTemperature[j, gridWidth - 1], maxWallTemperature);
            }

            // Обновляем массив температур
            for (int i = 0; i < gridWidth; i++) {
                for (int j = 0; j < gridHeight; j++) {
                    temperature[i, j] = newTemperature[i, j];
                }
            }

            // Отображаем температуру
            this->Invoke(gcnew MethodInvoker(this, &HeatTransferForm::RedrawGraphics));

            Thread::Sleep(50);
        }

        delete g;
        isSimulating = false;
        this->Invoke(gcnew MethodInvoker(this, &HeatTransferForm::OnSimulationComplete));
    }

    // Изменения в методе RedrawGraphics
    //void RedrawGraphics() {
    //    Bitmap^ bitmap = gcnew Bitmap(gridWidth, gridHeight);

    //    for (int i = 0; i < gridWidth; i++) {
    //        for (int j = 0; j < gridHeight; j++) {
    //            // Нагреватель черным цветом
    //            if (i >= 40 && i <= 60 && j >= 80 && j <= 99) {
    //                bitmap->SetPixel(i, j, Color::Black);
    //            }
    //            // Стенки с градиентом
    //            else if (i == 0 || i == gridHeight - 1 || j == 0 || j == gridWidth - 1) {
    //                int wallRed = Math::Min(255, (int)(temperature[i, j] * 2.55));
    //                int wallBlue = Math::Max(0, 255 - wallRed);
    //                bitmap->SetPixel(i, j, Color::FromArgb(wallRed, 0, wallBlue));
    //            }
    //            else {
    //                // Градиент для жидкости
    //                int red = Math::Min(255, (int)(temperature[i, j] * 2.55));
    //                int blue = Math::Max(0, 255 - red);
    //                int green = Math::Max(0, 128 - (int)(temperature[i, j] * 1.28));
    //                bitmap->SetPixel(i, j, Color::FromArgb(red, green, blue));
    //            }
    //        }
    //    }

    //    Graphics^ g = pictureBox->CreateGraphics();
    //    g->DrawImage(bitmap, 0, 0, pictureBox->Width, pictureBox->Height);
    //    delete g;
    //}
    //void RedrawGraphics() {
    //    Bitmap^ bitmap = gcnew Bitmap(gridWidth, gridHeight);

    //    // Уровни изотерм
    //    array<double>^ isothermLevels = gcnew array<double> { 10.0, 20.0, 30.0, 40.0, 50.0, 60.0, 70.0, 80.0, 90.0 };

    //    for (int i = 0; i < gridWidth; i++) {
    //        for (int j = 0; j < gridHeight; j++) {
    //            // Нагреватель черным цветом
    //            if (i >= 40 && i <= 60 && j >= 80 && j <= 99) {
    //                bitmap->SetPixel(i, j, Color::Black);
    //            }
    //            // Стенки с градиентом
    //            else if (i == 0 || i == gridHeight - 1 || j == 0 || j == gridWidth - 1) {
    //                int wallRed = Math::Min(255, (int)(temperature[i, j] * 2.55));
    //                int wallBlue = Math::Max(0, 255 - wallRed);
    //                bitmap->SetPixel(i, j, Color::FromArgb(wallRed, 0, wallBlue));
    //            }
    //            else {
    //                // Градиент для жидкости
    //                int red = Math::Min(255, (int)(temperature[i, j] * 2.55));
    //                int blue = Math::Max(0, 255 - red);
    //                int green = Math::Max(0, 128 - (int)(temperature[i, j] * 1.28));
    //                bitmap->SetPixel(i, j, Color::FromArgb(red, green, blue));
    //            }
    //        }
    //    }

    //    // Добавление изотермических линий
    //    for each (double isotherm in isothermLevels) {
    //        for (int i = 1; i < gridWidth - 1; i++) {
    //            for (int j = 1; j < gridHeight - 1; j++) {
    //                // Проверяем, пересекает ли текущая ячейка уровень изотермы
    //                if ((temperature[i, j] <= isotherm && temperature[i + 1, j] > isotherm) ||
    //                    (temperature[i, j] > isotherm && temperature[i + 1, j] <= isotherm) ||
    //                    (temperature[i, j] <= isotherm && temperature[i, j + 1] > isotherm) ||
    //                    (temperature[i, j] > isotherm && temperature[i, j + 1] <= isotherm)) {
    //                    bitmap->SetPixel(i, j, Color::White); // Белые точки для линий
    //                }
    //            }
    //        }
    //    }

    //    Graphics^ g = pictureBox->CreateGraphics();
    //    g->DrawImage(bitmap, 0, 0, pictureBox->Width, pictureBox->Height);
    //    delete g;
    //}
    void RedrawGraphics() {
        Bitmap^ bitmap = gcnew Bitmap(gridWidth, gridHeight);

        // Уровни изотерм (каждый уровень теперь будет добавляться по мере нагрева)
        array<double>^ isothermLevels = gcnew array<double> { 10.0,  40.0,   70.0,  90.0 };

        // Обновление изображения температуры
        for (int i = 0; i < gridWidth; i++) {
            for (int j = 0; j < gridHeight; j++) {
                // Нагреватель черным цветом
                if (i >= 40 && i <= 60 && j >= 80 && j <= 99) {
                    bitmap->SetPixel(i, j, Color::Black);
                }
                // Стенки с градиентом
                else if (i == 0 || i == gridHeight - 1 || j == 0 || j == gridWidth - 1) {
                    int wallRed = Math::Min(255, (int)(temperature[i, j] * 2.55));
                    int wallBlue = Math::Max(0, 255 - wallRed);
                    bitmap->SetPixel(i, j, Color::FromArgb(wallRed, 0, wallBlue));
                }
                else {
                    // Градиент для жидкости
                    int red = Math::Min(255, (int)(temperature[i, j] * 2.55));
                    int blue = Math::Max(0, 255 - red);
                    int green = Math::Max(0, 128 - (int)(temperature[i, j] * 1.28));
                    bitmap->SetPixel(i, j, Color::FromArgb(red, green, blue));
                }
            }
        }

        // Добавление изотермических линий
        for each (double isotherm in isothermLevels) {
            for (int i = 1; i < gridWidth - 1; i++) {
                for (int j = 1; j < gridHeight - 1; j++) {
                    // Проверяем, пересекает ли текущая ячейка уровень изотермы
                    if ((temperature[i, j] <= isotherm && temperature[i + 1, j] > isotherm) ||
                        (temperature[i, j] > isotherm && temperature[i + 1, j] <= isotherm) ||
                        (temperature[i, j] <= isotherm && temperature[i, j + 1] > isotherm) ||
                        (temperature[i, j] > isotherm && temperature[i, j + 1] <= isotherm)) {
                        bitmap->SetPixel(i, j, Color::White); // Белые точки для линий
                    }
                }
            }
        }

        // Отображение изображения на PictureBox
        Graphics^ g = pictureBox->CreateGraphics();
        g->DrawImage(bitmap, 0, 0, pictureBox->Width, pictureBox->Height);
        delete g;
    }


    void OnSimulationComplete() {
        simulateButton->Enabled = true;
        statusLabel->Text = "Статус: Готово!";
    }
};

[STAThread]
void main() {
    Application::EnableVisualStyles();
    Application::Run(gcnew HeatTransferForm());
}
