// �����еļ��㷽������ҵ�����㻡����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<cmath>
#include<iostream>
#include<time.h>
using namespace std;
int n = 1;
const double e = 0.000001;
inline double linelen(double (*f)(double x), double a, double b) {  //����С���������֮�����
	return sqrt((f(a) - f(b))*(f(a) - f(b)) + (a - b)*(a - b));
}
double arclen(double(*f)(double x), double a, double b, double e) { //f(x)Ϊ�󻡳�������a,b�ֱ�Ϊ����������˵㣬eΪ����
	double result_last= 0,result_new=linelen(f,a,b);
	for (int n = 2; abs(a - b) / n > e || abs(result_new-result_last)>e; n*=2) {
		result_last=result_new ;
		result_new = 0;
		for (double j = a; (j + (b - a) / n) <= b; j += ((b - a) / n))
			result_new+= linelen(f, j, j + (b - a) / n);
	}
	return result_new;
}
double f(double x) { //�ɴ˶��庯��
	return x*x*0.5;
}

int main()
{
	double a, b;
	cout << "�����뺯���ı߽磺 " << endl;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	double(*fun)(double ) = f;
	int start = clock();
	cout << "f(x)��[" << a << "," << b << "]�Ļ���Ϊ��" << arclen(fun, a, b,e) << endl;
	int end = clock();
	cout << "��������ʱ��Ϊ��" << end - start << "ms" << endl;
	system("pause");
    return 0;
}

