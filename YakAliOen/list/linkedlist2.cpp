#include <iostream>
using namespace std;

struct product
{
    string name, category;
    int price;
    product *next;
};

product *head, *tail, *cur, *newnode;

void createlinkedlist(string name, string category, int price)
{
    head = new product();
    head->name = name;
    head->category = category;
    head->price = price;
    head->next = NULL;
    tail = head;
}

void printlinkedlist()
{
    cur = head;
    int i = 1;
    while(cur != NULL)
    {
        cout << "=== Product " << i << ": ===" << endl;
        cout << "Name: " << cur->name << endl;
        cout << "Category: " << cur->category << endl;
        cout << "Price: " << cur->price << endl;
        cur = cur->next;
        i++;
    }
}

void addfirst(string name, string category, int price)
{
    product *newnode = new product();
    newnode->name = name;
    newnode->category = category;
    newnode->price = price;
    newnode->next = head;
    head = newnode;
}

void changefirst(string name, string category, int price)
{
    if (head != NULL)
    {
        head->name = name;
        head->category = category;
        head->price = price;
    }
}

int main()
{
    cout << "Input Product: " << endl;
    string p, c;
    int pr;
    cout << "Enter product name: ";
    cin >> p;
    cout << "Enter product category: ";
    cin >> c;
    cout << "Enter product price: ";
    cin >> pr;
    cout << endl;

    createlinkedlist(p, c, pr);

    cout << "Add another product at the front:" << endl;
    cout << "Enter product name: ";
    cin >> p;
    cout << "Enter product category: ";
    cin >> c;
    cout << "Enter product price: ";
    cin >> pr;
    cout << endl;

    addfirst(p, c, pr);
    printlinkedlist();
    cout << endl;

    cout << "Change the first product:" << endl;
    cout << "Enter new product name: ";
    cin >> p;
    cout << "Enter new product category: ";
    cin >> c;
    cout << "Enter new product price: ";
    cin >> pr;
    cout << endl;

    changefirst(p, c, pr);
    printlinkedlist();
    return 0;
}