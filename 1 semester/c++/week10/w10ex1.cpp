#include<iostream>
#include<fstream>
using namespace std;
int main(){
	string filename="text.txt";
	string text;
	int ch;
	ofstream fout(filename);
	cout<<"Enter Text:";
	getline(cin,text);
	fout<<text;
	fout.close();
	cout<<"1.Case Convert\n2.Display content\n3.Display a count\n4.exit"<<endl;
	while(true){
		cout<<"\nEnter your Choice:";
		cin>>ch;
		switch(ch){
			case 1:{
				ifstream fin(filename);
				char c;
				string str;
				while(fin.get(c)){
					if(isupper(c))
						c=tolower(c);
					else if(islower(c))
						c=toupper(c);
					str+=c;
				}
				fin.close();
				ofstream fout(filename);
				fout<<str;
				fout.close();
				cout<<"Converted"<<endl;
				break;
			}

			case 2:{
				ifstream fin(filename);
				char c;
				cout<<"Content"<<endl;
				while(fin.get(c))
					cout<<c;
				fin.close();
				break;
			}

			case 3:{
				ifstream fin(filename);
				char c;
				int count=0;
				while(fin.get(c)){
					if(c=='a')
						count++;
				}
				fin.close();
				cout<<"Character a is used "<<count<<" times"<<endl;
				break;
			}

			case 4:
				exit(0);

			default:
				cout<<"invalid choice"<<endl;
		}
	}
	return 0;
}
