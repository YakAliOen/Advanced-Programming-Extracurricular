#include<iostream>
using namespace std;
//struct node
struct Node{
    string label; // u/ isi data di tree
    Node *left, *right, *parent; 
};
//penjelasan variable pointer di tree
Node *root = NULL,*newNode = NULL; // linked list
// function u/ create tree
void createtree(string label)
{
if (root!= NULL)
    cout<<"Data Root sudah dibuat !!"<<endl;
else{
    root = new Node();
    root ->label = label;
    root ->left = NULL;
    root ->right = NULL;
    root ->parent = NULL;
    cout<<"Node :" << label <<" Berhasil Ditambahkan menjadi root "<<endl;
    }
}
// insert left
Node *insertleft(string label,Node *node)
{
    if (root == NULL){
    cout<<"Buat Tree / root terlebih dahulu !!"<<endl;
    return NULL;
}else{
   // if buat menampilkan data yang sudah ada
   if (node ->left != NULL){
    cout<<"Node :"<< node->label <<"Berada pada left"<<endl;
    return NULL;
   }else {
    newNode = new Node();
    newNode ->label = label;
    newNode ->left = NULL;
    newNode ->right = NULL;
    newNode ->parent = node;
    node->left = newNode; //proses masukkan data ke level 2
    cout<<"\n Node :" <<label
    <<" berhasil ditambahkan di bagian left"
    <<newNode->parent->label <<endl;
    return newNode;
   }
   // else apabila belum ada data
}
}
//insert right
Node *insertright(string label,Node *node)
{
    if (root == NULL){
    cout<<"Buat Tree / root terlebih dahulu !!"<<endl;
    return NULL;
}else{
   // if buat menampilkan data yang sudah ada
   if (node ->right != NULL){
    cout<<"Node :"<< node->label <<"Berada pada right"<<endl;
    return NULL;
   }else {
    newNode = new Node();
    newNode ->label = label;
    newNode ->left = NULL;
    newNode ->right = NULL;
    newNode ->parent = node;
    node->right = newNode; //proses masukkan data ke level 2
    cout<<"\n Node :" <<label
    <<" berhasil ditambahkan di bagian right"
    <<newNode->parent->label <<endl;
    return newNode;
   }
   // else apabila belum ada data
}
}

void update(string label, Node *node){
    if(!root){
        cout<<"\n Buat tree terlebih dahulu! "<<endl;
    }else{
        if(!node)
            cout<<"\n Node diganti tidak ada! "<<endl;
        else{
            string temp = node->label;
            node->label = label;
            cout<<"\n Label node "<< temp <<" berhasil diubah menjadi "<< label <<endl; 
        }
    }
}

void preorder(Node *node = root){
    if(!root){
        cout<<"\n Buat tree terlebih dahulu! "<<endl;
    }else{
        if(node != NULL){
            cout << node->label <<","; // process for root (Owner)
            preorder(node->left);
            preorder(node->right);
        }
    }
}

int main(){
    createtree(" Owner");
    Node *nodestaff, *nodeadmin, *nodesecurity, *nodeteknisi; 
    nodestaff = insertleft("Staff",root);
    nodeadmin = insertright("Admin", root);
    nodesecurity = insertright("Security", nodeadmin);
    nodeteknisi = insertleft("Teknisi", nodestaff);


    update("Supervisor", nodeadmin);
    
    cout<<"\n Pre Order"<<endl;
    preorder();
}
