#include<iostream>
#include<string>
using namespace std;
class Employee{
	protected:
		int id;
		string name;
		double salary;
	public:
		void inputemp(){
			cout<<"Enter the Employee ID:";
			cin>>id;
			cout<<"Enter the Name:";
			cin>>name;
			cout<<"Enter the Salary:";
			cin>>salary;
		}
		void displayemp(){
			cout<<"Employee ID:"<<id<<"\nEmployee Name:"<<name<<"Salary:"<<salary<<endl;
		}
};
class Education{
	protected:
		string qualification;
	public:
		void acceptedu(){
			cout<<"Enter Qualification:";
			cin>>qualification;
		}
		void displayedu(){
			cout<<"Qualification:"<<qualification<<endl;
		}
};
class Laborer:public Employee{
	public:
		void input(){
			inputemp();
		}
		void display(){
			displayemp();
		}
};
class Scientist:public Employee,public Education{
	private:
		string researcharea;
	public:
		void input(){
			inputemp();
			acceptedu();
			cout<<"Enter Research Area:";
			cin>>researcharea;
		}
		void display(){
			displayemp();
			displayedu();
			cout<<"Research Area:"<<researcharea<<endl;
		}
};
class Manager:public Employee,public Education{
	private:
		string dept;
	public:
		void input(){
			inputemp();
			acceptedu();
			cout<<"Enter Department:";
			cin>>dept;
		}
		void display(){
			displayemp();
			displayedu();
			cout<<"Department:"<<dept<<endl;
		}
};
int main(){
	int ch;
	cout<<"1.Laborer\n2.Scientists\n3.Manager\nEnter your choice:";
	cin>>ch;
	switch(ch){
		case 1:{
		
			Laborer l;
			l.input();
			cout<<"Laborer Details:\n";
			l.display();
			break;
		}
		case 2:{
			Scientist s;
			s.input();
			cout<<"\nScientist Details:\n";
			s.display();
			break;
		}
		case 3:{
			Manager m;
			m.input();
			cout<<"Manager Details:\n";
			m.display();
			break;
		}
		default:
			cout<<"Invalid Choice\n";
	}
	return 0;
}
