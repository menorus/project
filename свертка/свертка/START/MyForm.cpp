#include "MyForm.h"
#include "func.h"
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

std::vector<double> sv;
std::vector<double> Signal;
std::vector<double >Импульс;
std::vector <double> j;
std::vector <double> j_;
std::vector <double> SingalN;
System::Void START::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->chart1->Series[0]->Points->Clear();
	this->chart2->Series[0]->Points->Clear();
	this->chart3->Series[0]->Points->Clear();
	sv.clear();
	Signal.clear();
	Импульс.clear();
	double A1, A2, A3;
	double S1, S2, S3;
	double t01, t02, t03;
	double Ah, Sh;
	int N = 0; double fd; double t = 0;

	A1 = System::Convert::ToDouble(textBoxA1->Text);
	A2 = System::Convert::ToDouble(textBoxA2->Text);
	A3 = System::Convert::ToDouble(textBoxA3->Text);


	S1 = System::Convert::ToDouble(textBoxS1->Text);
	S2 = System::Convert::ToDouble(textBoxS2->Text);
	S3 = System::Convert::ToDouble(textBoxS3->Text);

	t01 = System::Convert::ToDouble(textBoxt01->Text);
	t02 = System::Convert::ToDouble(textBoxt02->Text);
	t03 = System::Convert::ToDouble(textBoxt03->Text);

	fd = System::Convert::ToDouble(textBoxfd->Text);
	N = System::Convert::ToDouble(textBoxN->Text);
	Ah = System::Convert::ToDouble(textBoxAh->Text);
	Sh = System::Convert::ToDouble(textBoxSh->Text);
	std::vector<double> con;
	std::vector<double> sig;
	Signal = генератор(A1, A2, A3, S1, S2, S3, t01, t02, t03, fd, N);
	sig = генератор(A1, A2, A3, S1, S2, S3, t01, t02, t03, fd, N);
	for (int i = 0; i < N; i++)
	{
		t = double(i) / fd;
		this->chart1->Series[0]->Points->AddXY(t, Signal[i]);
	}
	Импульс = генератор_импульса(Ah, Sh, fd, N);
	for (int i = 0; i < N; i++)
	{
		t = double(i) / fd;
		this->chart2->Series[0]->Points->AddXY(t, Импульс[i]);
	}
	double T;
	double шум;
	std::vector<double> sшум;
	for (int i = 0; i < N; i++)
	{
		T = 0;
		шум = 0;
		for (int k = 0; k < N; k++)
		{
			T += sig[k] * Импульс[abs(i - k)];
		}
		шум = double(rand()) / RAND_MAX;
		sшум.push_back(шум);
		sv.push_back(T);
		con.push_back(T);
	}
	for (int i = 0; i < N; i++)
	{
		t = double(i) / fd;
		this->chart3->Series[0]->Points->AddXY(t, sv[i]+ sшум[i]);
	}


	j.resize(N);
	for (int i = 0; i < N; i++)
	{
		j[i] = double(rand()) / RAND_MAX;
	}
	j_ = j;
	
	timer1->Enabled = true;
	return System::Void();
}

System::Void START::MyForm::timer1_Tick(System::Object^ sender, System::EventArgs^ e)
{
	SingalN.clear();
	int N = 0; double fd; double t = 0;
	fd = System::Convert::ToDouble(textBoxfd->Text);
	N = System::Convert::ToDouble(textBoxN->Text);
	this->chart1->Series[1]->Points->Clear();
	
	MHJ(sv, Импульс, j);

	double sum;
	for (int i = 0; i < N; i++)
	{
		sum = 0;
		for (int k = 0; k < N; k++)
		{
			sum += j[k] * Импульс[abs(i-k)];
		}
		SingalN.push_back(exp(-1 - sum));
	}


	for (int i = 0; i < N; i++)
	{
		t = double(i) / fd;
		this->chart1->Series[1]->Points->AddXY(t, SingalN[i]);
	}

	double error = otkl(SingalN, Signal);
	textBox1->Text = error.ToString();

	if (error < 0.0001 || otkl(j, j_) < 0.000001)
	{
		timer1->Enabled = false;
	}
	j_ = j;
	return System::Void();
}
