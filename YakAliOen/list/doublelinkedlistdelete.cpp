
#include <iostream>
#include <string>
using namespace std;


struct account {
    string username, name, email, password;
    account* prev;
    account* next;
    account(string u, string n, string e, string p)
        : username(u), name(n), email(e), password(p), prev(NULL), next(NULL) {}
};


account *head = NULL, *tail = NULL, *cur = NULL, *newNode = NULL, *del = NULL, *baru = NULL;


account *create (string username, string name, string email, string password) {
    // use the defined constructor
    account *node = new account(username, name, email, password);
    return node;
}


//prototypes
void addfirst(string username, string name, string email, string password);
void addlast(string username, string name, string email, string password);
void deletefirst();
void deletelast();
void print();


//main
int main() {
    int choice;
    string username, name, email, password;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add First\n";
        cout << "2. Add Last\n";
        cout << "3. Delete First\n";
        cout << "4. Delete Last\n";
        cout << "5. Print\n";
        cout << "6. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter email: ";
                cin >> email;
                cout << "Enter password: ";
                cin >> password;
                addfirst(username, name, email, password);
                break;
            case 2:
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter email: ";
                cin >> email;
                cout << "Enter password: ";
                cin >> password;
                addlast(username, name, email, password);
                break;
            case 3:
                deletefirst();
                break;
            case 4:
                deletelast();
                break;
            case 5:
                print();
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}


//tambah data di awal
void addfirst(string username, string name, string email, string password) {
    baru = create(username, name, email, password);
    if (head == NULL) {
        head = tail = baru;
    } else {
        baru->next = head;
        head->prev = baru;
        head = baru;
    }
    cout << "Data berhasil ditambahkan di awal.\n";
}


//tambah data di akhir
void addlast(string username, string name, string email, string password) {
    baru = create(username, name, email, password);
    if (head == NULL) {
        head = tail = baru;
    } else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
    cout << "Data berhasil ditambahkan di akhir.\n";
}


//delete first


//delete last


//print
void print() {
    if (head == NULL) {
        cout << "Data kosong.\n";
    } else {
        cur = head;
        int i = 1;
        while (cur != NULL) {
            cout << i++ << ". " << cur->username << " | " << cur->name << " | " << cur->email << " | " << cur->password << endl;
            cur = cur->next;
        }
    }
}