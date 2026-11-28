//C++ program to convert the time in seconds to hours, minutes and seconds.  
#include<iostream>
using namespace std;
int main(){
	int seconds,hours,minutes,sec;
	cout<<"Enter Seconds:";
	cin>>seconds;
	hours=seconds/3600;
	minutes=(seconds%3600)/60;
	sec=seconds%60;
	cout<<"Hours:"<<hours<<endl;
	cout<<"Minutes:"<<minutes<<endl;
	cout<<"Seconds:"<<sec<<endl;
	return 0;
}
