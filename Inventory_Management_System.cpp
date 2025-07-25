
// Inventory Management System - Final Version
// Author: Sai Bhaskar

#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <string>
#include <windows.h>
using namespace std;

struct node {
    int ID;
    string proName;
    double prePrice;
    int quantity;
    node* next;
};

node* head = nullptr;

void loading();
void beg();
void end();
int display();
string check(int);
void saveOnFile();
void OldProducts();
void modify();
void delPro();
int search(int);
void searching();
void buy();
void showbill();

int main() {
    system("color 0a");
    loading();

    string password;
    char ch;
    cout << "\n\n\t\tEnter Password: ";
    while ((ch = _getch()) != 13) {
        password += ch;
        cout << '*';
    }

    if (password != "pak123") {
        cout << "\n\nWrong password. Exiting...";
        return 0;
    }

    int choice;
    bool firstEntry = true;

    while (true) {
        system("cls");
        cout << "\n\t*********** INVENTORY MANAGEMENT SYSTEM ***********\n";
        cout << "\t1. Add New Product\n";
        cout << "\t2. Display Products\n";
        cout << "\t3. Modify Product\n";
        cout << "\t4. Delete Product\n";
        cout << "\t5. Buy Product\n";
        cout << "\t6. Search Product\n";
        cout << "\t7. Show Bill Records\n";
        cout << "\t0. Exit\n";
        cout << "\n\tEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (head == nullptr)
                beg();
            else
                end();
                break;
            case 2:
                int sub;
                do {
                    system("cls");
                    cout << "\n\t1. Show Old Products\n";
                    cout << "\t2. Save Current Products\n";
                    cout << "\t3. Display Existing Products\n";
                    cout << "\t4. Back to Main Menu\n";
                    cout << "\n\tEnter choice: ";
                    cin >> sub;
                    if (sub == 1) { system("cls"); OldProducts(); system("pause"); }
                    else if (sub == 2) { system("cls"); saveOnFile(); system("pause"); }
                    else if (sub == 3) { system("cls"); display(); system("pause"); }
                } while (sub != 4);
                break;
            case 3:
                modify();
                break;
            case 4:
                delPro();
                break;
            case 5:
                buy();
                break;
            case 6:
                searching();
                break;
            case 7:
                showbill();
                break;
            case 0:
                cout << "\n\nThank you for using the system. Goodbye!\n";
                return 0;
            default:
                cout << "\nInvalid choice. Try again!";
        }
        system("pause");
    }
    return 0;
}

void loading() {
    cout << "\n\tLoading... Please Wait!\n\t";
    for (int i = 0; i < 20; i++) {
        cout << (char)219;
        Sleep(100);
    }
    system("cls");
}

void beg() {
    node* t = new node;
    cout << "\nEnter Product ID: "; cin >> t->ID;
    cout << "Enter Product Name: "; cin >> t->proName;
    cout << "Enter Product Price: "; cin >> t->prePrice;
    cout << "Enter Quantity: "; cin >> t->quantity;
    t->next = head;
    head = t;
    cout << "\nProduct added successfully!\n";
}

void end() {
    node* t = new node;
    cout << "\nEnter Product ID: "; cin >> t->ID;
    cout << "Enter Product Name: "; cin >> t->proName;
    cout << "Enter Product Price: "; cin >> t->prePrice;
    cout << "Enter Quantity: "; cin >> t->quantity;
    t->next = nullptr;

    node* p = head;
    while (p->next != nullptr) p = p->next;
    p->next = t;
    cout << "\nProduct added successfully!\n";
}

int display() {
    node* p = head;
    int count = 0;
    cout << "\nID\tName\t\tPrice\tQuantity\n";
    cout << "-------------------------------------------\n";
    while (p != nullptr) {
        cout << p->ID << "\t" << p->proName << "\t\t" << p->prePrice << "\t" << check(p->quantity) << endl;
        p = p->next;
        count++;
    }
    cout << "\nTotal Products: " << count << endl;
    return count;
}

string check(int q) {
    return (q <= 0) ? "Out of stock" : to_string(q);
}

void saveOnFile() {
    ofstream out("Products_Record.txt");
    node* p = head;
    out << "ID\tName\tPrice\tQuantity\n";
    while (p != nullptr) {
        out << p->ID << "\t" << p->proName << "\t" << p->prePrice << "\t" << p->quantity << endl;
        p = p->next;
    }
    out.close();
    cout << "\nProducts saved to file successfully.\n";
}

void OldProducts() {
    ifstream in("Products_Record.txt");
    string line;
    while (getline(in, line)) {
        cout << line << endl;
    }
    in.close();
}

void modify() {
    int id;
    cout << "\nEnter ID to modify: "; cin >> id;
    node* p = head;
    while (p != nullptr && p->ID != id) p = p->next;
    if (!p) {
        cout << "\nProduct not found.";
        return;
    }
    cout << "\nCurrent Name: " << p->proName << ", Price: " << p->prePrice;
    cout << "\nEnter New Name: "; cin >> p->proName;
    cout << "Enter New Price: "; cin >> p->prePrice;
    cout << "\nProduct modified successfully.\n";
}

void delPro() {
    int id;
    cout << "\nEnter ID to delete: "; cin >> id;
    if (!head) return;
    if (head->ID == id) {
        node* temp = head;
        head = head->next;
        delete temp;
        cout << "\nProduct deleted.";
        return;
    }
    node* p = head;
    while (p->next && p->next->ID != id) p = p->next;
    if (!p->next) {
        cout << "\nProduct not found.";
        return;
    }
    node* temp = p->next;
    p->next = temp->next;
    delete temp;
    cout << "\nProduct deleted.";
}

int search(int id) {
    int pos = 1;
    node* p = head;
    while (p) {
        if (p->ID == id) return pos;
        p = p->next;
        pos++;
    }
    return -1;
}

void searching() {
    int id;
    cout << "\nEnter ID to search: "; cin >> id;
    node* p = head;
    while (p && p->ID != id) p = p->next;
    if (!p) {
        cout << "\nProduct not found.";
    } else {
        cout << "\nProduct Found! Name: " << p->proName << ", Price: " << p->prePrice << endl;
    }
}

void buy() {
    int id, quant;
    display();
    cout << "\nEnter ID of the product to buy: "; cin >> id;
    node* p = head;
    while (p && p->ID != id) p = p->next;
    if (!p) {
        cout << "\nProduct not found.";
        return;
    }
    cout << "Enter quantity to buy: "; cin >> quant;
    if (quant > p->quantity) {
        cout << "\nInsufficient quantity available.";
        return;
    }
    double total = quant * p->prePrice;
    double discount = total * 0.05;
    double final = total - discount;
    p->quantity -= quant;
    ofstream bill("billrecord.txt", ios::app);
    bill << "\nProduct ID: " << id;
    bill << "\nOriginal Price: " << total;
    bill << "\nDiscounted Price: " << final << "\n";
    bill.close();
    cout << "\nTotal Price: " << final << " (5% discount applied)\n";
    cout << "\nPurchase recorded.\n";
}

void showbill() {
    ifstream in("billrecord.txt");
    string line;
    while (getline(in, line)) {
        cout << line << endl;
    }
    in.close();
}
