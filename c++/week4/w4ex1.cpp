#include<iostream>
using namespace std;
class flight{
	int flight_no;
	char destination[20];
	float distance,fuel;
	void calculate_fuel(){
		if(distance<=1000){
			fuel=500;
		}else if(distance>1000 && distance<=2000){
			fuel=1100;
		}else{
			fuel=2200;
		}
	}
	public:
		flight(){
			distance=500;
		}
	    void information_entry(){
	    	cout<<"Enter Flight Number:";
	    	cin>>flight_no;
	    	cout<<"Enter Destination:";
	    	cin>>destination;
	    	cout<<"Enter Distance in kms:";
	    	cin>>distance;
	    	calculate_fuel();
		}
		void display_info(){
			cout<<"Flight Number:"<<flight_no<<endl;
			cout<<"Destination:"<<destination<<endl;
			cout<<"Distance:"<<distance<<" kms"<<endl;
			cout<<"Fuel:"<<fuel<<" Liters"<<endl;
		}
};
int main(){
	flight f;
	f.information_entry();
	f.display_info();
	return 0;
}
