// 工程中的计算方法大作业（计算弧长）.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cmath>
#include<iostream>
#include<time.h>
using namespace std;
int n = 1;
const double e = 0.000001;
inline double linelen(double (*f)(double x), double a, double b) {  //计算小区间的两点之间距离
	return sqrt((f(a) - f(b))*(f(a) - f(b)) + (a - b)*(a - b));
}
double arclen(double(*f)(double x), double a, double b, double e) { //f(x)为求弧长函数，a,b分别为区间的两个端点，e为精度
	double result_last= 0,result_new=linelen(f,a,b);
	for (int n = 2; abs(a - b) / n > e || abs(result_new-result_last)>e; n*=2) {
		result_last=result_new ;
		result_new = 0;
		for (double j = a; (j + (b - a) / n) <= b; j += ((b - a) / n))
			result_new+= linelen(f, j, j + (b - a) / n);
	}
	return result_new;
}
double f(double x) { //由此定义函数
	return x*x*0.5;
}

int main()
{
	double a, b;
	cout << "请输入函数的边界： " << endl;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	double(*fun)(double ) = f;
	int start = clock();
	cout << "f(x)在[" << a << "," << b << "]的弧长为：" << arclen(fun, a, b,e) << endl;
	int end = clock();
	cout << "程序运行时间为：" << end - start << "ms" << endl;
	system("pause");
    return 0;
}

