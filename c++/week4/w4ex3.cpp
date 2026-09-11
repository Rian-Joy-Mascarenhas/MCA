#include<iostream>
#include<string>
using namespace std;
class Player{
	string code,name;
	int matches,runs,notout;
	public:
		Player(){
		code="";name="";
		matches=runs=notout=0;
	}
		void input(){
			cout<<"Enter the player code:";
			cin>>code;
			cin.ignore(100, '\n');
			cout<<"Enter Name:";
			getline(cin, name);
			cout<<"Enter matches:";
			cin>>matches;
			cout<<"Enter Runs scored:";
			cin>>runs;
			cout<<"Enter no. of notout:";
			cin>>notout;
		}
		float average(){
			int innings=matches-notout;
			if(innings==0)
			   return 0;
			return (float)runs/innings;
		}
		static float average(Player p[],int n){
			float total=0;
			int totalinnings=0;
			for(int i=0;i<n;i++){
				total+=p[i].runs;
				totalinnings+=p[i].matches-p[i].notout;
			}
			if(totalinnings==0)
			   return 0;
			return total/totalinnings;
		}
		void display(){
			cout<<code<<"\t"<<name<<"\t"<<matches<<"\t"<<runs<<"\t"<<notout<<"\t"<<average()<<endl;
		}
		int getruns(){
			return runs;
		}	
};
int main(){
	Player p[10],temp;
	int n,ch,index;
	cout<<"Enter number of players(max:10):";
	cin>>n;
	if(n<1 || n>10){
		cout<<"Invalid number of players";
		return 0;
	}
	do{
		cout<<"\n1.Enter details of players";
        cout<<"\n2.Display average runs of a player";
        cout<<"\n3.Average runs of all players";
        cout<<"\n4.Display players sorted by total runs";
        cout<<"\n5.Exit";
        cout<<"\nEnter your choice:";
        cin>>ch;
        switch(ch){
        	case 1:{					
        		for(int i=0;i<n;i++){
        			cout<<"\nPlayer"<<i+1<<endl;
        			p[i].input();
				}
				break;
			}
			case 2:{
				cout<<"Enter player number:";
				cin>>index;
				if(index>=1 && index<=n)
					cout<<"Average runs:"<<p[index-1].average()<<endl;
				else
				    cout<<"Invalid player number";
				break;
			}
			case 3:{
				cout<<"Average runs of all players:"<<Player::average(p,n)<<endl;
				break;
			}
			case 4:{
				for(int i=0;i<n-1;i++){
					for(int j=i+1;j<n;j++){
						if(p[i].getruns()<p[j].getruns()){
							temp=p[i];
							p[i]=p[j];
							p[j]=temp;
						}
					}
				}
				cout<<"\nCode\tName\tMatches\tRuns\tNot Out\tAverage\n";
				for(int i=0;i<n;i++)
				  p[i].display();
				break;
			}
			case 5:{
				cout<<"Exit...";
				break;
			}
			default:
				cout<<"Invalid choice";
		}
		
	}while(ch!=5);
	return 0;
}
