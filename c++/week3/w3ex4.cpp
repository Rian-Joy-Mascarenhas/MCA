#include<iostream>
using namespace std;
int inverse(int n){
	int rev=0;
	while(n>0){
		rev=rev*10+n%10;
		n=n/10;
	}
	return rev;
}
int twice(int n){
	return n*2;
}
int main(){
	int n;
	cout<<"Enter a number:";
	cin>>n;
	int inv=inverse(n);
	int twiceinverse=twice(inv);
	cout<<"Reverse:"<<inv<<endl;
	cout<<"Twice:"<<twiceinverse;
	return 0;
}
