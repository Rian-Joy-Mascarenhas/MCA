//exchange 2 variables without using temporary variable
#include<iostream>
using namespace std;
int main(){
	int a;
	int b;
	cout<<"Enter the value for a and b:";
	cin>>a>>b;
	a=a+b;
	b=a-b;
	a=a-b;
	cout<<"After Swapping:";
	cout<<"A:"<<a;
	cout<<"    B:"<<b;
}
