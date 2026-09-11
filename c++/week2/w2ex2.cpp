#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"Enter the number:";
	cin>>n;
	int i;
	bool iscube=false;
	for(i=1;i*i*i<=n;i++){
		if(i*i*i==n){
			iscube=true;
			break;
		}
	}
	if(iscube){
		cout<<n<<" is a perfect cube,cube root is "<<i;
	}else{
		cout<,n<<"is not a perfect cube."
	}
	return 0;
}
