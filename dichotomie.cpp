#include<iostream>
#include"math.h"
typedef double func(double);
using namespace std;

double a,b,c,d;//定义为全局变量


int sub(double x1,double x2,double e,func f)//x1,x2为边界，e为容差，f为函数
{
    double x;
	if(fabs(f(x1))<e){
		x=x1;
		return x;
	}
	else if(fabs(f(x2))<e){
		x=x2;
		return x;
	}
	else if(f(x1)*f(x2)>0){
		cout<<"no root";
		return 0;
	}

		for(int i=0;;i++){
		    x=x1+(x2-x1)/2;
			if (f(x)==0 || (x2-x1)/2<e){
				return x;
			}
			else if(f(x)*f(x1)<0){
				x2=x;
				continue;
			}
			else if(f(x)*f(x2)<0){
				x1=x;
				continue;
			}
		}
	
}
int main(){
	double x1,x2,e;//x1,x2为边界，e为容差

	cout<<"please input the board:";
	cin>>x1;
	cin>>x2;
	cout<<"please input the error:";
	cin>>e;
	func f;
	cout<<"please input the coefficient:";//输入三次函数系数
    cin>>a;cin>>b;cin>>c;cin>>d;
	cout<<"x="<<sub(x1,x2,e,f)<<" is the zero of the function in ["<<x1<<","<<x2<<"]"<<endl;
	return 0;
}
double f(double x ){
	return a*x*x*x+b*x*x+c*x+d;
}

	
	




	