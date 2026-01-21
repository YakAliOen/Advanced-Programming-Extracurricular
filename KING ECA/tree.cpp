#include <iostream>
using namespace std;

// Struct Node
struct Node{
  string Label;
  Node *left, *right, *parent; // For Fill Data in Tree.
};

Node *root = NULL, *newNode = NULL; // Linked List

void createtree(string label){
  if (root != NULL){
    cout << "Data is already made!" << endl;
  } else {
    root = new Node();
    root -> Label = label;
    root -> left = NULL;
    root -> right = NULL;
    root -> parent = NULL;
    cout << "Node: [" << label << "] Added Data." << endl;
  }
}

// Insert Data to Left
Node *insertLeft(string label, Node *node){
  if (root == NULL){
    cout << "Make Tree / Root first" << endl;
    return NULL;
  } else {
    if (node -> left != NULL){
      cout << "Node : [" << node -> Label << "] is located in left side." << endl;
      return NULL;
    } else {
      newNode = new Node();
      newNode -> Label = label;
      newNode -> left = NULL;
      newNode -> right = NULL;
      newNode -> parent = node;
      cout << "\n Node : " << label << " successfully added in the Left side." << newNode -> parent -> Label << endl;
      return newNode;
    }
  }
}

// Insert Data to Right
Node *insertRight(string label, Node *node){
  if (root == NULL){
    cout << "Make Tree / Root first" << endl;
    return NULL;
  } else {
    if (node -> left != NULL){
      cout << "Node : [" << node -> Label << "] is located in left side." << endl;
      return NULL;
    } else {
      newNode = new Node();
      newNode -> Label = label;
      newNode -> left = NULL;
      newNode -> right = NULL;
      newNode -> parent = node;
      cout << "\n Node : " << label << " successfully added in the Left side." << newNode -> parent -> Label << endl;
      return newNode;
    }
  }
}

// Update
void update(string label, Node *node){
  if (!root){
    cout << "\n Make Tree first!" << endl;
  } else {
    if (!node){
      cout << "\n Node is not Available!" << endl;
    } else {
      // Temp: Variable old Data
      string temp = node -> Label; // Process Updating tree
      node -> Label = label;
      cout << "\n Label Node " << temp << " successfully updated:" << label << endl;
    }
  }
}

// Preorder
void preorder(Node *node = root){
  if (!root){
    cout << "\n Make Tree first!" << endl;
  } else {
    if (node != NULL){
      cout << node -> label << ","; // To process root (owner)
      preorder (node -> left); // For left side
      preorder (node -> right); // For right side
    }
  }  
}

// Variable pointer in Tree
int main(){
  createtree("Owner");
  Node *nodestaff, *nodeadmin, *nodeaccounting, *nodehrd, *nodemechanic, *nodetechnician ;
  nodestaff = insertLeft("Staff", root);
  nodeadmin = insertRight("Admin", root);
  nodeaccounting = insertLeft("Accountant", nodestaff);
  nodetechnician = insertLeft("Technician", nodestaff);
  nodemechanic = insertRight("Mechanic", nodeadmin);
  nodehrd = insertRight("HRD", nodehrd);

  cout << "Preorder: ";
  preorder();
  cout << "\n";

  update("Supervisor", nodeadmin)
}