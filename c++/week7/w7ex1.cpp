#include<iostream>
#include<string>
using namespace std;
class person{
	protected:
	string id;
	string name;
	public:
		void accept(){
			cout<<"Enter the ID:";
			cin>>id;
			cout<<"Enter the name:";
			cin>>name;
		}
		void display() const{
			cout<<"ID:"<<id<<"\nName:"<<name<<endl;
		}
};
class teaching : public person{
	protected:
		string subject;
	public:
		void accept(){
			person::accept();
			cout<<"Enter the subject:";
			cin>>subject;
		}
		void display() const{
			person::display();
			cout<<"Subject: "<<subject<<endl;
		}
};
class nonteaching : public person{
	protected:
		string dept;
	public:
		void accept(){
			person::accept();
			cout<<"Enter department:";
			cin>>dept;
		}
		void display()const {
			person::display();
			cout<<"Department:"<<dept<<endl;
		}
};
class instructor : public person{
	public:
		void accept(){
			cout<<"\nEnter instructor details\n";
			person::accept();
		}
		void display() const{
		cout<<"\nInstructor details\n";
		person::display();
		}
};
int main(){
	int n;
	cout<<"Enter the number of instructors:";
	cin>>n;
	instructor* instructors= new instructor[n];
	for (int i = 0;i<n;i++){
        cout<<"\nInstructor"<<(i+1)<<":";
        instructors[i].accept();
    }
    cout<<"\nInstructor Details";
    for (int i=0;i<n;i++){
        instructors[i].display();
    }
    delete[] instructors;
    return 0;
}

