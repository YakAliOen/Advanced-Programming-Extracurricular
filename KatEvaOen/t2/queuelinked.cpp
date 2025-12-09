#include <iostream>
using namespace std;

struct antrianmcd{
    string name;
    int order;

    antrianmcd *next;
};

int maxantrian = 5;
antrianmcd *head, *tail, *cur, *del, *newnode;

int countdata(){
    if(head == NULL){
        return 0;
    }else{
        int jumlah = 0;
        cur = head;
        while(cur != NULL){ //for when a data entered
            cur = cur ->next;
            jumlah++;
        }
        return jumlah;
    }
}

bool isfull(){
    if(countdata() == maxantrian){
        return true;
    }else{
        return false;
    }
}

bool isempty(){
    if(countdata() == 0){
        return true;
    }else{
        return false;
    }
}

void enq(string name, int order){
    if(isfull()){
        cout << "Data is full" <<endl;
    }else{
        if(isempty()){
            head = new antrianmcd;
            head -> name = name;
            head -> order = order;
            head -> next = NULL;
            tail = head;
        }else{
            newnode = new antrianmcd();
            newnode -> name = name;
            newnode -> order = order;
            newnode -> next = NULL;
            tail -> next = newnode;
            tail = newnode;
        }
    }
}

void display(){
    cout << "== Data Antrian MCD ==" <<endl;
    if(isempty()){
        cout << "Data is Empty" <<endl;
    }else{
        cout << "Banyak data Antrian: " <<endl;
        cur = head;
        int id = 1; //for the 1st ID
        while (id <= maxantrian){
            if (cur != NULL){
                cout << id << "." << cur -> name << "." << cur -> order <<endl;
                cur = cur ->next;
            }else{
                cout << id << "." << "Empty" <<endl;
            }
            id++;
        }
    }
}

int main(){
    enq ("Coffee", 3);
    display();

    enq ("Sandwich", 1);
    display();

    return 0;
}