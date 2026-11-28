#include<iostream>
using namespace std;
class Student{
	protected:
		int rollno;
		string name;
	public:
		void input(){
			cout<<"Enter Roll No:";
			cin>>rollno;
			cout<<"Enter Name:";
			cin>>name;
		}
		void display(){
			cout<<"Rollno:"<<rollno<<endl;
			cout<<"Name:"<<name<<endl;
		}
};
class Exam:virtual public Student{
	protected:
		float marks;
	public:
		void inputexam(){
			cout<<"Enter the Marks:";
			cin>>marks;
		}
		void displayexam(){
			cout<<"Marks:"<<marks;
		}
};
class Sports:virtual public Student{
	protected:
		float spmarks;
	public:
		void inputsports(){
			cout<<"Enter the Sports Marks:";
			cin>>spmarks;
		}
		void displaysports(){
			cout<<"Sports Marks:"<<spmarks<<endl;
		
		}
};
class Result:public Exam,public Sports{
	float total;
	public:
		void input(){
			Student::input();
			inputexam();
			inputsports();
			
		}
		void display(){
			total=marks+spmarks;
			cout<<"\nResult:\n";
			Student::display();
			displayexam();
			displaysports();
			cout<<"Total Marks:"<<total<<endl;		
		}
};
int main(){
	Result r;
	r.input();
	r.display();
	return 0;
}
