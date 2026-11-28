#include<iostream>
#include<string>
using namespace std;
class Employee{
	string name;
	int code;
	public:
		void input(){
			cout<<"Enter Employee Name:";
			cin>>name;
			cout<<"Enter Employee Code:";
			cin>>code;
		}
		void display(){
			cout<<"Emoployee Name:"<<name<<endl;
			cout<<"Employee Code:"<<code<<endl;
		}
};
class Account:virtual public Employee{
	protected:
	int pay;
	public:
		void inputacc(){
			cout<<"Enter Pay:";
			cin>>pay;
		}
		void displayacc(){
			cout<<"Pay:"<<pay;
		}
};
class Admin:virtual public Employee{
	protected:
	int experience;
	public:
		void inputadmin(){
			cout<<"Enter Experience:";
			cin>>experience;
	}
	void displayadmin(){
		cout<<"Experience:"<<experience<<endl;
	}
};
class Master:public Account,public Admin{
	public:
		void input(){
			Employee::input();
			inputacc();
			inputadmin();
		}
		void update(){
			cout<<"Enter Updated pay:";
			cin>>pay;
			cout<<"Enter updated experience:";
			cin>>experience;
		}
		void display(){
			cout<<"\nMaster Details\n";
			Employee::display();
			displayacc();
			displayadmin();
		}
};
int main(){
	Master m;
	cout<<"\nEnter Employee Details\n";
	m.input();
	cout<<"\nInitial Details\n";
	m.display();
	cout<<"\nUpdate Details\n";
	m.update();
	cout<<"\nUpdated Details\n";
	m.display();
	return 0;
}
