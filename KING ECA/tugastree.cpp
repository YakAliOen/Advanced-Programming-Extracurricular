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
    // Build the exact assignment tree
    createTree("A");

    Node *B = insertLeft("B", root);
    Node *C = insertRight("C", root);

    Node *D = insertLeft("D", B);
    Node *E = insertRight("E", B);

    Node *F = insertLeft("F", C);

    Node *G = insertLeft("G", E);
    Node *H = insertRight("H", E);

    Node *I = insertLeft("I", G);
    Node *J = insertRight("J", G);

    cout << "\nPreorder  : ";
    preorder(root);

    cout << "\nInorder   : ";
    inorder(root);

    cout << "\nPostorder : ";
    postorder(root);

    return 0;
}