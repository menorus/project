#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <cmath>
#include <complex>
#include <windows.h>
#include <string>

//#include "Chart.h" // Подключение библиотеки System.Windows.Forms.DataVisualization.Charting

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Windows::Forms::DataVisualization::Charting;


const double hbar = 1.0;      // Постоянная Планка
 double m = 1.0;         // Масса частицы
 double k = 1.0;         // Коэффициент жесткости гармонического осциллятора
 double dx = 0.1;        // Шаг по пространству
 double dt = 0.01;       // Шаг по времени
 double x_max = 5.0;     // Максимальное значение x
 int steps = 1000;       // Количество временных шагов

typedef std::complex<double> Complex;

// Потенциальная энергия U(x)
double potential(double x) {
    return 0.5 * k * x * x;
}


#include <complex>  // Подключаем заголовок для работы с комплексными числами

std::vector<Complex> initialize_wavefunction(double dx, double x_max) {
    std::vector<Complex> psi;
    double sigma = 0.5;  // Ширина гауссиана
    double x0 = 0.0;     // Центр волнового пакета на нуле
    double k0 = 4.0;     // Начальная волновая волна
    for (double x = -x_max; x <= x_max; x += dx) {
        // Используем комплексную экспоненту для вычисления фазы
        Complex phase = std::exp(Complex(0, k0 * x));  // Экспонента комплексного числа

        // Начальная волновая функция в виде гауссового пакета с фазой для движения
        Complex value = std::exp(-(x - x0) * (x - x0) / (2 * sigma * sigma)) * phase;
        psi.emplace_back(value);
    }
    return psi;
}



// Расчет коэффициентов A, B, C, D и обновление волновой функции методом сеточной прогонки
std::vector<Complex> ABCD(double R, const std::vector<Complex>& wave, double dt, double k) {
    size_t n = wave.size();
    double stepx = 2 * R / n;

    std::vector<Complex> A(n), B(n), C(n), D(n);
    std::vector<Complex> alpha(n), beta(n);
    std::vector<Complex> Psi(n);

    for (size_t i = 1; i < n - 1; i++) {
        double xi = i * stepx;
        double xi_minus_1 = (i - 1) * stepx;
        double xi_plus_1 = (i + 1) * stepx;

        A[i] = -(Complex(0, dt) / ((xi_plus_1 - xi_minus_1) * (xi - xi_minus_1)));
        B[i] = -(Complex(0, dt) / ((xi_plus_1 - xi_minus_1) * (xi_plus_1 - xi)));
        C[i] = Complex(1, 0) + Complex(0, dt * 0.5) * potential(xi) +
            (Complex(0, dt) * (1.0 / (xi_plus_1 - xi) + 1.0 / (xi - xi_minus_1))) / (xi_plus_1 - xi_minus_1);

        Complex sigma2_wave = Complex(2.0) * ((wave[i + 1] - wave[i]) / (xi_plus_1 - xi) -
            (wave[i] - wave[i - 1]) / (xi - xi_minus_1)) /
            (xi_plus_1 - xi_minus_1);
        D[i] = wave[i] + Complex(0, dt * 0.5) * (sigma2_wave - potential(xi) * wave[i]);
    }

    // Прямой ход прогонки
    alpha[1] = 0;
    beta[1] = 0;

    for (size_t i = 1; i < n - 1; i++) {
        alpha[i + 1] = -B[i] / (C[i] + A[i] * alpha[i]);
        beta[i + 1] = (D[i] - A[i] * beta[i]) / (C[i] + A[i] * alpha[i]);
    }

    // Обратный ход прогонки
    Psi[n - 1] = 0;
    Psi[0] = 0;

    for (size_t i = n - 2; i >= 1; i--) {
        Psi[i] = alpha[i + 1] * Psi[i + 1] + beta[i + 1];
    }

    return Psi;
}

// Нахождение плотности вероятности
std::vector<double> probability_density(const std::vector<Complex>& psi) {
    std::vector<double> density(psi.size());
    for (size_t i = 0; i < psi.size(); ++i) {
        density[i] = std::norm(psi[i]);
    }
    return density;
}

// Класс для управления симуляцией
class QuantumSimulation {
public:
    std::vector<Complex> psi;
    std::vector<double> x;
    std::vector<std::vector<Complex>> allStepsPsi; // Хранение всех шагов
    int currentStep;

