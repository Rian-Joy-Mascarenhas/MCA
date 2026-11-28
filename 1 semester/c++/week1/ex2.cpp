//program to find smallest of 3 numbers
#include<iostream>
using namespace std;
int main(){
	int a,b,c;
	cout<<"Enter the values for a,b and c:";
	cin>>a>>b>>c;
	if(a<=b && a<=c)
		cout<<"A is smallest";
	else if(b<=a && b<=c)
		cout<<"B is smallest";
	else
		cout<<"C is smallest";
	
	return 0;
	}

