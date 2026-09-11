#include<iostream>
using namespace std;
class Complex{
	float real,imag;
	public:
		Complex(float r=0,float i=0){
			real=r;
			imag=i;
		}
		Complex add(int s1, const Complex& s2){
			return Complex(s1+s2.real,s2.imag);
		}
		Complex add(const Complex& s1,const Complex& s2){
			return Complex(s1.real + s2.real,
			              s1.imag + s2.imag);
		}
		
		void display() const{
			if(imag>=0)
			  cout<<real<<"+"<<imag<<"i";
			else
			  cout<<real<<"-"<<-imag<<"i";
		}
		void input(){
			cin>>real>>imag;
		}
};
int main(){
	int n;
	Complex c1,c2,result;
	cout<<"Enter an integer:";
	cin>>n;
	cout<<"Enter real and imag part of complex 1:";
	c1.input();
	cout<<"Enter real and imag part of complex 2:";
	c2.input();
	result=result.add(n,c1);
	cout<<"\nInteger + Complex =";
	result.display();
	result=result.add(c1,c2);
	cout<<"\nComplex + Complex =";
	result.display();
	return 0;
}
