#include <cliext/vector>
#include <math.h>

#define grid_size 100

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

ref class FieldVisualizer : public Form {
private:
    array<array<double>^>^ potential; // Потенциальное поле
    double h = 1.0; // Шаг сетки
    double dielectric_constant = 0.5; // Константа диэлектрика

public:
    FieldVisualizer() {
        this->Text = "Electrostatic Field Visualization with Dielectric";
        this->ClientSize = System::Drawing::Size(800, 800);

        // Инициализация двумерного массива для потенциала
        potential = gcnew array<array<double>^>(grid_size);
        for (int i = 0; i < grid_size; ++i) {
            potential[i] = gcnew array<double>(grid_size);
        }

        InitializePotential();
    }

    void InitializePotential() {
        // Инициализация потенциала
        for (int i = 0; i < grid_size; ++i) {
            for (int j = 0; j < grid_size; ++j) {
                potential[i][j] = 0.0;
            }
        }

        // Устанавливаем проводник в центре
        int center_x = grid_size / 2;
        int center_y = grid_size / 2;
        int rect_width = grid_size / 5;
        int rect_height = grid_size / 10;

        for (int i = center_x - rect_width / 2; i <= center_x + rect_width / 2; ++i) {
            for (int j = center_y - rect_height / 2; j <= center_y + rect_height / 2; ++j) {
                potential[i][j] = 100.0; // Проводник с потенциалом 100 В
            }
        }
    }
    void DrawConductor(Graphics^ g) {
        SolidBrush^ brush = gcnew SolidBrush(Color::Black); // Черный цвет для заливки

        int center_x = grid_size / 2;
        int center_y = grid_size / 2;
        int rect_width = grid_size / 5;
        int rect_height = grid_size / 10;

        float x = center_x - rect_width / 2.0f;
        float y = center_y - rect_height / 2.0f;
        float width = rect_width;
        float height = rect_height;

        // Перевод координат в пиксели
        x *= (this->ClientSize.Width / (float)grid_size);
        y *= (this->ClientSize.Height / (float)grid_size);
        width *= (this->ClientSize.Width / (float)grid_size);
        height *= (this->ClientSize.Height / (float)grid_size);

        // Закрашивание прямоугольника
        g->FillRectangle(brush, x, y, width, height);
    }

   

    bool IsConductor(int i, int j) {
        int center_x = grid_size / 2;
        int center_y = grid_size / 2;
        int rect_width = grid_size / 5;
        int rect_height = grid_size / 10;

        return (i >= center_x - rect_width / 2 && i <= center_x + rect_width / 2 &&
            j >= center_y - rect_height / 2 && j <= center_y + rect_height / 2);
    }

    void SolvePoisson() {
        array<array<double>^>^ newPotential = gcnew array<array<double>^>(grid_size);
        for (int i = 0; i < grid_size; ++i) {
            newPotential[i] = gcnew array<double>(grid_size);
        }

        for (int iter = 0; iter < 1000; ++iter) {
            for (int i = 1; i < grid_size - 1; ++i) {
                for (int j = 1; j < grid_size - 1; ++j) {
                    if (IsConductor(i, j)) continue;

                    bool isDielectric = (j >= grid_size / 2); // Диэлектрик занимает нижнюю половину пространства

                    double factor = isDielectric ? dielectric_constant : 1.0;
                    newPotential[i][j] = 0.25 * factor *
                        (potential[i + 1][j] + potential[i - 1][j] +
                            potential[i][j + 1] + potential[i][j - 1]);
                }
            }

            // Обновляем потенциал
            for (int i = 1; i < grid_size - 1; ++i) {
                for (int j = 1; j < grid_size - 1; ++j) {
                    if (!IsConductor(i, j)) {
                        potential[i][j] = newPotential[i][j];
                    }
                }
            }
        }
    }

    void DrawDielectricBoundary(Graphics^ g) {
        SolidBrush^ brush = gcnew SolidBrush(Color::FromArgb(50, Color::Green));
        g->FillRectangle(brush, 0, this->ClientSize.Height / 2, this->ClientSize.Width, this->ClientSize.Height / 2);
    }

    /*void DrawEquipotentialLines(Graphics^ g) {
        array<double>^ levels = { 10, 30, 50, 70, 90 };
        Pen^ pen = gcnew Pen(Color::FromArgb(128, Color::Blue), 1);

        for each (double level in levels) {
            cliext::vector<PointF> linePoints;

            for (int i = 1; i < grid_size - 1; ++i) {
                for (int j = 1; j < grid_size - 1; ++j) {
                    if ((potential[i][j] - level) * (potential[i + 1][j] - level) < 0 ||
                        (potential[i][j] - level) * (potential[i][j + 1] - level) < 0) {
                        double x = i * (this->ClientSize.Width / grid_size);
                        double y = j * (this->ClientSize.Height / grid_size);
                        linePoints.push_back(PointF((float)x, (float)y));
                    }
                }
            }

            if (linePoints.size() > 1) {
                array<PointF>^ pointsArray = gcnew array<PointF>(linePoints.size());
                for (size_t k = 0; k < linePoints.size(); ++k) {
                    pointsArray[k] = linePoints[k];
                }
                g->DrawLines(pen, pointsArray);
            }
        }
    }*/
    PointF ConvertToPixel(double x, double y) {
        float pixel_x = (float)(x * (this->ClientSize.Width / (double)grid_size));
        float pixel_y = (float)(y * (this->ClientSize.Height / (double)grid_size));
        return PointF(pixel_x, pixel_y);
    }
    cliext::vector<PointF> OrderPointsToFormOval(cliext::vector<PointF> points) {
        if (points.size() < 2) return points;

        cliext::vector<PointF> orderedPoints;
        cliext::vector<bool> visited(points.size(), false);

        // Начинаем с первой точки
        orderedPoints.push_back(points[0]);
        visited[0] = true;

        // Последовательно добавляем ближайшие точки
        while (orderedPoints.size() < points.size()) {
            PointF lastPoint = orderedPoints.back();
            double minDistance = Double::MaxValue;
            size_t nextIndex = -1;

            for (size_t i = 0; i < points.size(); ++i) {
                if (!visited[i]) {
                    double distance = Math::Sqrt(Math::Pow(lastPoint.X - points[i].X, 2) +
                        Math::Pow(lastPoint.Y - points[i].Y, 2));
                    if (distance < minDistance) {
                        minDistance = distance;
                        nextIndex = i;
                    }
                }
            }

            if (nextIndex != -1) {
                orderedPoints.push_back(points[nextIndex]);
                visited[nextIndex] = true;
            }
        }

        // Возвращаем упорядоченный вектор точек
        return orderedPoints;
    }

    void DrawEquipotentialLines(Graphics^ g) {
        array<double>^ levels = { 10, 30, 50, 70, 90 }; // Уровни потенциала
        Pen^ pen = gcnew Pen(Color::FromArgb(128, Color::Blue), 1);

        for each (double level in levels) {
            cliext::vector<PointF> linePoints;

            // Находим точки пересечения уровня
            for (int i = 0; i < grid_size - 1; ++i) {
                for (int j = 0; j < grid_size - 1; ++j) {
                    // Горизонтальное пересечение
                    if ((potential[i][j] - level) * (potential[i + 1][j] - level) < 0) {
                        double t = (level - potential[i][j]) / (potential[i + 1][j] - potential[i][j]);
                        double x = i + t;
                        double y = j;
                        linePoints.push_back(ConvertToPixel(x, y));
                    }
                    // Вертикальное пересечение
                    if ((potential[i][j] - level) * (potential[i][j + 1] - level) < 0) {
                        double t = (level - potential[i][j]) / (potential[i][j + 1] - potential[i][j]);
                        double x = i;
                        double y = j + t;
                        linePoints.push_back(ConvertToPixel(x, y));
                    }
                }
            }

            // Упорядочиваем точки для создания связного контура
            cliext::vector<PointF> orderedPoints = OrderPointsToFormOval(linePoints);

            // Рисуем замкнутую линию
            if (orderedPoints.size() > 1) {
                array<PointF>^ pointsArray = gcnew array<PointF>(orderedPoints.size());
                for (size_t k = 0; k < orderedPoints.size(); ++k) {
                    pointsArray[k] = orderedPoints[k];
                }
                g->DrawPolygon(pen, pointsArray); // Рисуем замкнутую линию
            }
        }
    }

    
    void DrawFieldLines(Graphics^ g) {
        Pen^ pen = gcnew Pen(Color::FromArgb(128, Color::Red), 1);
        int num_lines = 36;
        double step_size = 0.5;

        int center_x = grid_size / 2;
        int center_y = grid_size / 2;
        int rect_width = grid_size / 5;
        int rect_height = grid_size / 10;

        array<PointF>^ startPoints = gcnew array<PointF>(num_lines);
        for (int i = 0; i < num_lines; ++i) {
            double angle = (2 * Math::PI / num_lines) * i;
            double x = center_x + (rect_width / 2) * Math::Cos(angle);
            double y = center_y + (rect_height / 2) * Math::Sin(angle);
            startPoints[i] = PointF((float)(x * (this->ClientSize.Width / grid_size)),
                (float)(y * (this->ClientSize.Height / grid_size)));
        }

        for each (PointF startPoint in startPoints) {
            cliext::vector<PointF> fieldLine;
            PointF current = startPoint;

            for (int steps = 0; steps < 200; ++steps) {
                int i = (int)(current.X / (this->ClientSize.Width / grid_size));
                int j = (int)(current.Y / (this->ClientSize.Height / grid_size));

                if (i < 1 || i >= grid_size - 1 || j < 1 || j >= grid_size - 1) break;

                double Ex = -(potential[i + 1][j] - potential[i - 1][j]) / 2.0;
                double Ey = -(potential[i][j + 1] - potential[i][j - 1]) / 2.0;

                double magnitude = Math::Sqrt(Ex * Ex + Ey * Ey);
                if (magnitude < 1e-6) break;
                Ex /= magnitude;
                Ey /= magnitude;

                current.X += (float)(step_size * Ex * (this->ClientSize.Width / grid_size));
                current.Y += (float)(step_size * Ey * (this->ClientSize.Height / grid_size));

                fieldLine.push_back(current);
            }

            if (fieldLine.size() > 1) {
                array<PointF>^ pointsArray = gcnew array<PointF>(fieldLine.size());
                for (size_t k = 0; k < fieldLine.size(); ++k) {
                    pointsArray[k] = fieldLine[k];
                }
                g->DrawLines(pen, pointsArray);
            }
        }
    }

    virtual void OnPaint(PaintEventArgs^ e) override {
        Graphics^ g = e->Graphics;
        SolvePoisson();
        DrawDielectricBoundary(g);
        DrawEquipotentialLines(g);
        DrawFieldLines(g);
        DrawConductor(g); // Добавляем вызов рисования границы
    }
};

[STAThreadAttribute]
int main() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew FieldVisualizer());
    return 0;
}