    QuantumSimulation() {
        size_t n_points = static_cast<size_t>(2 * x_max / dx) + 1;
        double R = x_max;
        x.resize(n_points);
        for (size_t i = 0; i < n_points; ++i) {
            x[i] = -x_max + i * dx;
        }
        psi = initialize_wavefunction(dx, x_max);
        currentStep = 0;
        allStepsPsi.push_back(psi);
    }

    void Step() {
        psi = ABCD(x_max, psi, dt, k);
        currentStep++;
        allStepsPsi.push_back(psi);
    }

    std::vector<double> GetProbabilityDensity(int step =-1) {
        const auto& selectedPsi = (step >= 0 && step < allStepsPsi.size()) ? allStepsPsi[step] : psi;
        return probability_density(psi);
    }
};
public ref class SpectrumForm : public Form {
    private:
        Chart^ chart;
    
    public:

        SpectrumForm(const std::vector<std::complex<double>>& psi) {
            this->Text = "Спектр";
            this->Width = 800;
            this->Height = 600;
    
            chart = gcnew Chart();
            chart->Dock = DockStyle::Fill;
            this->Controls->Add(chart);
    
            ChartArea^ chartArea = gcnew ChartArea("SpectrumArea");
            chart->ChartAreas->Add(chartArea);
    
            Series^ spectrumSeries = gcnew Series("Spectrum");
            spectrumSeries->ChartType = SeriesChartType::Line;
            chart->Series->Add(spectrumSeries);
    
            // Вычисление спектра через преобразование Фурье
            std::vector<double> spectrum = computeFourierTransform(psi);
    
            // Добавление данных спектра в график
            for (size_t i = 0; i < spectrum.size(); ++i) {
                spectrumSeries->Points->AddXY(i, spectrum[i]);
            }
        }
    
        // Функция вычисления преобразования Фурье
        std::vector<double> computeFourierTransform(const std::vector<std::complex<double>>& psi) {
            size_t n = psi.size();
            std::vector<std::complex<double>> fft(n);
    
            // Простое вычисление дискретного преобразования Фурье
            for (size_t k = 0; k < n; ++k) {
                fft[k] = 0.0;
                for (size_t j = 0; j < n; ++j) {
                    double angle = -2.0 * M_PI * k * j / n;
                    fft[k] += psi[j] * std::polar(1.0, angle);
                }
            }
    
            // Возвращаем спектральную плотность
            std::vector<double> spectrum(n);
            for (size_t i = 0; i < n; ++i) {
                spectrum[i] = std::norm(fft[i]);
            }
            return spectrum;
        }
    };
