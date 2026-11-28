//Write a C++ program to convert the temperature given in Fahrenheit to Celsius 
//and vice versa. ( C = 5/9(F-32) )
#include<iostream>
using namespace std;

int main(){
    float F,C;
    cout<<"Enter Temperature in Fahrenheit:"<<endl;
    cin>>F;
    C=(5.0/9.0)*(F-32);
    cout <<"Celsius:"<<C<<"\n"<<endl;
    cout <<"Enter the Temperature in Celsius:"<<endl;
    cin>>C;
    F=(9.0/5.0)*C+32;
    cout<<"Fahrenheit:"<<F<<endl;
    return 0;
}

	
