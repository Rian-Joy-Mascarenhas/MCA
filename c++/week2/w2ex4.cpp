#include<iostream>
using namespace std;
int main(){
	int f0=0,f1=1,f2,n,i;
	cout<<"Enter the value for n:";
	cin>>n;
	cout<<"Fibonacci Series:";
	for(i=1;i<=n;i++){
		cout<<f0<<" ";
		f2=f0+f1;
		f0=f1;
		f1=f2;
	}
	return 0;	
}
