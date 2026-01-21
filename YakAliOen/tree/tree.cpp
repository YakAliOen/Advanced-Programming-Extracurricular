#include <iostream>
using namespace std;

// strut node
struct Node{
    string label; // untuk isi data di tree
    Node *left, *right, *parent;
};

// penjelasan variable pointer di tree
Node *root = NULL, *newNode = NULL; // linked list

// function untuk create tree
void createtree(string label){
    if (root != NULL){
        cout << "Data root sudah dibuat !!" <<endl;
    } else {
        root = new Node();
        root -> label = label;
        root -> left = NULL;
        root -> right = NULL;
        root -> parent = NULL;
        cout << "Node: " << label << " berhasil ditambahkan menjadi root" <<endl;
    }
}

// insert left
Node *insertleft(string label, Node *node){
    if (root == NULL){
        cout << "Buat tree / root terbelih dahulu !!" <<endl;
        return NULL;
    } else {
        // if buat menampilkan data yang sudah ada
        if (node -> left != NULL){
            cout << "Node: " << node -> label << " berada pada left" <<endl;
            return NULL;
        } else { // else apabila belum ada data
            newNode = new Node();
            newNode -> label = label;
            newNode -> left = NULL;
            newNode -> right = NULL;
            newNode -> parent = node;
            node -> left = newNode; // proses masukkan data ke level 2
            cout << "\n Node: " << label << " berhasil ditambahkan di bagian left " 
            << newNode -> parent -> label <<endl;
            return newNode;
        }
    }
}

int main(){
    createtree("Owner");
    Node *nodeperusahaan;
    nodeperusahaan = insertleft("Staff", root);
}
