#include <iostream>
using namespace std;

struct product
{
    string name, category;
    int price;
    product *next;
};

product *head = NULL, *tail = NULL, *cur = NULL, *newnode = NULL;

void createlinkedlist(string name, string category, int price);
void addfirst(string name, string category, int price);
void addlast(string name, string category, int price);
void addmiddle(string name, string category, int price, int position);
void changefirst(string name, string category, int price);
void deletefirst();
void deletelast();
void deletemiddle(int position);
void printlinkedlist();

int main()
{
    int choice, price, position;
    string name, category;
    bool running = true;

    cout << "Enter first product data:\n";
    cout << "Name: "; cin >> name;
    cout << "Category: "; cin >> category;
    cout << "Price: "; cin >> price;
    createlinkedlist(name, category, price);

    while (running)
    {
        cout << "\nMenu:\n";
        cout << "1. Add product at front\n";
        cout << "2. Add product at back\n";
        cout << "3. Add product at middle (position)\n";
        cout << "4. Change first product\n";
        cout << "5. Delete first product\n";
        cout << "6. Delete last product\n";
        cout << "7. Delete product at middle (position)\n";
        cout << "8. Print products\n";
        cout << "9. Exit\n";
        cout << "Choose: "; cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Name: "; cin >> name;
                cout << "Category: "; cin >> category;
                cout << "Price: "; cin >> price;
                addfirst(name, category, price);
                break;
            case 2:
                cout << "Name: "; cin >> name;
                cout << "Category: "; cin >> category;
                cout << "Price: "; cin >> price;
                addlast(name, category, price);
                break;
            case 3:
                cout << "Position: "; cin >> position;
                cout << "Name: "; cin >> name;
                cout << "Category: "; cin >> category;
                cout << "Price: "; cin >> price;
                addmiddle(name, category, price, position);
                break;
            case 4:
                cout << "Name: "; cin >> name;
                cout << "Category: "; cin >> category;
                cout << "Price: "; cin >> price;
                changefirst(name, category, price);
                break;
            case 5:
                deletefirst();
                break;
            case 6:
                deletelast();
                break;
            case 7:
                cout << "Position: "; cin >> position;
                deletemiddle(position);
                break;
            case 8:
                printlinkedlist();
                break;
            case 9:
                running = false;
                break;
            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}

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
    if (tail == NULL) tail = head;
}

void addlast(string name, string category, int price)
{
    newnode = new product();
    newnode->name = name;
    newnode->category = category;
    newnode->price = price;
    newnode->next = NULL;
    if (head == NULL) {
        head = tail = newnode;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
}

//adding data at middle
void addmiddle(string name, string category, int price, int position)
{
    if (position <= 1 || head == NULL) //to validate and use the available position
    //Basically base case
    {
        addfirst(name, category, price);
        return;
    }
    cur = head;
    int idx = 1;

    while (cur != NULL && idx < position - 1) //Mencari position
    {
        cur = cur->next;
        idx++;
    }

    if (cur == NULL || cur->next == NULL) //Cek ada tidak, if none add last
    {
        addlast(name, category, price);
        return;
    }

    newnode = new product();
    newnode->name = name;
    newnode->category = category;
    newnode->price = price;
    newnode->next = cur->next;
    cur->next = newnode;
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

void deletefirst()
{
    if (head != NULL)
    {
        product *temp = head;
        head = head->next;
        delete temp;
        if (head == NULL) tail = NULL;
    }
}

void deletelast()
{
    if (head == NULL) return; //When there is literally just nothing to do

    if (head == tail)
    {
        delete head;
        head = tail = NULL;
        return;
    }

    cur = head;

    while (cur->next != tail)
    {
        cur = cur->next;
    }
    
    delete tail;
    tail = cur;
    tail->next = NULL;
}

void deletemiddle(int position)
{
    if (position <= 1)
    {
        deletefirst();
        return;
    }

    cur = head;
    int idx = 1;

    while (cur != NULL && idx < position - 1) //Nyari posisi
    {
        cur = cur->next;
        idx++;
    }

    if (cur == NULL || cur->next == NULL) return; //Cek if position ada

    product *temp = cur->next;
    cur->next = temp->next;

    if (temp == tail) tail = cur; //If deleting the last node, update tailnya

    delete temp;
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