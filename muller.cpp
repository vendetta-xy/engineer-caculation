#include<iostream>
#include<math.h>
using namespace std;
typedef double function(double);
double e=0.000001;//eΪ�ݲ�

double n_1,n_2,n_3,n_4;//���庯���ĸ�����ϵ��


double sub(double x1,double x2,double x3,function f){
	double a,b,c,p,q,f1,f2,f3;//a,b,cΪ�������Ӧ���κ���������ϵ��,p,qΪ���κ����������
	    f1=f(x1);f2=f(x2);f3=f(x3);
	    a=(f1*(x2-x3)+f2*(x3-x1)+f3*(x1-x2))/((x1-x2)*(x2-x3)*(x1-x3));
	    b=((f1-f2)-(x1*x1-x2*x2)*a)/(x1-x2);
	    c=f1-a*x1*x1-b*x1;
	//����ö��κ��������
	while(1){
	if(b*b-4*a*c<0){
		cout<<"bad choice"<<endl;
	    break;
	}
	else{
		p=-2*c/(b-sqrt(b*b-4*a*c));
		q=-2*c/(b+sqrt(b*b-4*a*c));
	}

	if (fabs(p-x1)<fabs(q-x1)){
			if (fabs(f(p))<e || fabs(x1-p)<e)
				return p;
			else
		        return sub(x2,x3,p,f);
			break;
		}
	else {
		if (fabs(f(q))<e || fabs(x1-q)<e)
			return q;
		else
			return sub(x2,x3,q,f);
		break;
	}
	}
}



int main(){
	double x1,x2,x3;
	//������ԭ�����ĸ�����ϵ��
    cout<<"n_1=";
	cin>>n_1;
	cout<<"n_2=";
	cin>>n_2;
	cout<<"n_3=";
	cin>>n_3;
	cout<<"n_4=";
	cin>>n_4;
	//�����뺯����������
	cout<<"input x1:";
	cin>>x1;
	cout<<"input x2:";
	cin>>x2;
	cout<<"input x3:";
	cin>>x3;

	function f;
    cout<<"zero point is "<<sub(x1,x2,x3,f);
	return 0;
}
double f(double x){
	return n_1*pow(x,3)+n_2*pow(x,2)+n_3*x+n_4;
}

		


