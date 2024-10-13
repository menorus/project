#include <vector>
#include <cmath>
//m_m - кол-во строк автокоррел€ционной матрицы
//n_n - кол-во столбцов автокоррел€ционной матрицы
//a - автокоррел€ционна€ матрица
//u - лева€ сингул€рна€ матрица
//v - права€ сингул€рна€ матрица
//sigma - матрица с сингул€рными числами
int —ингул€рное_разложение_матрицы(int m_m, int n_n, double* a, double* u, double* v, double* sigma)	// функци€ сингул€рного разложени€, не мо€ лесть опасно
{
	double thr = 0.000001f;
	int n, m, i, j, l, k, lort, iter, in, ll, kk;
	double alfa, betta, hamma, eta, t, cos0, sin0, buf, s, r;
	n = n_n;
	m = m_m;
	for (i = 0; i < n; i++)
	{
		in = i * n;
		for (j = 0; j < n; j++)
			if (i == j) v[in + j] = 1.;
			else v[in + j] = 0.;
	}
	for (i = 0; i < m; i++)
	{
		in = i * n;
		for (j = 0; j < n; j++)
		{
			u[in + j] = a[in + j];
		}
	}

	iter = 0;
	while (1)
	{
		lort = 0;
		iter++;
		for (l = 0; l < n - 1; l++)
			for (k = l + 1; k < n; k++)
			{
				alfa = 0.; betta = 0.; hamma = 0.;
				for (i = 0; i < m; i++)
				{
					in = i * n;
					ll = in + l;
					kk = in + k;
					alfa += u[ll] * u[ll];
					betta += u[kk] * u[kk];
					hamma += u[ll] * u[kk];
				}

				if (sqrt(alfa * betta) < 1.e-10)	continue;
				if (fabs(hamma) / sqrt(alfa * betta) < thr)
					continue;

				lort = 1;
				eta = (betta - alfa) / (2.f * hamma);
				t = (eta / fabs(eta)) /
					(fabs(eta) + (double)sqrt(1.f + eta * eta));
				cos0 = 1.f / (double)sqrt(1.f + t * t);
				sin0 = t * cos0;

				for (i = 0; i < m; i++)
				{
					in = i * n;
					buf = u[in + l] * cos0 - u[in + k] * sin0;
					u[in + k] = u[in + l] * sin0 + u[in + k] * cos0;
					u[in + l] = buf;

					if (i >= n) continue;
					buf = v[in + l] * cos0 - v[in + k] * sin0;
					v[in + k] = v[in + l] * sin0 + v[in + k] * cos0;
					v[in + l] = buf;
				}
			}

		if (!lort) break;
	}

	for (i = 0; i < n; i++)
	{
		s = 0.;
		for (j = 0; j < m; j++)	s += u[j * n + i] * u[j * n + i];
		s = (double)sqrt(s);
		sigma[i] = s;
		if (s < 1.e-10)	continue;
		for (j = 0; j < m; j++)	u[j * n + i] = u[j * n + i] / s;
	}
	for (i = 0; i < n - 1; i++)
		for (j = i; j < n; j++)
			if (sigma[i] < sigma[j])
			{
				r = sigma[i]; sigma[i] = sigma[j]; sigma[j] = r;
				for (k = 0; k < m; k++)
				{
					r = u[i + k * n]; u[i + k * n] = u[j + k * n]; u[j + k * n] = r;
				}
				for (k = 0; k < n; k++)
				{
					r = v[i + k * n]; v[i + k * n] = v[j + k * n]; v[j + k * n] = r;
				}
			}

	return iter;
}
std::vector<std::vector<double>> јвтокоррел€ционна€_матрица(std::vector<double> X)
{
	std::vector<std::vector<double>> R; R.resize(X.size());
	std::vector<double> rxx; rxx.resize(X.size());
	for (int i = 0; i < X.size(); i++)
	{
		for (int j = 0; j < X.size()-i; j++)
		{
			rxx[i] += X[j]*X[j+i];
		}
		rxx[i] = rxx[i] / X.size() - i;
	}

	for (int i = 0; i < X.size(); i++)
	{
		R[i].resize(X.size());
		for (int j = 0; j < X.size(); j++)
		{
			R[i][j] = rxx[abs(i - j)];
		}
	}
	return R;
}
std::vector<double> —ингул€рна€_последовательность(std::vector<std::vector<double>> A, double* a, double* u, double* v, double* s, int q)
{
	std::vector<double> result;
	for (int i = 0; i < q; i++)
	{
		for (int j = 0; j < q; j++)
		{
			a[i * q + j] = A[i][j];
		}
	}
	—ингул€рное_разложение_матрицы(q, q, a, u, v, s);
	for (int i = 0; i < q; i ++)
	{
		result.push_back(s[i]);
	}
	return result;
}
std::vector<double> решение_системы(std::vector<std::vector<double>> R, double err)
{
	std::vector<double> result;
	int nn = R.size(); int ny = nn;
	double* a = new double[nn * nn];
	double* b = new double[nn];
	double* x = new double[nn];
	for (int i = 0; i < nn; i++)
	{
		for (int j = 0; j < nn; j++)
		{
			a[i * nn + j] = R[i][j];
		}
	}
	for (int i = 0; i < nn; i++)
	{
		b[i] = 0;
		x[i] = 0;
	}
	b[0] = 1;

	// nn - количество неизвестных; ny - количество уравнений
	double eps = err;
	//float s;
	int i, j, k;
	double s1, s2, fa1, t;
	double* x1;

	x1 = new double[nn];

	x[0] = 1;
	for (i = 1; i < nn; i++) x[i] = 0.f;

	s1 = s2 = 1.f;
	while (s1 > eps * s2)
	{

		for (i = 0; i < nn; i++) x1[i] = x[i];

		for (i = 0; i < ny; i++)
		{
			s1 = 0.0;
			s2 = 0.0;
			for (j = 0; j < nn; j++)
			{
				fa1 = a[i * nn + j];
				s1 += fa1 * x[j];
				s2 += fa1 * fa1;
			}
			t = (b[i] - s1) / s2;
			for (k = 1; k < nn; k++) x[k] += a[i * nn + k] * t;
		}

		s1 = 0.0;
		s2 = 0.0;
		for (i = 0; i < nn; i++)
		{
			s1 += (x[i] - x1[i]) * (x[i] - x1[i]);
			s2 += x[i] * x[i];
		}
		s1 = (double)sqrt(s1);
		s2 = (double)sqrt(s2);
	}
	for (int i = 0; i < nn; i++)
	{
		result.push_back(x[i]);
	}
	delete[] x1;
	delete[] a;
	delete[] b;
	delete[] x;
	return result;
}
