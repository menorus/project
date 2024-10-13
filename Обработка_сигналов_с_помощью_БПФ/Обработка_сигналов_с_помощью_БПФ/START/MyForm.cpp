#define _USE_MATH_DEFINES

#include "MyForm.h"
#include "FFT.h"


using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int main(array <String^>^ args)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();

	START::MyForm form;
	Application::Run(% form);
}




System::Void START::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->chart1->Series[0]->Points->Clear();
	this->chart1->Series[1]->Points->Clear();
	this->chart1->Series[2]->Points->Clear();
	this->chart1->Series[3]->Points->Clear();
	this->chart2->Series[0]->Points->Clear();
	this->chart3->Series[1]->Points->Clear();
	this->chart3->Series[0]->Points->Clear();
	this->chart4->Series[0]->Points->Clear();
	this->chart4->Series[1]->Points->Clear();

	double A1 = 0, A2 = 0, A3 = 0;
	double f1 = 0, f2 = 0, f3 = 0;
	double F1 = 0, F2 = 0, F3 = 0;
	int  fd = 0, N = 0;
	double процент_шума = 0, шум = 0, Процент_фильтра = 0, фильтр = 0;
	double S1 = 0, S2 = 0, S3 = 0, t = 0;


	A1 = System::Convert::ToDouble(textBox1->Text);
	A2 = System::Convert::ToDouble(textBox6->Text);
	A3 = System::Convert::ToDouble(textBox9->Text);

	f1 = System::Convert::ToDouble(textBox2->Text);
	f2 = System::Convert::ToDouble(textBox5->Text);
	f3 = System::Convert::ToDouble(textBox8->Text);

	F1 = System::Convert::ToDouble(textBox3->Text);
	F2 = System::Convert::ToDouble(textBox4->Text);
	F3 = System::Convert::ToDouble(textBox7->Text);

	fd	=			System::Convert::ToDouble(textBox11->Text);
	N	= (pow(2,	System::Convert::ToDouble(textBox12->Text)));

	процент_шума = System::Convert::ToDouble(textBox10->Text);
	Процент_фильтра = System::Convert::ToDouble(textBox13->Text);

	double S = 0;
	struct cmplx* Data = new struct cmplx[N];
	double* A = new double[N];

	for (int i = 0; i < N; i++)
	{
		t = double(i) / fd;

		S1 = A1 * sin((2 * M_PI * f1 * t) + F1);
		S2 = A2 * sin((2 * M_PI * f2 * t) + F2);
		S3 = A3 * sin((2 * M_PI * f3 * t) + F3);

		this->chart1->Series[1]->Points->AddXY(t, S1);
		this->chart1->Series[2]->Points->AddXY(t, S2);
		this->chart1->Series[3]->Points->AddXY(t, S3);
		S = S1 + S2 + S3;
		this->chart1->Series[0]->Points->AddXY(t, S);
		A[i] = S;
		Data[i].real = S;
		Data[i].image = 0;
	}
	шум = Энергия(Data, N) * процент_шума/100/N;
	for (int i = 0; i < N; i++)
	{
		Data[i].real = Data[i].real + Шум(шум);
		this->chart2->Series[0]->Points->AddXY(i, Data[i].real);
	}

	Быстрое_Фурье_преобразование(Data, N, 1);
	for (int i = 0; i < N; i++)
	{
		S = sqrt(Data[i].real * Data[i].real + Data[i].image * Data[i].image);
		this->chart3->Series[0]->Points->AddXY(i, S);
	}
	фильтр = Энергия(Data, N) * Процент_фильтра / 100;
	Фильтр(Data, N, фильтр);
	for (int i = 0; i < N; i++)
	{
		S = sqrt(Data[i].real * Data[i].real + Data[i].image * Data[i].image);
		this->chart3->Series[1]->Points->AddXY(i, S);
	}

	Быстрое_Фурье_преобразование(Data, N, -1);
	for (int i = 0; i < N; i++)
	{
		t = double(i) / fd;
		this->chart4->Series[0]->Points->AddXY(t, A[i]);
		this->chart4->Series[1]->Points->AddXY(t, Data[i].real);
	}

	


	textBox14->Text = Отклонение(A, Data, N).ToString();
	delete[] Data;
	delete[] A;
	return System::Void();
}
