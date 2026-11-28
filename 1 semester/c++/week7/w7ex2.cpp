#include<iostream>
#include<string>
using namespace std;
class Employee{
	protected:
		int code;
		string name;
	public:
		void accept(){
			cout<<"Enter the Employee code:";
			cin>>code;
			cout<<"Enter the Employee name:";
			cin>>name;
		}
		void display(){
			cout<<"Employee Code:"<<code<<endl;
			cout<<"Employee Name:"<<name<<endl;
		}
};
class Faculty:public Employee{
	protected:
		string qualification;
		int experience;
	public:
		void accept(){
			Employee::accept();
			cout<<"Enter the Qualification:";
			cin>>qualification;
			cout<<"Enter the experience:";
			cin>>experience;
	}
	void display(){
		Employee::display();
	    cout<<"Qualification:"<<qualification<<endl;
	    cout<<"Experience:"<<experience<<endl;
	}		
};
class NonTeaching:public Employee{
	protected:
		char grade;
	public:
		void accept(){
			Employee::accept();
			cout<<"Enter the Grade:";
			cin>>grade;
		}
		void display(){
			Employee::display();
			cout<<"Grade:"<<grade<<endl;
		}
};
class Permanent:public Faculty{
	protected:
		int basic,allowance;
	public:
		void accept(){
			Faculty::accept();
			cout<<"Enter Basic Pay:";
			cin>>basic;
			cout<<"Enter Academic Allowance:";
			cin>>allowance;
		}
		void display(){
			Faculty::display();
			cout<<"Basic Pay:"<<basic<<endl;
			cout<<"Academic Alowance:"<<allowance<<endl;
		}
};
class Contract:public Faculty{
	protected:
		int probyrs;
	public:
		void accept(){
			Faculty::accept();
			cout<<"Enter Probation Years:";
			cin>>probyrs;
		}
		void display(){
			Faculty::display();
			cout<<"Probation Years:"<<probyrs<<endl;
		}
};
int main(){
	int n,choice;
	cout<<"Enter the number of Instructors:";
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"1.Permanent Faculty\n2.Contract Faculty\nEnter your choice:";
		cin>>choice;
		if(choice==1){
			Permanent p;
			p.accept();
			cout<<"\nPermanent Faculty Details:";
			p.display();
		}else if(choice==2){
			Contract c;
			c.accept();
			cout<<"\nContract Faculty Details:";
			c.display();
		}else{
			cout<<"Invalid choice";
		}
	}
	return 0;
	
}
