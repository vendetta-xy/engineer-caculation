// �����еļ��㷽������ҵ�����㻡����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<cmath>
#include<iostream>
using namespace std;
int n = 1;
const double e = 0.000001;
inline double linelen(double (*f)(double x), double a, double b) {
	return sqrt((f(a) - f(b))*(f(a) - f(b)) + (a - b)*(a - b));
}
double arclen(double(*f)(double x), double a, double b, double e) {
	double result = 0;
	for (int n = 1; abs(a - b) / n < e; n++)
		for (double j = a; (j + (b - a) / n) <= b; j += ((b - a) / n))
			result += linelen(f, j, j + (b - a) / n);
	return result;
}
double f(double x) {
	return x*x;
}

int main()
{
	double a, b;
	cout << "�����뺯���ı߽磺 " << endl;
	cout << "a= ";
	cin >> a;
	cout << "b= ";
	cin >> b;
	double(*fun)(double ) = f;
	
	cout << "f(x)��[" << a << "," << b << "]�Ļ���Ϊ��" << arclen(fun, a, b,e) << endl;
	system("pause");
    return 0;
}

