#include <iostream>
#include <string>
using namespace std;

//struct Node {
//    int data;
//    Node* prev;
//    Node* next;
//    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
//};

struct account {
    string username, name, email, password;
    account* prev;
    account* next;
    account(string u, string n, string e, string p)
        : username(u), name(n), email(e), password(p), prev(nullptr), next(nullptr) {}
};

class DoubleLinkedList {
private:
    account* head;
    account* tail;
public:
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoubleLinkedList() {
        account* current = head;
        while (current) {
            account* next = current->next;
            delete current;
            current = next;
        }
    }

    void push_front(const string& username, const string& name, const string& email, const string& password) {
        account* node = new account(username, name, email, password);
        node->next = head;
        if (head) head->prev = node;
        head = node;
        if (!tail) tail = node;
    }

    void push_back(const string& username, const string& name, const string& email, const string& password) {
        account* node = new account(username, name, email, password);
        node->prev = tail;
        if (tail) tail->next = node;
        tail = node;
        if (!head) head = node;
    }

    void pop_front() {
        if (!head) return;
        account* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
    }

    void pop_back() {
        if (!tail) return;
        account* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
    }

    void print_forward() const {
        account* current = head;
        while (current) {
            cout << "[Username: " << current->username << ", Name: " << current->name << ", Email: " << current->email << ", Password: " << current->password << "]\n";
            current = current->next;
        }
        cout << endl;
    }

    void print_backward() const {
        account* current = tail;
        while (current) {
            cout << "[Username: " << current->username << ", Name: " << current->name << ", Email: " << current->email << ", Password: " << current->password << "]\n";
            current = current->prev;
        }
        cout << endl;
    }
};


int main() {
    DoubleLinkedList dll;
    int choice;
    string username, name, email, password;
    while (true) {
        cout << "\nDouble Linked List Account Menu:\n";
        cout << "1. Push Front\n2. Push Back\n3. Pop Front\n4. Pop Back\n5. Print Forward\n6. Print Backward\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 0) break;
        switch (choice) {
            case 1:
                cout << endl;
                cout << "Enter username: "; cin >> username;
                cout << "Enter name: "; cin >> name;
                cout << "Enter email: "; cin >> email;
                cout << "Enter password: "; cin >> password;
                dll.push_front(username, name, email, password);
                break;
            case 2:
                cout << endl;
                cout << "Enter username: "; cin >> username;
                cout << "Enter name: "; cin >> name;
                cout << "Enter email: "; cin >> email;
                cout << "Enter password: "; cin >> password;
                dll.push_back(username, name, email, password);
                break;
            case 3:
                dll.pop_front();
                cout << "Front account removed.\n";
                break;
            case 4:
                dll.pop_back();
                cout << "Back account removed.\n";
                break;
            case 5:
                cout << endl;
                cout << "Accounts (forward):\n";
                dll.print_forward();
                break;
            case 6:
                cout << endl;
                cout << "Accounts (backward):\n";
                dll.print_backward();
                break;
            default:
                cout << endl;
                cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}