//public ref class SpectrumForm1 : public Form {
//private:
//    Chart^ chart;
//
//public:
//
//    SpectrumForm1(const std::vector<std::complex<double>>& psi, int step) {
//        this->Text = "Спектр для шага " + step;
//        this->Width = 800;
//        this->Height = 600;
//
//        chart = gcnew Chart();
//        chart->Dock = DockStyle::Fill;
//        this->Controls->Add(chart);
//
//        ChartArea^ chartArea = gcnew ChartArea("SpectrumArea");
//        chart->ChartAreas->Add(chartArea);
//
//        Series^ spectrumSeries = gcnew Series("Spectrum");
//        spectrumSeries->ChartType = SeriesChartType::Line;
//        chart->Series->Add(spectrumSeries);
//
//        // Вычисление спектра через преобразование Фурье
//        std::vector<double> spectrum = computeFourierTransform(psi);
//
//        // Добавление данных спектра в график
//        for (size_t i = 0; i < spectrum.size(); ++i) {
//            spectrumSeries->Points->AddXY(i, spectrum[i]);
//        }
//    }
//
//
//    // Функция вычисления преобразования Фурье
//    std::vector<double> computeFourierTransform(const std::vector<std::complex<double>>& psi) {
//        size_t n = psi.size();
//        std::vector<std::complex<double>> fft(n);
//
//        // Простое вычисление дискретного преобразования Фурье
//        for (size_t k = 0; k < n; ++k) {
//            fft[k] = 0.0;
//            for (size_t j = 0; j < n; ++j) {
//                double angle = -2.0 * M_PI * k * j / n;
//                fft[k] += psi[j] * std::polar(1.0, angle);
//            }
//        }
//
//        // Возвращаем спектральную плотность
//        std::vector<double> spectrum(n);
//        for (size_t i = 0; i < n; ++i) {
//            spectrum[i] = std::norm(fft[i]);
//        }
//        return spectrum;
//    }
//};
    public ref class ColumnValuesForm : public Form {
    public:
        ColumnValuesForm(const std::vector<std::complex<double>>& columnData, int xIndex) {
            this->Text = "График значений столбца " + xIndex;
            this->Width = 800;
            this->Height = 600;

            Chart^ chart = gcnew Chart();
            chart->Dock = DockStyle::Fill;
            this->Controls->Add(chart);

            // Настройка области графика
            ChartArea^ chartArea = gcnew ChartArea("ColumnValuesArea");
            chartArea->AxisX->Title = "Индекс";
          //  chartArea->AxisY->Title = "Значение (действительная часть)";
            chart->ChartAreas->Add(chartArea);

            // Создание серии для графика
            Series^ realPartSeries = gcnew Series("");
            realPartSeries->ChartType = SeriesChartType::Line;
            realPartSeries->Color = System::Drawing::Color::Blue;
            chart->Series->Add(realPartSeries);

            // Добавление данных в график
            for (size_t i = 0; i < columnData.size(); ++i) {
                realPartSeries->Points->AddXY(i, columnData[i].real());
            }

            // Настройка легенды
            Legend^ legend = gcnew Legend();
            chart->Legends->Add(legend);
        }
    };

    public ref class SpectrumForm1 : public Form {
    private:
        Chart^ chart;
        const std::vector<std::vector<std::complex<double>>>* allStepsPsi;

    public:
        SpectrumForm1(const std::vector<std::complex<double>>& psi,
            int step,
            const std::vector<std::vector<std::complex<double>>>* allStepsPsiRef) {
            this->Text = "Спектр для шага " + step;
            this->Width = 800;
            this->Height = 600;

            this->allStepsPsi = allStepsPsiRef;

            chart = gcnew Chart();
            chart->Dock = DockStyle::Fill;
            this->Controls->Add(chart);

            ChartArea^ chartArea = gcnew ChartArea("SpectrumArea");
            chart->ChartAreas->Add(chartArea);

            Series^ spectrumSeries = gcnew Series("Spectrum");
            spectrumSeries->ChartType = SeriesChartType::Line;
            chart->Series->Add(spectrumSeries);

            // Вычисление спектра через преобразование Фурье
            std::vector<double> spectrum = computeFourierTransform(psi);

            // Добавление данных спектра в график
            for (size_t i = 0; i < spectrum.size(); ++i) {
                spectrumSeries->Points->AddXY(i, spectrum[i]);
            }

            // Подключаем обработчик кликов
            chart->MouseClick += gcnew MouseEventHandler(this, &SpectrumForm1::OnChartMouseClick);
        }

    private:
        // Функция вычисления преобразования Фурье
        std::vector<double> computeFourierTransform(const std::vector<std::complex<double>>& psi) {
            size_t n = psi.size();
            std::vector<std::complex<double>> fft(n);

            // Простое вычисление дискретного преобразования Фурье
            for (size_t k = 0; k < n; ++k) {
                fft[k] = 0.0;
                for (size_t j = 0; j < n; ++j) {
                    double angle = -2.0 * M_PI * k * j / n;
                    fft[k] += psi[j] * std::polar(1.0, angle);
                }
            }

            // Возвращаем спектральную плотность
            std::vector<double> spectrum(n);
            for (size_t i = 0; i < n; ++i) {
                spectrum[i] = std::norm(fft[i]);
            }
            return spectrum;
        }

        // Обработчик клика по графику
        void OnChartMouseClick(Object^ sender, MouseEventArgs^ e) {
            if (e->Button == System::Windows::Forms::MouseButtons::Left) {
                HitTestResult^ hit = chart->HitTest(e->X, e->Y);
                if (hit->ChartElementType == ChartElementType::DataPoint) {
                    int selectedX = hit->PointIndex;

                    if (selectedX >= 0 && selectedX < allStepsPsi->size()) {
                        std::vector<std::complex<double>> selectedColumn = (*allStepsPsi)[selectedX];

                        // Открываем новое окно для отображения значений столбца
                        ColumnValuesForm^ columnForm = gcnew ColumnValuesForm(selectedColumn, selectedX);
                        columnForm->Show();
                    }
                }
            }
        }
    };

   


