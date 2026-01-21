#include <iostream>
#include <limits>
using namespace std;

//single linked list
struct antriankopi
{
    string name;
    string order;
    antriankopi *next;
};

int maksimal = 5;
antriankopi *head = nullptr, *tail = nullptr, *cur = nullptr, *del = nullptr, *newnode = nullptr;

int count()
{
    int jumlah = 0;
    cur = head;
    while (cur != nullptr)
    {
        jumlah++;
        cur = cur->next;
    }
    return jumlah;
}

//function full
bool isfull()
{
    return count() >= maksimal;
}

//function empty
bool isempty()
{
    return head == nullptr;
}

void enqueue(string nama, string pesanan)
{
    if (isfull())
    {
        cout << "Antrian penuh!" << endl;
    }
    else
    {
        //head = new antraiankopi();
        //head -> name = nama;
        //head -> order = pesanan;
        //head -> next = NULL;
        //tail = head;
        newnode = new antriankopi();
        newnode->name = nama;
        newnode->order = pesanan;
        newnode->next = nullptr;
        if (isempty())
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cout << nama << " telah ditambahkan ke antrian.\n" << endl;
    }
}

void display()
{
    cout << "Daftar Antrian Kopi: " << endl;
    if (isempty())
    {
        cout << "Antrian kosong!" << endl;
    }
    else
    {
        int total = count();
        cout << "Ada " << total << " antrian." << endl;
        cur = head;
        int id = 1;
        while (cur != nullptr)
        {
            cout << id << ". " << cur->name << " - Pesanan: " << cur->order << endl;
            cur = cur->next;
            id++;
        }
        cout << endl;
    }
}

int main()
{
    cout << "\nSelamat datang di Kopi Rollaas Cafe!" << endl;
    while (true)
    {
        cout << "Menu:\n1. Tambah Antrian\n2. Tampilkan Antrian\n3. Keluar\nPilihan: ";
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            string nama, pesanan;
            cout << "Masukkan nama pelanggan: ";
            cin >> nama;
            cout << "Masukkan pesanan kopi: ";
            cin >> pesanan;
            enqueue(nama, pesanan);
        }
        else if (choice == 2)
        {
            display();
        }
        else if (choice == 3)
        {
            cout << "Terima kasih telah menggunakan layanan kami!" << endl;
            break;
        }
        else
        {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }
    return 0;
}
