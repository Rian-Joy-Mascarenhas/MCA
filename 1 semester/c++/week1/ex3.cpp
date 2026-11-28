//program to calculate area of circle and triangle
#include<iostream>
using namespace std;
int main(){
float radius,base,height;
cout<<"Enter Radius:";
cin>>radius;
cout<<"Area of Circle:"<<3.14*radius*radius<<"\n"<<endl;
cout<<"Enter Base and Height:";
cin>>base>>height;
cout<<"Area of Triangle:"<<0.5*base*height;
return 0;
}
