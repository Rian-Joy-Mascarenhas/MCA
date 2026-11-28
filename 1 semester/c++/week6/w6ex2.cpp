#include<iostream>
using namespace std;
class Complex{
	private:
		float real,imag;
	public:
		Complex(float r=0,float i=0){
			real=r;
			imag=i;
		}
		void input(){
			cin>>real>>imag;
		}
		Complex operator + (Complex c){
			return Complex(real + c.real, imag + c.imag);
		}
		Complex operator - (Complex c){
			return Complex(real - c.real, imag - c.imag);
		}
		void display(){
			if(imag>=0)
			   cout<<real<<" + "<<imag<< "i" <<endl;
			else
			   cout<<real<<imag<< "i" <<endl;
		}
};
int main(){
	Complex c1,c2,sum,diff;
	cout<<"Enter real and imag part of first complex number:";
	c1.input();
	cout<<"Enter real and imag part of second complex number:";
	c2.input();
	sum=c1+c2;
	diff=c1-c2;
	cout<<"Addition of two complex numbers:";
	sum.display();
	cout<<"Subtraction of two complex numbers:";
	diff.display();
	return 0;	
}
