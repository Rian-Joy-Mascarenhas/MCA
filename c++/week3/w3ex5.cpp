#include<iostream>
using namespace std;
struct emp{
	int empno;
	string empname;
	float basic,da,it,gross,net_sal;
};
void read(emp &e){
	cout<<"Enter Employee number:";
	cin>>e.empno;
	cout<<"Enter Employee name:";
	cin>>e.empname;
	cout<<"Enter Basic Salary:";
	cin>>e.basic;
}
void calculate(emp &e){
	e.da=0.12*e.basic;
	e.gross=e.basic+e.da;
	e.it=0.18*e.gross;
	e.net_sal=e.gross-e.it;
}
void display(emp &e){
	cout<<"\n\nEmployee Number:"<<e.empno;
	cout<<"\nEmployee Name:"<<e.empname;
	cout<<"\nBasic:"<<e.basic;
	cout<<"\nDA:"<<e.da;
	cout<<"\nGross Salary:"<<e.gross;
	cout<<"\nIT:"<<e.it;
	cout<<"\nNet Salary:"<<e.net_sal;
}
int main(){
	int n;
	cout<<"Enter the number of employees:";
	cin>>n;
	emp employees[n];
	for(int i = 0; i < n; i++) {
        cout << "\nEnter details for employee "<<(i+1)<<":\n";
        read(employees[i]);
        calculate(employees[i]);
    }
    cout<<"\n\nEmployee Details:";
    for(int i = 0; i < n; i++) {
        display(employees[i]);
    }
    return 0;
}
