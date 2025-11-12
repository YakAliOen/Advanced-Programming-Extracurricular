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

void addfirst(string name, string category, int price)
{
    newnode = new product();
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

int main()
{
    createlinkedlist("Indomie", "Mie", 2018);
    printlinkedlist();
    cout << "\n\n";

    addfirst("Aqua", "Air Minum", 2009);
    printlinkedlist();
    cout << "\n\n";

    changefirst("Le Mineral", "Mineral Water", 2000);
    printlinkedlist();
    cout << "\n\n";

    return 0;
}