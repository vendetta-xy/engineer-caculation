#include<iostream>
using namespace std;
double x[100]; //����n�׷��̵ĸ�
void sub_matrix(double a[][100],double b[],int n);
  

int main()
{
	int n;//����
	cout<<"�������";
	cin>>n;

	double matrix[100][100]={0},re[100]={0};//matrix���ڼ�¼����re���ڼ�¼�Ⱥ��ұߵ�ֵ
	//-----------------------�������A��B------------------------//
	for(int i=0;i<n;i++){
	    for(int j=0;j<n;j++)
			cin>>matrix[i][j];
		cin>>re[i];
	}

	sub_matrix(matrix,re,n);
	return 0;
}
void sub_matrix(double a[][100],double b[],int n){
  
	//---------------------����ѡ��Ԫ-----------------------//
	for(int i=0;i<n;i++){
		int maxindex;
		maxindex=i;//i�̶���
		for(int j=i;j<n-1;j++){
			if (a[j][i]<a[j+1][i])
				maxindex=j+1;
		}
		if(a[maxindex][i]==0){
			cout<<"A���죬�޽�";
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
	//--------------------��Ԫ����------------------------//
	for ( i=0;i<n;i++)
		for(int j=i+1;j<n;j++){
			double h=a[j][i];
			for(int t=i;t<n;t++)
			    a[j][t]-=((a[i][t]/a[i][i])*h);
		b[j]-=b[i]/a[i][i]*h;
		}
			
	//--------------------�õ���������---------------------//
    
		//--------------------�ش�----------------------//
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