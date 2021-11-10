// Лабораторна робота No 5.4
#include <iostream>
#include <cmath>
using namespace std;
double P0(const double N)
{
	double P = 1;
	for (int k = N; k <= 25; k++)
		P *= sqrt(1 + (N / k));
	return P;
}
double P1(const double N, const double k)
{
	if (k > 25)
		return 1;
	else
		return sqrt(1 + (N / k)) * P1(N, k + 1);
}
double P2(const double N, const int k)
{
	if (k < N)
		return 1;
	else
		return sqrt(1 + (N / k)) * P2(N, k - 1);
}
double P3(const double N, const int k, double t)
{
	t *= sqrt(1 + (N / k));
	if (k >= 25)
		return t;
	else
		return P3(N, k + 1, t);
}
double P4(const double N, const int k, double t)
{
	t *= sqrt(1 + (N / k));
	if (k <= N)
		return t;
	else
		return P4(N, k - 1, t);
}

int main()
{
	int k, N;
	cout << "N = "; cin >> N;
	cout << "(iter) P0 = " << P0(N) << endl;
	cout << "(rec up ++) P1 = " << P1(N, N) << endl;
	cout << "(rec up --) P2 = " << P2(N, 25) << endl;
	cout << "(rec down ++) P3 = " << P3(N, N, 1) << endl;
	cout << "(rec down --) P4 = " << P4(N, 25, 1) << endl;
	return 0;
}