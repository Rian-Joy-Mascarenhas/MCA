#include<iostream>
#include<cstring>
using namespace std;
class my_String{
	private:
		char str[50];
	public:
		void input(){
			cout<<"Enter the String:";
			cin>>str;
		}
		bool operator <=(my_String s){
			return strcmp(str,s.str)<=0;
		}
};
int main(){
	my_String s1,s2;
	s1.input();
	s2.input();
	if(s1<=s2)
		cout<<"s1 is lesser than or equal to s2";
	else
		cout<<"s1 is greater than s2";
	return 0;	
}
