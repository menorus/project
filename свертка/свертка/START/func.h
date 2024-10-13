#define _USE_MATH_DEFINES
#include<math.h>
#include<chrono> 
#include<random> 
#include<vector> 

std::vector<double >генератор(double A1, double A2, double A3, double S1, double S2, double S3, double t01, double t02, double t03, double fd, double N)
{
	std::vector<double>Data;
	Data.resize(N);
	double* T = new double[N];
	double t = 0;
	for (int i = 0; i < N; i++)
	{
		t = double(i) / fd;
		T[i]= A1 * exp(-(((t-t01)*(t - t01))/(2*S1*S1)))
			+ A2 * exp(-(((t - t02)*(t - t02)) /( 2 * S2 * S2)))
			+ A3 * exp(- (((t - t03)*(t - t03)) / (2 * S3 * S3)));
	}
	for (int i = 0; i < N; i++)
	{
		Data[i] = T[i];
	}
	delete[] T;
	return Data;
}
std::vector<double >генератор_импульса(double Ah, double Sh, double fd, double N)
{
	std::vector<double>Data;
	Data.resize(N);
	double* T = new double[N];
	double t = 0;
	for (int i = 0; i < N; i++)
	{
		t = double(i) / fd;
		if (i < N / 2)
		{
			
			T[i] = Ah * exp((-1 *( t * t) / (2 * Sh * Sh)));
			Data[i] = T[i];
		}
		else
		{
			
			T[i] = Ah * exp(-((t-double(N)/fd) * (t - double(N) / fd)) / (2 * Sh * Sh));
			Data[i] = T[i];
		}
	}
	delete[] T;
	return Data;

}
double E(std::vector <double> y, std::vector <double> h, std::vector<double> &x)
{
	double func = 0;
	int N = y.size();
	//std::vector<double> funch1;funch1.resize(N);
	double* D = new double[N];
	double sum1 = 0;

	for (int k = 0; k < N; k++)
	{
		sum1 = 0;
		for (int i = 0; i < N; i++)
		{
			sum1 += x[i] * h[abs(k-i)];
		}
		D[k]=exp(-1 - sum1);
	}

	for (int k = 0; k < N; k++)
	{
		sum1 = 0;
		for (int i = 0; i < N; i++)
		{
			sum1 += h[abs(i - k)] * D[i];
		}
		func += (y[k] - sum1) * (y[k] - sum1);
	}
	delete[] D;
	return func;
}
int MHJ(std::vector <double> Y, std::vector <double> H, std::vector<double>& x)
	{
	int kk = Y.size();
	// kk - количество параметров; x - массив параметров
	double  TAU = 1.e-12f; // Точность вычислений
	int i, j, bs, ps, calc = 0;
	double z, h, k, fi, fb;
	double* b = new double[kk];
	double* y = new double[kk];
	double* p = new double[kk];
	h = 1.;
	k = h;
	for (i = 0; i < kk; i++)  y[i] = p[i] = b[i] = x[i];
	fi = E(Y, H, x);
	ps = 0;   bs = 1;  fb = fi;

	j = 0;
	while (calc<1000)
	{
		calc++; // Счетчик итераций. Можно игнорировать

		x[j] = y[j] + k;
		z = E(Y, H, x);
		if (z >= fi) {
			x[j] = y[j] - k;
			z = E(Y,H,x);
			if (z < fi)   y[j] = x[j];
			else  x[j] = y[j];
		}
		else  y[j] = x[j];
		fi = E(Y, H, x);

		if (j < kk - 1) { j++;  continue; }
		if (fi + 1e-15 >= fb) {
			if (ps == 1 && bs == 0) {
				for (i = 0; i < kk; i++) {
					p[i] = y[i] = x[i] = b[i];
				}
				z = E(Y, H, x);
				bs = 1;   ps = 0;   fi = z;   fb = z;   j = 0;
				continue;
			}
			k /= 2.;
			if (k < TAU) break;
			j = 0;
			continue;
		}

		for (i = 0; i < kk; i++) {
			p[i] = 2 * y[i] - b[i];
			b[i] = y[i];
			x[i] = p[i];

			y[i] = x[i];
		}
		z = E(Y, H, x);
		fb = fi;   ps = 1;   bs = 0;   fi = z;   j = 0;
	} //  end of while(1)

	for (i = 0; i < kk; i++)  x[i] = p[i];
delete[] b;
	delete[] y;
	delete[] p;
	return calc;
}

double otkl(std::vector<double> M, std::vector<double> H)
	{
		int N = M.size();
		double result = 0;
		for (int i = 0; i < N; i++)
		{
			result += (M[i] - H[i]) * (M[i] - H[i]);
		}
		return result;
	}