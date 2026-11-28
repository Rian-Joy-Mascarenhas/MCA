#include<iostream>
using namespace std;
void swap(int &a,int &b){
	int c=a;
	a=b;
	b=c;
}
void swap(float &a,float &b){
	float c=a;
	a=b;
	b=c;
}
void swap(char &a,char &b){
	char c=a;
	a=b;
	b=c;
}
int main(){
	int a,b;
	cout<<"Enter 2 integer values to swap:";
	cin>>a>>b;
	swap(a,b);
	cout<<"After Swapping:"<<a<<" "<<b<<endl;
	
	float x,y;
	cout<<"Enter float values to swap:";
	cin>>x>>y;
	swap(x,y);
	cout<<"After Swapping:"<<x<<" "<<y<<endl;
	
	
	char p,q;
	cout<<"Enter character values to swap:";
	cin>>p>>q;
	swap(p,q);
	cout<<"After Swapping:"<<p<<" "<<q<<endl;
}
