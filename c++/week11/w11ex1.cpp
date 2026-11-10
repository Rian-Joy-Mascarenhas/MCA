#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const char FILE_NAME[] = "employees.dat";

struct Employee {
    int id;
    char name[50];
    char department[30];
    char designation[30];
    double basic;
};

int generateID() {
    ifstream fin(FILE_NAME, ios::binary);
    if (!fin) return 1000;
    Employee e;
    int id = 1000;
    while (fin.read((char*)&e, sizeof(e))) {
        if (e.id > id)
            id = e.id;
    }
    return id + 1;
}

void addEmployee() {
    Employee e;
    e.id = generateID();
    cout << "Enter employee name: ";
    cin >> ws;
    cin.getline(e.name, 50);
    cout << "Enter department: ";
    cin.getline(e.department, 30);
    cout << "Enter designation: ";
    cin.getline(e.designation, 30);
    cout << "Enter basic salary: ";
    cin >> e.basic;
    if (!cin || e.basic < 0) {
        cout << "Invalid input.\n";
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }
    ofstream fout(FILE_NAME, ios::binary | ios::app);
    if (!fout) {
        cout << "File opening error.\n";
        return;
    }
    fout.write((char*)&e, sizeof(e));
    fout.close();
    cout << "Employee added. ID: " << e.id << '\n';
}

void salarySlip() {
    int id;
    cout << "Enter employee ID: ";
    cin >> id;
    ifstream fin(FILE_NAME, ios::binary);
    if (!fin) {
        cout << "Employee file not found.\n";
        return;
    }
    int position = (id - 1000) * sizeof(Employee);
    fin.seekg(position, ios::beg);
    Employee e;
    if (fin.read((char*)&e, sizeof(e)) && e.id == id) {
        fin.close();
        double da = e.basic * 0.10;
        double hra = e.basic * 0.20;
        double gross = e.basic + da + hra;
        double tax = gross * 0.10;
        double net = gross - tax;
        cout << fixed << setprecision(2);
        cout << "\n SALARY SLIP :-\n";
        cout << "Employee ID : " << e.id << '\n';
        cout << "Name        : " << e.name << '\n';
        cout << "Department  : " << e.department << '\n';
        cout << "Designation : " << e.designation << '\n';
        cout << "Basic Salary: Rs. " << e.basic << '\n';
        cout << "DA          : Rs. " << da << '\n';
        cout << "HRA         : Rs. " << hra << '\n';
        cout << "Gross Pay   : Rs. " << gross << '\n';
        cout << "Income Tax  : Rs. " << tax << '\n';
        cout << "Net Pay     : Rs. " << net << '\n';
        cout << "-------------------------\n";
    } else {
        fin.close();
        cout << "Employee not found.\n";
    }
}
int main() {
    int choice;
    do {
        cout << "\n1. Add Employee";
        cout << "\n2. Generate Salary Slip";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:{
				 addEmployee(); break;
			}
            case 2: {
            	salarySlip();
				break;
			}
            case 3: cout << "Exiting.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 3);
    return 0;
}

