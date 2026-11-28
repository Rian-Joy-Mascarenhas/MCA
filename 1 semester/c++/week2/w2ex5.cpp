#include<iostream>
using namespace std;
int main(){
	int start,end,i;
	bool prime=false;
	cout<<"Enter start and end limits:";
	cin>>start>>end;
	for(int i=start;i<=end;i++){
		if (i <= 1) {
            continue; 
        }
        bool prime=true;
        for(int num=2;num*num<=i;num++){
            if(i%num==0){
                prime=false;
                break; 
			}
		}
	 
	if(prime)
		cout<<i<<" ";
   }
    return 0;
}
