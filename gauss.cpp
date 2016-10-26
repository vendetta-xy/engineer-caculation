#include<iostream>
using namespace std;
double x[100]; //储存n阶方程的根
void sub_matrix(double a[][100],double b[],int n);
  

int main()
{
	int n;//阶数
	cout<<"输入阶数";
	cin>>n;

	double matrix[100][100]={0},re[100]={0};//matrix用于记录矩阵，re用于记录等号右边的值
	//-----------------------输入矩阵A和B------------------------//
	for(int i=0;i<n;i++){
	    for(int j=0;j<n;j++)
			cin>>matrix[i][j];
		cin>>re[i];
	}

	sub_matrix(matrix,re,n);
	return 0;
}
void sub_matrix(double a[][100],double b[],int n){
  
	//---------------------按列选主元-----------------------//
	for(int i=0;i<n;i++){
		int maxindex;
		maxindex=i;//i固定列
		for(int j=i;j<n-1;j++){
			if (a[j][i]<a[j+1][i])
				maxindex=j+1;
		}
		if(a[maxindex][i]==0){
			cout<<"A奇异，无解";
			return ;
        }

		if (maxindex!=i){
			double temp;
			for(int k=0;k<n;k++){
				temp=a[i][k];
				a[i][k]=a[maxindex][k];
				a[maxindex][k]=temp;
				
			}temp=b[i];
				b[i]=b[maxindex];
				b[maxindex]=temp;
		}
	}
	//--------------------消元计算------------------------//
	for ( i=0;i<n;i++)
		for(int j=i+1;j<n;j++){
			double h=a[j][i];
			for(int t=i;t<n;t++)
			    a[j][t]-=((a[i][t]/a[i][i])*h);
		b[j]-=b[i]/a[i][i]*h;
		}
			
	//--------------------得到上三角阵---------------------//
    
		//--------------------回代----------------------//
    for( i=n-1;i>=0;i--){
		if (i==n-1)
		    x[i]=b[i]/a[i][i];
		else{
			for(int k=i;k+1<n;k++)
			   b[i]-=a[i][k+1]*x[k+1];
			x[i]=b[i]/a[i][i];
		}
	}
	for( i=0;i<n;i++)
		cout<<"x"<<i+1<<"="<<x[i]<<endl;
}