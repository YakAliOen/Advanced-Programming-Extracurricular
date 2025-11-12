//single linked list

#include <iostream>
#include <cctype>
using namespace std;

bool isAlphaString(const string& str);

struct product
{
    string name, category;
    int price;
    product *next;
};

int main()
{
    //initialisation
    product *node1, *node2, *node3;
    node1 = new product();
    node2 = new product();
    node3 = new product();

    product* nodes[3] = {node1, node2, node3};
    for (int i = 0; i < 3; ++i) {
        cout << "Product " << (i + 1) << endl;

        // Name validation
        while (true) {
            cout << "Name: ";
            cin >> nodes[i]->name;
            if (isAlphaString(nodes[i]->name)) break;
            cout << "Invalid input. Name must be alphabetic." << endl;
        }

        // Category validation
        while (true) {
            cout << "Category: ";
            cin >> nodes[i]->category;
            if (isAlphaString(nodes[i]->category)) break;
            cout << "Invalid input. Category must be alphabetic." << endl;
        }

        // Price validation
        while (true) {
            cout << "Price: ";
            string priceInput;
            cin >> priceInput;
            bool valid = true;
            for (char c : priceInput) {
                if (!isdigit(c)) {
                    valid = false;
                    break;
                }
            }
            if (valid && !priceInput.empty()) {
                nodes[i]->price = stoi(priceInput);
                break;
            }
            cout << "Invalid input. Price must be an integer." << endl;
        }

        if (i < 2) nodes[i]->next = nodes[i+1];
        else nodes[i]->next = nullptr;
        cout << endl;
    }

    //output
    product *cursor;
    cursor = node1;
    while(cursor != NULL)
    {
        cout << "Product " << cursor->name << " is " << cursor->category << ", " << cursor->price << endl;
        cursor = cursor->next;
    }

    return 0;
}

bool isAlphaString(const string& str) {
    for (char c : str) {
        if (!isalpha(c)) return false;
    }
    return !str.empty();
}