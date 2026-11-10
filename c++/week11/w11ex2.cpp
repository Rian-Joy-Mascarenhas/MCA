#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
const char FILE_NAME[] = "items.dat";
struct Item {
    int code;
    char name[50];
    double price;
    int quantity;
};
int generateCode() {
    ifstream fin(FILE_NAME, ios::binary);
    Item item;
    int code = 2000;
    while (fin.read((char*)&item, sizeof(item))) {
        if (item.code > code)
            code = item.code;
    }
    return code + 1;
}
void addItem() {
    Item item;
    item.code = generateCode();
    cout << "Enter item name: ";
    cin >> ws;
    cin.getline(item.name, 50);
    cout << "Enter unit price: ";
    cin >> item.price;
    cout << "Enter quantity: ";
    cin >> item.quantity;
    if (!cin || item.price < 0 || item.quantity < 0) {
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
    fout.write((char*)&item, sizeof(item));
    fout.close();
    cout << "Item added successfully.\n";
    cout << "Generated item code: " << item.code << '\n';
}
void modifyItem() {
    int code;
    cout << "Enter item code to modify: ";
    cin >> code;
    fstream file(FILE_NAME,
                 ios::binary | ios::in | ios::out);
    if (!file) {
        cout << "Item file not found.\n";
        return;
    }
    Item item;
      while (true) {
        streampos pos = file.tellg();
        if (!file.read((char*)&item, sizeof(item)))
            break;
        if (item.code == code) {
            cout << "Current name: " << item.name << '\n';
            cout << "Current price: " << item.price << '\n';
            cout << "Current quantity: "
                 << item.quantity << '\n';
            cout << "Enter new item name: ";
            cin >> ws;
            cin.getline(item.name, 50);
            cout << "Enter new unit price: ";
            cin >> item.price;
            cout << "Enter new quantity: ";
            cin >> item.quantity;
            if (!cin || item.price < 0 ||
                item.quantity < 0) {
                cout << "Invalid input.\n";
                cin.clear();
                file.close();
                return;
            }
            file.clear();
            file.seekp(pos);
            file.write((char*)&item, sizeof(item));
            file.close();
            cout << "Item modified successfully.\n";
            return;
        }
    }
    file.close();
    cout << "Item code not found.\n";
}
int main() {
    int choice;
    do {
        cout << "\n1. Add New Item";
        cout << "\n2. Modify Existing Item";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: addItem(); break;
            case 2: modifyItem(); break;
            case 3: cout << "Exiting.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 3);
    return 0;
}
