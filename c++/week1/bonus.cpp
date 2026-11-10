//Write a C++ program, which generates all the possible combinations of the 
//given 3-digit number.
#include <iostream>
using namespace std;
int main() {
    int num;
    cout<<"Enter a 3-digit number:";
    cin>>num;
    int a=num/100;
    int b=(num/10)%10;
    int c= num % 10;
    int digits[3] = {a, b, c};

    cout << "All possible combinations are:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (i != j && j != k && i != k) {
                    cout << digits[i] << digits[j] << digits[k] << endl;
                }
            }
        }
    }
    return 0;
}

