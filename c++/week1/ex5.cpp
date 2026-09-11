//Write a C++ program to convert the distance in mm to cm, inch, feet (1 cm = 
//10mm, 1 inch = 2.5cm, 1 feet = 12 inches).
#include<iostream>
using namespace std;
int main(){
	float mm,cm,inch,feet;
	cout<<"Enter mm:";
	cin>>mm;
	cm=mm/10.0;
	inch=cm/2.5;
	feet=inch/12.0;
	cout<<"CM:"<<cm<<endl;
	cout<<"INCH:"<<inch<<endl;
	cout<<"FEET:"<<feet<<endl;
}
