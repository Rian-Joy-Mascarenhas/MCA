#include <iostream>
using namespace std;
class shape{
protected:
    double a,b;
public:
    void get_data(){
        cin >>a>>b;
    }
    virtual void display_area() const{
        cout << "Area cannot be calculated!"<< endl;
    }
    virtual ~shape() = default;
};
class triangle:public shape{
public:
    void display_area() const override{
        cout << "Area of Triangle: "<<0.5*a*b<< endl;
    }
};
class rectangle:public shape{
public:
    void display_area() const override {
        cout << "Area of Rectangle: "<<a*b<<endl;
    }
};
int main(){
    int ch;
    cout<<"1. Triangle\n2. Rectangle\n";
    cout<<"Enter your choice: ";
    cin>>ch;
    shape* s = nullptr;
    triangle t;
    rectangle r;
    switch (ch){
        case 1:
            s=&t;
            cout<<"Enter base and height of triangle: ";
            break;

        case 2:
            s = &r;
            cout <<"Enter length and breadth of rectangle: ";
            break;
        default:
            cout<<"Invalid choice!"<<endl;
            return 0;
    }
    s->get_data();
    s->display_area();
    return 0;
}

