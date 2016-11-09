// 工程中的计算方法大作业（计算弧长）.cpp : 定义控制台应用程序的入口点。
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
	cout << "请输入函数的边界： " << endl;
	cout << "a= ";
	cin >> a;
	cout << "b= ";
	cin >> b;
	double(*fun)(double ) = f;
	
	cout << "f(x)在[" << a << "," << b << "]的弧长为：" << arclen(fun, a, b,e) << endl;
	system("pause");
    return 0;
}

