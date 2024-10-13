#include <ctime>
#include "MyForm.h"
#include "functions.h"
#include <msclr/marshal_cppstd.h>

// как странно! когда я пишу программу и все получается, я абсолютно не теряю сил, кажется я могу заниматья этим часами
// Если же возникает проблема, и я не знаю как ее решить, это заставляет меня учиться, это тяжело, но делаю я это с удовольствием
// В процессе творческого поиска, штудирования матчасти и теории, я осознаю что начинаю все понимать, я устал но готов продолжить


using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int main(array <String^>^ args)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	srand((unsigned)time(NULL));
	START::MyForm form;
	Application::Run(% form);
}


std::vector<double> Сигнал;
System::Void START::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->chart1->Series[0]->Points->Clear();
	this->chart3->Series[2]->Points->Clear();
	this->chart3->Series[1]->Points->Clear();
	this->chart3->Series[0]->Points->Clear();
	this->chart4->Series[0]->Points->Clear();
	this->chart4->Series[1]->Points->Clear();

	int fd = Convert::ToInt32(textBox2->Text); // считываем частоту дискретизации
	int n = Convert::ToInt32(textBox1->Text);  // считываем количество синусоид
	int N = pow(2,Convert::ToInt32(textBox3->Text)); // считываем количество отсчетов

	Сигнал = Генератор_Сигнала(N, n, fd);
	for (int i = 0; i < N; i++)
	{
		this->chart1->Series[0]->Points->AddXY(i, Сигнал[i]);
	}
	return System::Void();
}


System::Void START::MyForm::button2_Click_1(System::Object^ sender, System::EventArgs^ e) // пороговый метод!
{
	this->chart3->Series[2]->Points->Clear();
	this->chart3->Series[1]->Points->Clear();
	this->chart3->Series[0]->Points->Clear();
	int n = Convert::ToInt32(textBox1->Text); // количество синусоид
	int trigger = 0; double порог = 0; std::vector<double> Выборка;
	int k = 0; if (n == 1) { k = 10; } else { if (n == 2) { k = 7; } else { k = 5; }};
	for (int i = 0; i < n * k; i++) // укореченная выборка, нет смысла делать размером с N
	{
		Выборка.push_back(Сигнал[i]);
	}

	int N = Выборка.size(); // какого размера сварганили выборку такого размера будет АКМ
	double* u = new double[N * N];
	double* v = new double[N * N];
	double* s = new double[N * N];
	double* a = new double[N * N];
	std::vector<double> sigma;
	std::vector<std::vector<double>> R;				// матрица автокореляции АКМ
	R = Автокорреляционная_матрица(Выборка);

	sigma = Сингулярная_последовательность(R, a, u, v, s, N); // cингулярное разложение, функция возвратить толко вектор из упорядоченных сингулярных чисел
	if (checkBox1->Checked == true) //  если включена шалочка AUTO то порог будет выставлен как 5% от максимального сингулярного числа
	{
		порог = sigma[0] * 0.05;
		textBox4->Text = порог.ToString();
	}
	else // если галочка AUTO отключена то порого будет введен пользователем с кравиатуры
	{
		порог = Convert::ToDouble(textBox4->Text);
	}

	for (int i = 0; i < N; i++) // вычисляем на каком отсчете сингулярные числа становятся меньше порога
	{
		if (sigma[i] > порог)
		{
			trigger = i;
		}
		this->chart3->Series[0]->Points->AddXY(i, sigma[i]);
		this->chart3->Series[2]->Points->AddXY(i, sigma[i]);
		this->chart3->Series[1]->Points->AddXY(i, порог);
	}
	delete[] u;
	delete[] v;
	delete[] s;
	delete[] a;
	textBox7->Text = trigger.ToString();
	return System::Void();
}


System::Void START::MyForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->chart4->Series[0]->Points->Clear();
	this->chart4->Series[1]->Points->Clear();
	std::vector<double> АР; // последовательность на которой будет расчитываться АКМ, решаться система Юла-Уокера...
	std::vector<double> П; // контрольная последовательность истинного сигнала, на которой будет вычисляться диссперсия ошибки предсказания 
	std::vector<double> ИКА; // график ИКА[порядок модели] при n - const
	double ИКА_i = 0; // один  отсчет ИКА
	int N = Сигнал.size(); // общее количество отсчетов сигнала (всего)
	int n = Convert::ToInt32(textBox5->Text); // на сколько вперед будет предсказывать АР модель
	int s = Convert::ToInt32(textBox1->Text); // количество синусоид будет использоваться в качестве ограничение максимального порядка
	double trigger = 0; double min = RAND_MAX;

	int k = 0; if (s == 1) { k = 10; } else { if (s == 2) { k = 7; } else { k = 5; }}; // ограничение максимального порядка нет смысла брать N
	for (int i = 0; i < s*k ; i++) // внешний цикл перебираем порядки моделей
	{
		if (i < 3) // модели порядка 0 1 2 не исследуем, просто пропускаем заполняя ИКА большим значением
		{
			ИКА_i = N+N;
			ИКА.push_back(ИКА_i);
		}
		else // начиная со второго порядка честно считаем АКИ
		{
			АР.clear(); П.clear(); // отчищаем старые последовательности 
			for (int j = 0; j < i; j++) // Заполняем последовательность на которой модель будет вычислять свои параметры
			{
				АР.push_back(Сигнал[N / 2 - i + j]); // от середины сигнала берутся точки слева
			}
			for (int j = 0; j < n; j++) // Заполняем последовательность относительно которой будет вычисляться дисперсия ошибки предсказания 
			{
				П.push_back(Сигнал[N / 2 + j]); // от середины сигнала берутся точки справа N/2, N/2+1, ... , N/2 + n     где n вводим с клавиатруры
			}

			ИКА_i = n*ИКА_(АР,П); 
			ИКА.push_back(ИКА_i+i*2);
		}
	}

	for (int i = 3; i < s * k; i++) // поиск минимума 
	{

		if (ИКА[i] < min)
		{
			min = ИКА[i];
			trigger = i;
		}
		this->chart4->Series[0]->Points->AddXY(i, ИКА[i]);
		this->chart4->Series[1]->Points->AddXY(i, ИКА[i]);
	}
	textBox9->Text = trigger.ToString();
	return System::Void();
}