#include <iostream>
using namespace std;
struct product
{
    string name, category;
    int price;
    product *next;
};
product *head, *tail, *cur, *newnode; //head: data awal, tail: data akhir

void createlinkedlist(string name, string category, int price)
{
    head = new product();
    head ->name = name;
    head ->category = category;
    head ->price = price;
    head ->next = NULL;
    tail = head;
}

void printlinkedlist()
{
    cur = head;
    while(cur != NULL)
    {
        cout << "Name: " << cur ->name << endl;
        cout << "Category: " << cur ->category << endl;
        cout << "Price: " << cur ->price << endl;
        cur = cur ->next;
    }
}

int countlinkedlist()
{
    cur = head;
    int jumlah = 0;
    while (cur !=NULL){
        jumlah++;
        cur = cur ->next;
    }
     return jumlah;
}

void addfirst(string name, string category, int price)
{
    newnode = new product();
    newnode ->name = name;
    newnode ->category = category;
    newnode ->price = price;
    newnode ->next = NULL;
    newnode ->next = head;
    head = newnode;
}

void addmiddle(string name, string category, int price, int position)
{
    if (position < 1 || position > countlinkedlist()){
        cout << "Posisi di luar jangkauan" << endl;
    }else if (position == 1){
        cout << "In addfirst" << endl;
    }else{
        newnode = new product();
        newnode ->name = name;
        newnode ->category = category;
        newnode ->price = price;

        //formula
        cur = head; //cur = current node
        int number = 1; //start from node1

        while (number < position -1){
            cur = cur ->next; //go to the next node
            number++;
        }
        newnode ->next = cur ->next; //keeping extra new node
        cur ->next = newnode;
    }
}

void addlast(string name, string category, int price)
{
    newnode = new product();
    newnode ->name = name;
    newnode ->category = category;
    newnode ->price = price;
    newnode ->next = NULL;
    tail ->next = newnode;
    tail = newnode;
}

void changefirst(string name, string category, int price)
{
    head ->name = name;
    head ->category = category;
    head ->price = price;
}

int main ()
{
    createlinkedlist ("Sony", "Furnitur", 2500000);
    printlinkedlist ();

    cout << "\n" << endl;

    addfirst ("Ultramilk 1000mL", "Susu", 25000);
    printlinkedlist ();

    cout << "\n" << endl;

    changefirst ("Mie Samyang", "Mie Instan", 25000);
    printlinkedlist ();
    
    cout << "\n" << endl;

    addmiddle ("Aqua 500mL", "Air Mineral", 5000, 2);
    printlinkedlist ();
    
    cout << "\n" << endl;

    addlast ("Ultramilk 100mL", "Susu", 2500);
    printlinkedlist ();

    cout << "\n\n" << endl;
    return 0;
}