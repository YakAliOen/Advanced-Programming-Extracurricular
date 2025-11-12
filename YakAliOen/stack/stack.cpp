//suggestion: use classes and methods

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

// Implementasi Stack untuk string dengan input pengguna
// Fitur: kapasitas ditentukan oleh pengguna, push manual, pop, peek, display, dll.

class Stack {
private:
    vector<string> data; // tempat penyimpanan elemen stack
    int capacity;        // kapasitas maksimum
    int top;             // posisi elemen berikutnya (jumlah elemen saat ini)

public:
    // Konstruktor
    explicit Stack(int cap) : data(cap), capacity(cap), top(0) {}

    bool isFull() const { return top == capacity; }
    bool isEmpty() const { return top == 0; }
    int size() const { return top; }
    int max_size() const { return capacity; }

    void push(const string &value) {
        if (isFull()) {
            throw runtime_error("Stack penuh! Tidak bisa menambahkan produk baru.");
        }
        data[top++] = value;
    }

    string pop() {
        if (isEmpty()) {
            throw runtime_error("Stack kosong! Tidak ada produk untuk dihapus.");
        }
        --top;
        string val = data[top];
        data[top].clear();
        return val;
    }

    const string &peek() const {
        if (isEmpty()) {
            throw runtime_error("Stack kosong! Tidak ada produk di atas.");
        }
        return data[top - 1];
    }

    void display() const {
        cout << "\nIsi Stack (atas -> bawah):" << endl;
        if (isEmpty()) {
            cout << "  [kosong]" << endl;
            return;
        }
        for (int i = top - 1; i >= 0; --i) {
            cout << "  [" << i << "] " << data[i] << endl;
        }
    }
};

int main() {
    int cap;
    cout << "Masukkan kapasitas maksimum stack: ";
    cin >> cap;
    cin.ignore(); // bersihkan newline dari buffer

    Stack st(cap);
    int choice;
    string item;

    do {
        cout << "\n=== MENU STACK PRODUK ===\n";
        cout << "1. Tambah produk (push)\n";
        cout << "2. Hapus produk terakhir (pop)\n";
        cout << "3. Lihat produk paling atas (peek)\n";
        cout << "4. Tampilkan semua produk (display)\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> choice;
        cin.ignore(); // membersihkan input buffer

        try {
            switch (choice) {
                case 1:
                    cout << "Masukkan nama produk: ";
                    getline(cin, item);
                    st.push(item);
                    cout << item << "' telah ditambahkan.\n";
                    break;
                case 2:
                    cout << "Produk '" << st.pop() << "' telah dihapus.\n";
                    break;
                case 3:
                    cout << "Produk paling atas: " << st.peek() << endl;
                    break;
                case 4:
                    st.display();
                    break;
                case 5:
                    cout << "Keluar dari program.\n";
                    break;
                default:
                    cout << "Pilihan tidak valid.\n";
            }
        }
        catch (const exception &e) {
            cout << "Error: " << e.what() << endl;
        }
    } while (choice != 5);

    return 0;
}
