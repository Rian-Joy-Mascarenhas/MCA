#include <iostream>
using namespace std;
class Date {
    int day, month, year;
    bool isLeapYear(int y){
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }
    int getMaxDays(int m,int y){
        if (m == 2) {
            return isLeapYear(y) ? 29 : 28;
        }
        if (m == 4||m == 6||m == 9|| m== 11) {
            return 30;
        }
        return 31;
    }
public:
    Date(int d=1,int m=1,int y=2026):day(d),month(m),year(y){}
    void display() const{
        cout << (day < 10 ? "0":"") <<day<<"/"<<(month<10 ? "0" : "")<<month<<"/"<<year<<"\n";
    }
    Date& operator ++ (){
        day++;
        if (day>getMaxDays(month,year)){
            day=1;
            month++;
            if (month>12){
                month=1;
                year++;
            }
        }
        return *this;
    }
    Date operator ++ (int){
        Date temp = *this;
        ++(*this);
        return temp;
    }
};
int main() {
    Date d1(28, 2, 2024);
    cout <<"Initial Date:";
    d1.display();
    ++d1;
    cout <<"After prefix increment (++d1):";
    d1.display();
    d1++;
    cout <<"After postfix increment (d1++):";
    d1.display();
    return 0;
}
