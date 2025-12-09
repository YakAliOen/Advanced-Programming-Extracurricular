//difference between double and single linked list is that DOUBLE has PREVIOUS
#include <iostream>
using namespace std;

struct account //declaring struct
{
    string username, name, email, password;
    account *next, *prev;
};
account *head = NULL, *tail = NULL, *cur, *del, *baru;

account *create (string username, string name, string email, string password) //function u/ create data
{
    account *node = new account;
    node ->username = username;
    node ->name = name;
    node ->email = email;
    node ->password = password;
    node ->prev = NULL;
    node ->next = NULL;
    return NULL;
}

void addfirst(string username, string name, string email, string password)
{
    baru = create(username, name, email, password);

    if (head == NULL)
    {
        head = tail = baru;
    }
    else{
        baru ->next = head;
        head ->prev = baru;
        head = baru;
    }
    cout<<"\n Data berhasil ditambahkan di data awal \n";
}

void addlast(string username, string name, string email, string password)
{
    baru = create(username, name, email, password);

    if (head == NULL)
    {
        head = tail = baru;
    }
    else{
        tail -> next = baru;
        baru -> prev = tail;
        tail = baru;
    }
    cout<<"\n Data berhasil ditambahkan di data akhir \n";
}


void printdouble()
{
    if(head == NULL)
    {
        cout <<"belum ada data";
    }else{
        cout << "=== isi data ===" <<endl;
        cur =head;
        while (cur != NULL){
            cout << "Username: "<< cur ->username <<endl;
            cout << "Name: "<< cur ->name <<endl;
            cout << "Email: "<< cur ->email <<endl;
            cout << "Password: "<< cur ->password <<endl;
            cur = cur ->next;
        }
    }
}

int main()
{
    int option;
    string username, name, email, password;
    do {
        cout << "\n Menu Sisuca \n";
        cout << "1. Tambah data di awal \n";
        cout << "2. Tambah data di akhir \n";
        cout << "3. Tampilkan data \n";
        cout << "Choose Option: ";
        cin >> option;
        switch (option)
        {
            case 1:
            cout << "Tambah data di awal \n";
            cout << "Username: "; cin >> username;
            cout << "Name: "; cin >> name;
            cout << "Email: "; cin >> email;
            cout << "Password: "; cin >> password;
            addfirst(username, name, email, password);
            break;

            case 2:
            cout << "Tambah data di akhir \n";
            cout << "Username: "; cin >> username;
            cout << "Name: "; cin >> name;
            cout << "Email: "; cin >> email;
            cout << "Password: "; cin >> password;
            addlast(username, name, email, password);
            break;

            case 3:
            printdouble();
            break;

            default:
            cout << "Menu tidak valid \n";
        }
    }while(option != 3);

    return 0;
}