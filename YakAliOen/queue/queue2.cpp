#include <iostream>
using namespace std;

int maksarray = 5, front = 0, back = 0;
string antrianmcd[5];

bool isfull() {
    return back == maksarray;
}

bool isempty() {
    return back == 0;
}

void enqueuearray(string data) {
    if (isfull()) {
        cout << "Data penuh bro!!" << endl;
    } else {
        if (isempty()) {
            antrianmcd[0] = data;
            front++;
            back++;
        } else {
            antrianmcd[back] = data;
            back++;
        }
    }
}

void dequeue()
{
    if (isempty())
    {
        cout << "Antrian Kosong, input dulu !!" << endl;
    }
    else
    {
        //you can use for loop bruh
        antrianmcd[0] = antrianmcd[1];
        antrianmcd[1] = antrianmcd[2];
        antrianmcd[2] = antrianmcd[3];
        antrianmcd[3] = antrianmcd[4];
        antrianmcd[4] = "";
    }
}

int count()
{
    if (isempty())
    {
        return 0;
    }
    else if (isfull())
    {
        return maksarray;
    }
    else
    {
        return back;
    }
}

void destroy()
{
    if (isempty())
    {
        cout << "Antrian kosong, input dulu !!" << endl;
    }
    else
    {
        for (int i = 0; i < maksarray; i++)
        {
            if (back > 1)
            {
                antrianmcd[back - 1] = "";
                back--;
            }
            else if (back == 1)
            {
                antrianmcd[back - 1] = "";
                back = 0;
                front = 0;
            }
        }
    }
}

void view() {
    cout << "\nData Antrian MCD:" << endl;
    for (int i = 0; i < maksarray; i++) {
        if (antrianmcd[i] != "") {
            cout << i + 1 << ". " << antrianmcd[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    int jumlah;
    string nama;

    cout << "Masukkan jumlah antrian (maksimal " << maksarray << "): ";
    cin >> jumlah;
    cin.ignore(); // hapus newline di buffer

    if (jumlah > maksarray) {
        cout << "Jumlah antrian melebihi kapasitas!" << endl;
        jumlah = maksarray;
    }

    for (int i = 0; i < jumlah; i++) {
        cout << "Masukkan nama pelanggan ke-" << i + 1 << ": ";
        getline(cin, nama);
        enqueuearray(nama);
    }

    view();

    dequeue();
    view();
    destroy();
    view();

    cout << "Jumlah antrian MCD: " << count << endl;

    return 0;
}
