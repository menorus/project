#include <ctime>
#include "MyForm.h"
#include "functions.h"
#include <msclr/marshal_cppstd.h>

// ��� �������! ����� � ���� ��������� � ��� ����������, � ��������� �� ����� ���, ������� � ���� ��������� ���� ������
// ���� �� ��������� ��������, � � �� ���� ��� �� ������, ��� ���������� ���� �������, ��� ������, �� ����� � ��� � �������������
// � �������� ����������� ������, ������������ �������� � ������, � ������� ��� ������� ��� ��������, � ����� �� ����� ����������


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


std::vector<double> ������;
System::Void START::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->chart1->Series[0]->Points->Clear();
	this->chart3->Series[2]->Points->Clear();
	this->chart3->Series[1]->Points->Clear();
	this->chart3->Series[0]->Points->Clear();
	this->chart4->Series[0]->Points->Clear();
	this->chart4->Series[1]->Points->Clear();

	int fd = Convert::ToInt32(textBox2->Text); // ��������� ������� �������������
	int n = Convert::ToInt32(textBox1->Text);  // ��������� ���������� ��������
	int N = pow(2,Convert::ToInt32(textBox3->Text)); // ��������� ���������� ��������

	������ = ���������_�������(N, n, fd);
	for (int i = 0; i < N; i++)
	{
		this->chart1->Series[0]->Points->AddXY(i, ������[i]);
	}
	return System::Void();
}


System::Void START::MyForm::button2_Click_1(System::Object^ sender, System::EventArgs^ e) // ��������� �����!
{
	this->chart3->Series[2]->Points->Clear();
	this->chart3->Series[1]->Points->Clear();
	this->chart3->Series[0]->Points->Clear();
	int n = Convert::ToInt32(textBox1->Text); // ���������� ��������
	int trigger = 0; double ����� = 0; std::vector<double> �������;
	int k = 0; if (n == 1) { k = 10; } else { if (n == 2) { k = 7; } else { k = 5; }};
	for (int i = 0; i < n * k; i++) // ����������� �������, ��� ������ ������ �������� � N
	{
		�������.push_back(������[i]);
	}

	int N = �������.size(); // ������ ������� ���������� ������� ������ ������� ����� ���
	double* u = new double[N * N];
	double* v = new double[N * N];
	double* s = new double[N * N];
	double* a = new double[N * N];
	std::vector<double> sigma;
	std::vector<std::vector<double>> R;				// ������� ������������� ���
	R = ������������������_�������(�������);

	sigma = �����������_������������������(R, a, u, v, s, N); // c���������� ����������, ������� ���������� ����� ������ �� ������������� ����������� �����
	if (checkBox1->Checked == true) //  ���� �������� ������� AUTO �� ����� ����� ��������� ��� 5% �� ������������� ������������ �����
	{
		����� = sigma[0] * 0.05;
		textBox4->Text = �����.ToString();
	}
	else // ���� ������� AUTO ��������� �� ������ ����� ������ ������������� � ����������
	{
		����� = Convert::ToDouble(textBox4->Text);
	}

	for (int i = 0; i < N; i++) // ��������� �� ����� ������� ����������� ����� ���������� ������ ������
	{
		if (sigma[i] > �����)
		{
			trigger = i;
		}
		this->chart3->Series[0]->Points->AddXY(i, sigma[i]);
		this->chart3->Series[2]->Points->AddXY(i, sigma[i]);
		this->chart3->Series[1]->Points->AddXY(i, �����);
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
	std::vector<double> ��; // ������������������ �� ������� ����� ������������� ���, �������� ������� ���-������...
	std::vector<double> �; // ����������� ������������������ ��������� �������, �� ������� ����� ����������� ���������� ������ ������������ 
	std::vector<double> ���; // ������ ���[������� ������] ��� n - const
	double ���_i = 0; // ����  ������ ���
	int N = ������.size(); // ����� ���������� �������� ������� (�����)
	int n = Convert::ToInt32(textBox5->Text); // �� ������� ������ ����� ������������� �� ������
	int s = Convert::ToInt32(textBox1->Text); // ���������� �������� ����� �������������� � �������� ����������� ������������� �������
	double trigger = 0; double min = RAND_MAX;

	int k = 0; if (s == 1) { k = 10; } else { if (s == 2) { k = 7; } else { k = 5; }}; // ����������� ������������� ������� ��� ������ ����� N
	for (int i = 0; i < s*k ; i++) // ������� ���� ���������� ������� �������
	{
		if (i < 3) // ������ ������� 0 1 2 �� ���������, ������ ���������� �������� ��� ������� ���������
		{
			���_i = N+N;
			���.push_back(���_i);
		}
		else // ������� �� ������� ������� ������ ������� ���
		{
			��.clear(); �.clear(); // �������� ������ ������������������ 
			for (int j = 0; j < i; j++) // ��������� ������������������ �� ������� ������ ����� ��������� ���� ���������
			{
				��.push_back(������[N / 2 - i + j]); // �� �������� ������� ������� ����� �����
			}
			for (int j = 0; j < n; j++) // ��������� ������������������ ������������ ������� ����� ����������� ��������� ������ ������������ 
			{
				�.push_back(������[N / 2 + j]); // �� �������� ������� ������� ����� ������ N/2, N/2+1, ... , N/2 + n     ��� n ������ � �����������
			}

			���_i = n*���_(��,�); 
			���.push_back(���_i+i*2);
		}
	}

	for (int i = 3; i < s * k; i++) // ����� �������� 
	{

		if (���[i] < min)
		{
			min = ���[i];
			trigger = i;
		}
		this->chart4->Series[0]->Points->AddXY(i, ���[i]);
		this->chart4->Series[1]->Points->AddXY(i, ���[i]);
	}
	textBox9->Text = trigger.ToString();
	return System::Void();
}