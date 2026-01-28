#include <iostream>
using namespace std;

// Struct Node
struct Node {
    string label;
    Node *left, *right, *parent;
};

Node *root = NULL;

// Create root
void createTree(string label) {
    if (root != NULL) {
        cout << "Tree already exists!" << endl;
    } else {
        root = new Node();
        root->label = label;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "Root [" << label << "] created." << endl;
    }
}

// Insert Left
Node* insertLeft(string label, Node *node) {
    if (node == NULL) return NULL;

    if (node->left != NULL) {
        cout << "Left child already exists for " << node->label << endl;
        return NULL;
    }

    Node *newNode = new Node();
    newNode->label = label;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = node;
    node->left = newNode;

    return newNode;
}

// Insert Right
Node* insertRight(string label, Node *node) {
    if (node == NULL) return NULL;

    if (node->right != NULL) {
        cout << "Right child already exists for " << node->label << endl;
        return NULL;
    }

    Node *newNode = new Node();
    newNode->label = label;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = node;
    node->right = newNode;

    return newNode;
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
      string temp = node -> label; // Process Updating tree
      node -> label = label;
      cout << "\n Label Node " << temp << " successfully updated:" << label << endl;
    }
  }
}

// Preorder Traversal
void preorder(Node *node) {
    if (node != NULL) {
        cout << node->label << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

// Inorder Traversal
void inorder(Node *node) {
    if (node != NULL) {
        inorder(node->left);
        cout << node->label << " ";
        inorder(node->right);
    }
}

// Postorder Traversal
void postorder(Node *node) {
    if (node != NULL) {
        postorder(node->left);
        postorder(node->right);
        cout << node->label << " ";
    }
}

int main() {
    int option;
    string label;
    Node *active = NULL; // Why NULL? cause there are no data input. yet.
    do {
        cout << "Menu TREE" << endl;
        cout << "1. Make Root" << endl;
        cout << "2. Input Data Left side (Level 1)" << endl;
        cout << "3. Input Data Right side (Level 1)" << endl;
        cout << "4. Update Data" << endl;
        cout << "5. Pre Order" << endl;
        cout << "6. In Order" << endl;
        cout << "7. Post Order" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose Option: ";
        cin  >> option;

        switch (option)
        {
        case 1:
            cout << "Input Data Root: ";
            cin  >> label;
            createTree(label);
            active = root;
            break;
        case 2:
            cout << "Input Data Node Left: ";
            cin  >> label;
            active = insertLeft(label, active);
            break;
        case 3:
            cout << "Input Data Node Right: ";
            cin  >> label;
            active = insertRight(label, active);
            break;
        case 4:
            cout << "Input Data Update Data: ";
            cin  >> label;
            update(label, active);
            break;
        case 5:
            cout << "Input Data PreOrder Data: ";
            preorder(root);
            cout << endl;
            break;
        case 6:
            cout << "Input Data InOrder Data: ";
            inorder(root);
            cout << endl;
            break;
        case 7:
            cout << "Input Data PostOrder Data: ";
            postorder(root);
            cout << endl;
            break;
        case 0:
            break;

        default:
            cout << "Wrong Input!";
        }
    } while (option != 0);

    return 0;
}