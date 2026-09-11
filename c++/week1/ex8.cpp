#include<iostream>
using namespace std;
int main(){
	int sem,m1,m2,m3,m4,m5;
	string name,reg_no,yoj,grade;
	float avg,tot;
	cout<<"Enter the Student name:";
	cin>>name;
	cout<<"Enter Student regno:";
	cin>>reg_no;
	cout<<"Enter student year of joining:";
	cin>>yoj;
	cout<<"Enter student sem.no:";
	cin>>sem;
	cout<<"Enter student marks in 5 sub:";
	cin>>m1>>m2>>m3>>m4>>m5;
	tot=m1+m2+m3+m4+m5;
	avg=tot/5.0;
	if(avg>=90)
	 grade="A";
	else if(avg>=80)
	  grade="B";
	else if(avg>=60)
	 grade="C";
	else if(avg>=50)
	 grade="D";
	else if(avg>=40)
	 grade="E";
	else
	 grade="F";
	cout<<"\n\t\tscore card for student:"<<name;
	cout<<"\nRegister no:"<<reg_no;
	cout<<"\t\tSemester:"<<sem;
	cout<<"\tYear:"<<yoj;
	cout<<"\nGrade Assigned:";
	cout<<"\nMarks1:"<<m1;
	cout<<"\nMarks2:"<<m2;
	cout<<"\nMarks3:"<<m3;
	cout<<"\nMarks4:"<<m4;
	cout<<"\nMarks5:"<<m5;
	cout<<"\n\tTotal:"<<tot;
	cout<<"\n\tAverage:"<<avg;
	cout<<"\n\tGrade:"<<grade;
	return 0;
}
