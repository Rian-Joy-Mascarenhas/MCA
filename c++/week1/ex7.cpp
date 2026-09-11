#include<iostream>
#include<cmath>
using namespace std;
int main(){
	double p,t,r,n,A,interest;
	cout<<"Enter the Principle investment amount:";
	cin>>p;
	cout<<"Enter the annual interest rate:";
	cin>>r;
	r=r/100.0;
	cout<<"Enter the number of times that interest is compounded per unit:";
	cin>>n;
	cout<<"Enter the Time:";
	cin>>t;
	A=p*pow((1.0+(r/n)),(n*t));
    interest=A-p;
    cout<<"Future value:"<<A<<endl;
    cout<<"Compound Interest:"<<interest<<endl;
    return 0;
}