// Класс для формы Windows Forms
ref class QuantumForm : public Form {
private:
    Chart^ chart;
    Button^ startButton;
    Button^ spectrumButton;
    Button^ applyParamsButton;
    Button^ viewStepButton;
    TextBox^ stepInputBox; // Выбор шага
    Timer^ timer;
    Series^ series;

    Label^ labelMass;
    Label^ labelK;
    Label^ labelDx;
    Label^ labelDt;
    Label^ labelXMax;
    Label^ labelSteps;

    TextBox^ textMass;
    TextBox^ textK;
    TextBox^ textDx;
    TextBox^ textDt;
    TextBox^ textXMax;
    TextBox^ textSteps;
    ComboBox^ viewModeComboBox;
    QuantumSimulation* simulation;

public:
    QuantumForm() {
        this->Text = "Яма";
        this->Width = 800;
        this->Height = 800;

        chart = gcnew Chart();
        chart->Dock = DockStyle::Top;
        chart->Height = 400;
        this->Controls->Add(chart);

        ChartArea^ chartArea = gcnew ChartArea("MainArea");
        chart->ChartAreas->Add(chartArea);

        series = gcnew Series("Wavefunction");
        series->ChartType = SeriesChartType::Line;
        chart->Series->Add(series);

        series = gcnew Series("Density");
        series->ChartType = SeriesChartType::Line;
        chart->Series->Add(series);

        startButton = gcnew Button();
        startButton->Text = "Старт";
        startButton->Dock = DockStyle::Bottom;
        startButton->Click += gcnew EventHandler(this, &QuantumForm::OnStartButtonClick);
        this->Controls->Add(startButton);

        spectrumButton = gcnew Button();
        spectrumButton->Text = "Спектр";
        spectrumButton->Dock = DockStyle::Bottom;
        spectrumButton->Click += gcnew EventHandler(this, &QuantumForm::OnSpectrumButtonClick);
        this->Controls->Add(spectrumButton);


        applyParamsButton = gcnew Button();
        applyParamsButton->Text = "Новые параметры";
        applyParamsButton->Dock = DockStyle::Bottom;
        applyParamsButton->Click += gcnew EventHandler(this, &QuantumForm::OnApplyParametersClick);
        this->Controls->Add(applyParamsButton);

        // Поле для ввода шага
        stepInputBox = gcnew TextBox();
        stepInputBox->Text = "0"; // По умолчанию шаг 0
        stepInputBox->Location = System::Drawing::Point(3, 590);
        this->Controls->Add(stepInputBox);

        // Кнопка для отображения спектра на определенном шаге
        viewStepButton = gcnew Button();
        viewStepButton->Text = "Посмотреть шаг";
        viewStepButton->Location = System::Drawing::Point(150, 590);
        viewStepButton->Click += gcnew EventHandler(this, &QuantumForm::OnViewStepButtonClick);
        this->Controls->Add(viewStepButton);

        // Timer
        timer = gcnew Timer();
        timer->Interval = 5; // Интервал в миллисекундах
        timer->Tick += gcnew EventHandler(this, &QuantumForm::OnTimerTick);

        // Input Labels and TextBoxes
        InitializeParameterControls();

        // Simulation
        simulation = new QuantumSimulation();
        UpdateChart();
    }
    void QuantumForm::OnViewStepButtonClick(Object^ sender, EventArgs^ e) {
        int step = 0;

        try {
            step = System::Convert::ToInt32(stepInputBox->Text);
        }
        catch (Exception^) {
            MessageBox::Show("Введите корректное значение для шага.");
            return;
        }

        if (step < 0 || step >= steps) {
            MessageBox::Show("Шаг должен быть в диапазоне от 0 до " + steps.ToString() + ".");
            return;
        }
        if (step >= simulation->allStepsPsi[0].size()) {
            MessageBox::Show("Данные для указанного шага ещё не рассчитаны.");
            return;
        }

        // Извлечение данных столбца для данного временного шага
        std::vector<std::complex<double>> stepColumn;
        for (size_t i = 0; i < simulation->allStepsPsi.size(); ++i) {
            stepColumn.push_back(simulation->allStepsPsi[i][step]);
        }

        // Передаём allStepsPsi для кликов
        SpectrumForm1^ spectrumForm = gcnew SpectrumForm1(stepColumn, step, &(simulation->allStepsPsi));
        spectrumForm->Show();
    }


    void QuantumForm::UpdateChart(int step) {
        series->Points->Clear();
        std::vector<double> density;

        // Если step == -1, отображаем текущий шаг, иначе конкретный шаг
        if (step == -1) {
            density = simulation->GetProbabilityDensity();
        }
        else {
            density = simulation->GetProbabilityDensity(step);
        }

        for (size_t i = 0; i < simulation->x.size(); ++i) {
            series->Points->AddXY(simulation->x[i], density[i]);
        }
    }
    ~QuantumForm() {
        delete simulation;
    }

    void OnStartButtonClick(Object^ sender, EventArgs^ e) {
        if (!timer->Enabled) {
            timer->Start();
            startButton->Text = "пауза";
        }
        else {
            timer->Stop();
            startButton->Text = "старт";
        }
    }

    void OnTimerTick(Object^ sender, EventArgs^ e) {
        if (simulation->currentStep >= steps) {
            timer->Stop();
            startButton->Text = "Start";
            return;
        }

        simulation->Step();
        UpdateChart();
    }

    void OnSpectrumButtonClick(Object^ sender, EventArgs^ e) {
        SpectrumForm^ spectrumForm = gcnew SpectrumForm(simulation->psi);
        spectrumForm->Show();
    }

    void OnApplyParametersClick(Object^ sender, EventArgs^ e) {
        // Update parameters from TextBox inputs
        double newMass = System::Convert::ToDouble(textMass->Text);
        double newK = System::Convert::ToDouble(textK->Text);
        double newDx = System::Convert::ToDouble(textDx->Text);
        double newDt = System::Convert::ToDouble(textDt->Text);
        double newXMax = System::Convert::ToDouble(textXMax->Text);
        int newSteps = System::Convert::ToInt32(textSteps->Text);

        // Update global constants
        m = newMass;
        k = newK;
        dx = newDx;
        dt = newDt;
        x_max = newXMax;
        steps = newSteps;

        // Reinitialize simulation
        delete simulation;
        simulation = new QuantumSimulation();

        // Update the chart
        UpdateChart();
    }

    void UpdateChart() {
        series->Points->Clear();
        std::vector<double> density = simulation->GetProbabilityDensity();
        for (size_t i = 0; i < simulation->x.size(); ++i) {
            series->Points->AddXY(simulation->x[i], density[i]);
        }
    }

    void InitializeParameterControls() {
        labelMass = CreateLabel("Mass (m):", 3, 410);
        textMass = CreateTextBox(System::Convert::ToString(m), 110, 410);

        labelK = CreateLabel("k:", 3, 440);
        textK = CreateTextBox(System::Convert::ToString(k), 110, 440);

        labelDx = CreateLabel("dx:", 3, 470);
        textDx = CreateTextBox(System::Convert::ToString(dx), 110, 470);

        labelDt = CreateLabel("dt:", 3, 500);
        textDt = CreateTextBox(System::Convert::ToString(dt), 110, 500);

        labelXMax = CreateLabel("x_max:", 3, 530);
        textXMax = CreateTextBox(System::Convert::ToString(x_max), 110, 530);

        labelSteps = CreateLabel("Steps:", 3, 560);
        textSteps = CreateTextBox(System::Convert::ToString(steps), 110, 560);
    }

    Label^ CreateLabel(String^ text, int x, int y) {
        Label^ label = gcnew Label();
        label->Text = text;
        label->Location = System::Drawing::Point(x, y);
        this->Controls->Add(label);
        return label;
    }

    TextBox^ CreateTextBox(String^ text, int x, int y) {
        TextBox^ textBox = gcnew TextBox();
        textBox->Text = text;
        textBox->Location = System::Drawing::Point(x, y);
        this->Controls->Add(textBox);
        return textBox;
    }

};

[STAThread]
void main() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew QuantumForm());
}
