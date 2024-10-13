#define _USE_MATH_DEFINES 


#include <vector>
#include "string"
#include"Matrix.h"

// создание сигнала
std::vector<double> Param_A(int n)// произвольные амплитуды от 0 до 1
{ 
	std::vector<double> result;
	for (int i = 0; i < n; i++)
	{
		result.push_back(((double)(rand()) / RAND_MAX)*5);
	}
	return result;
}
std::vector<double> Param_f(int n, int fd) // произвольные частоты (0.5 до 0.75)*fd/8
{
	double k = double(fd) / 8.;
	std::vector<double> result;
	for (int i = 0; i < n; i++)
	{
		result.push_back((((double)(rand())/ RAND_MAX) + 1 ) / 2 * k);
	}
	return result;
}
std::vector<double> Param_fi(int n) // произвольные фазы 0 до 2 * Pi
{
	std::vector<double> result;
	for (int i = 0; i < n; i++)
	{
		result.push_back((double)(rand()) * 2 * M_PI / RAND_MAX);
	}
	return result;
}
std::vector<double> Генератор_Сигнала(int N, int n, int fd) 
{

	std::vector<double> result;

	std::vector<double> param_A = Param_A(n);
	std::vector<double> param_f = Param_f(n, fd);
	std::vector<double> param_fi = Param_fi (n);

	double y = 0; double t = 0;
	for (int i = 0; i < N; i++)
	{
		t = double(i) / fd; y = 0;
		for (int k = 0; k < n; k++)
		{
			y += param_A[k] * sin((2 * M_PI * param_f[k] * t) + param_fi[k]);
		}
		result.push_back(y);
	}
	return result;
}
// создание сигнала




double предсказание(std::vector<double> a_i, std::vector<double> data) // предсказание принимает вектор параметров АР модели и последовательность которую нужно продолждать
{
	double y;
	int N = a_i.size(); int N_data = data.size();
	for (int i = 0; i < N; i++)
	{
		y += - (a_i[i] * data[N_data - 1  - i]);
	}
	return y;
}
double ИКА_(std::vector<double> Data1, std::vector<double> Data2)
{
	std::vector<double> ПО = Data1;
	double result = 0; std::vector<double> a_i; int N_АР = Data1.size(); int N_П = Data2.size();

	// вычисление автокорреляционной матрицы
	std::vector<std::vector<double>> R = Автокорреляционная_матрица(ПО); 

	// вычисление коэфициентов АР модели
	a_i = решение_системы(R, 0.0000001);
	// созжание предсказаной последовательности
	for (int i = 0; i < N_П; i++)
	{
		ПО.push_back(предсказание(a_i , ПО));
	}
	// вычисление дисперсии
	for (int i = 0; i < N_П; i++)
	{
		result += (ПО[i+N_АР] - Data2[i]) * (ПО[i + N_АР] - Data2[i]);
	}
	return log(result/N_П); 
}








