#include<iostream>
#include"math.h"
using namespace std;
int main()
{
	float a,b,c,x1,x2;

	cout<<"get the a,b,c of equation:";
	cin>>a;
	cin>>b;
	cin>>c;
    if(b*b<4*a*c){
		cout<<"the equation is unslovable"<<endl;
	}
	else if(b*b==4*a*c){
		x1=-b/2*a;
	    cout<<x1;
	}
	else{
    x1=-2*a*c/(b-sqrt(b*b-4*a*c));
	x2=-2*a*c/(b+sqrt(b*b-4*a*c));
	cout<<x1<<endl;
	cout<<x2<<endl;
	}
	return 0;
}
 
