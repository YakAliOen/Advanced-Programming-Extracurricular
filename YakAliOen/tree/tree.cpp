#include <iostream>
#include <string>

using namespace std;

/**
 * Node structure for binary tree
 * Represents each node in the organizational hierarchy
 */
struct Node
{
    string label;
    Node *left;
    Node *right;
    Node *parent;
};

// Global pointers for tree management
Node *root = NULL;
Node *newNode = NULL;

/**
 * Creates the root node of the tree
 * @param label The label for the root node
 */
void createTree(string label)
{
    if (root != NULL)
    {
        cout << "Root node already exists!" << endl;
    }
    else
    {
        root = new Node();
        root->label = label;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "Node: " << label << " successfully added as root" << endl;
    }
}

/**
 * Inserts a node as the left child of the given node
 * @param label The label for the new node
 * @param node The parent node
 * @return Pointer to the newly created node, or NULL if operation fails
 */
Node *insertLeft(string label, Node *node)
{
    if (root == NULL)
    {
        cout << "Please create a tree/root first!" << endl;
        return NULL;
    }
    else if (node->left != NULL)
    {
        cout << "Node: " << node->label << " already has a left child" << endl;
        return NULL;
    }
    else
    {
        newNode = new Node();
        newNode->label = label;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->parent = node;
        node->left = newNode;
        cout << "Node: " << label << " successfully added as left child of "
             << newNode->parent->label << endl;
        return newNode;
    }
}

/**
 * Inserts a node as the right child of the given node
 * @param label The label for the new node
 * @param node The parent node
 * @return Pointer to the newly created node, or NULL if operation fails
 */
Node *insertRight(string label, Node *node)
{
    if (root == NULL)
    {
        cout << "Please create a tree/root first!" << endl;
        return NULL;
    }
    else if (node->right != NULL)
    {
        cout << "Node: " << node->label << " already has a right child" << endl;
        return NULL;
    }
    else
    {
        newNode = new Node();
        newNode->label = label;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->parent = node;
        node->right = newNode;
        cout << "Node: " << label << " successfully added as right child of "
             << newNode->parent->label << endl;
        return newNode;
    }
}

/**
 * Updates the label of a given node
 * @param label The new label for the node
 * @param node The node to be updated
 */
void update(string label, Node *node)
{
    if (!root)
    {
        cout << "Please create a tree first!" << endl;
    }
    else if (!node)
    {
        cout << "Node does not exist!" << endl;
    }
    else
    {
        string temp = node->label;
        node->label = label;
        cout << "Node label '" << temp << "' successfully changed to '" << label << "'" << endl;
    }
}

/**
 * Performs preorder traversal of the tree
 * @param node The current node to process
 */
void preorder(Node *node)
{
    if (!root)
    {
        cout << "Please create a tree first!" << endl;
    }
    else if (node != NULL)
    {
        cout << node->label << ", ";
        preorder(node->left);
        preorder(node->right);
    }
}

/**
 * Main function - demonstrates tree creation and operations
 */
int main(void)
{
    // Create root node
    createTree("Owner");

    // Declare node pointers for organizational structure
    Node *nodeStaff, *nodeAdmin, *nodeSecurity, *nodeTechnician;

    // Build organizational hierarchy
    nodeStaff = insertLeft("Staff", root);
    nodeAdmin = insertRight("Admin", root);
    nodeSecurity = insertRight("Security", nodeAdmin);
    nodeTechnician = insertLeft("Technician", nodeStaff);

    // Update a node label
    update("Supervisor", nodeAdmin);

    // Display tree in preorder traversal
    cout << "\nPreorder Traversal:" << endl;
    preorder(root);
    cout << endl;

    return 0;
}
