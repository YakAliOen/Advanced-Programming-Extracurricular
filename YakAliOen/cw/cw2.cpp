#include <iostream>
#include <string>

using namespace std;


struct Node
{
    string label;
    Node *left;
    Node *right;
    Node *parent;
};


Node *root = NULL;
Node *newNode = NULL;

void createTree(string label);
Node *insertLeft(string label, Node *node);
Node *insertRight(string label, Node *node);
void update(string label, Node *node);

void preorder(Node *node);
void inorder(Node *node);
void postorder(Node *node);

Node* findNode(Node* node, const string& label);
void displayTree(Node* node, int space);


int main(void)
{
    int choice;
    string label, parentLabel;
    Node* parentNode;

    do
    {
        cout << "\n===== Binary Tree Menu =====\n";
        cout << "1. Create root\n";
        cout << "2. Insert left child\n";
        cout << "3. Insert right child\n";
        cout << "4. Update node label\n";
        cout << "5. Preorder traversal\n";
        cout << "6. Inorder traversal\n";
        cout << "7. Postorder traversal\n";
        cout << "8. Display tree\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter root label: ";
            cin >> label;
            createTree(label);
            break;

        case 2:
            cout << "Enter parent label: ";
            cin >> parentLabel;
            parentNode = findNode(root, parentLabel);

            cout << "Enter new node label: ";
            cin >> label;
            insertLeft(label, parentNode);
            break;

        case 3:
            cout << "Enter parent label: ";
            cin >> parentLabel;
            parentNode = findNode(root, parentLabel);

            cout << "Enter new node label: ";
            cin >> label;
            insertRight(label, parentNode);
            break;

        case 4:
            cout << "Enter node label to update: ";
            cin >> parentLabel;
            parentNode = findNode(root, parentLabel);

            cout << "Enter new label: ";
            cin >> label;
            update(label, parentNode);
            break;

        case 5:
            cout << "\nPreorder Traversal:\n";
            preorder(root);
            cout << endl;
            break;

        case 6:
            cout << "\nInorder Traversal:\n";
            inorder(root);
            cout << endl;
            break;

        case 7:
            cout << "\nPostorder Traversal:\n";
            postorder(root);
            cout << endl;
            break;

        case 8:
            cout << "\nTree Structure:\n";
            displayTree(root, 0);
            break;

        case 0:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}


void createTree(string label)
{
    if (root)
    {
        cout << "Root already exists!\n";
        return;
    }

    root = new Node();
    root->label = label;
    root->left = NULL;
    root->right = NULL;
    root->parent = NULL;

    cout << "Root '" << label << "' created\n";
}


Node *insertLeft(string label, Node *node)
{
    if (!node)
    {
        cout << "Parent node not found!\n";
        return NULL;
    }
    if (node->left)
    {
        cout << "Left child already exists!\n";
        return NULL;
    }

    newNode = new Node();
    newNode->label = label;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = node;

    node->left = newNode;

    cout << "Node '" << label << "' added as LEFT child of '" << node->label << "'\n";
    return newNode;
}


Node *insertRight(string label, Node *node)
{
    if (!node)
    {
        cout << "Parent node not found!\n";
        return NULL;
    }
    if (node->right)
    {
        cout << "Right child already exists!\n";
        return NULL;
    }

    newNode = new Node();
    newNode->label = label;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = node;

    node->right = newNode;

    cout << "Node '" << label << "' added as RIGHT child of '" << node->label << "'\n";
    return newNode;
}


void update(string label, Node *node)
{
    if (!node)
    {
        cout << "Node not found!\n";
        return;
    }

    node->label = label;
    cout << "Node updated successfully\n";
}


void preorder(Node *node)
{
    if (!node) return;

    cout << node->label << " ";
    preorder(node->left);
    preorder(node->right);
}


void inorder(Node *node)
{
    if (!node) return;

    inorder(node->left);
    cout << node->label << " ";
    inorder(node->right);
}


void postorder(Node *node)
{
    if (!node) return;

    postorder(node->left);
    postorder(node->right);
    cout << node->label << " ";
}


void displayTree(Node* node, int space)
{
    if (!node) return;

    space += 5;

    displayTree(node->right, space);

    cout << endl;
    for (int i = 5; i < space; i++)
        cout << " ";
    cout << node->label << "\n";

    displayTree(node->left, space);
}


Node* findNode(Node* node, const string& label)
{
    if (!node) return NULL;

    if (node->label == label)
        return node;

    Node* leftResult = findNode(node->left, label);
    if (leftResult) return leftResult;

    return findNode(node->right, label);
}
