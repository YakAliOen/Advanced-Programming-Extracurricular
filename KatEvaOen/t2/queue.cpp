#include <iostream>
using namespace std;

//function u maks array
int maksarray = 5, front = 0, back = 0, number = 0;
string anmcd[5];

//function u data penuh/kosong
bool isfull(){
    if(back == maksarray){
        return true;
    }else{
        return false;
    }
}

bool isempty(){
    if(back == 0){
        return true;
    }else{
        return false;
    }
}

//function u entry data
void enqueuearray(string data){
    if(isfull()){
        cout<<"Data is already full, no space available"<<endl;
    }else{
        if(isempty()){
            anmcd[0] = data; //u data antrian pertama
            front++;
            back++;
        }else{
            anmcd[back] = data;
            back++;
        }
    }
}

//function u delete data
void dequeue(){
    if(isempty()){
        cout<<"Data is empty"<<endl;
    }else{
        anmcd[0] = anmcd[1];
        //isempty = delete the first data, which is at 0, and the second, which is at 1 will replace 0
        anmcd[1] = anmcd[2];
        anmcd[2] = anmcd[3];
        anmcd[3] = anmcd[4];
        anmcd[4] = " ";
    }
}

//function count
int count(){
    if(isempty()){
        return 0;
    }else if(isfull()){
        return maksarray;
    }else{
        return back;
    }
}

//function u viewdata
void view(){
    cout<<"Data Antrian MCD"<<endl;
    //buat for loop u output
    for(int i = 0; i < maksarray; i++){
        if(anmcd[i] !=" "){
            cout<< i + 1 <<"."<< anmcd [i]<<endl;
        }else{
            cout<< i + 1 <<". "<<endl;  
        }
    }
}

void destroy(){
    cout<<"DESTROY"<<endl;
    if(){
        cout<<
    }else{
        
    }
}

int main(){
    string nama;
    int jumlah;

    cout<<"Number of people: "<< maksarray <<endl;
    cin >> jumlah;
    cin.ignore(); //delete new line in buffer

    cout<< jumlah << "Input Nama: "<<endl;
    cin >> nama;

    if(jumlah > maksarray){
        cout<<"Out of capacity!"<<endl;
        jumlah = maksarray;
    }

    for(int i = 0; i < jumlah; i++){
        cout<<"Masukkan nama pelanggan ke-"<< i + 1 <<" ";
        getline(cin, nama);
        enqueuearray(nama);
    }
    
    enqueuearray(name);
    view();

    dequeue();
    view();

    cout<<"Jumlah antrian MCD: "<< count() <<endl;
    return 0;
}