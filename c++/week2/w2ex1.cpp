#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"Enter number of lines:";
	cin>>n;
	for(int i=n;i>=1;i--){
		for(int j=1;j<=i;j++){
			cout<<"*"<<"  ";
		}
		cout<<"\n";
	}
	for(int i=n;i>=1;i--){
		char ch='A';
		for(int j=1;j<=i;j++){
			cout<<ch<<"  ";
			ch++;
		}
		cout<<endl;
	}
	int num=1;
	cout<<endl;
	cout<<"Floyd's triangle"<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cout<<num<<" ";
			num++;
		}
		cout<<endl;
	}
	return 0;
}
