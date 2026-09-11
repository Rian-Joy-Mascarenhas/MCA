#include<iostream>
#include<cstring>
using namespace std;
bool palindrome(char str[]){
	int i=0,j=strlen(str)-1;
	while(i<j){
		if(str[i]!=str[j])
		  return false;
		i++;
		j--;
	}
	return true;
}
int main(){
	char str[50];
	cout<<"Enter a String:";
	cin>>str;
	if(palindrome(str))
	  cout<<"It is a palindrome";
	else
	  cout<<"Not a palindrome";
	return 0;
}
