#include <iostream>
using namespace std;

struct final{
    string name;
    string nilai;
    int tugas; 
    int quiz; 
    int uts; 
    int uas; 
    int nilai_akhir;
    int total_tugas;
    int total_quiz;
    int total_uts;
    int total_uas;
};

int main(){
    final f;

    cout << "Report Card" << endl;
    cout << "Input Name: ";
    cin >> f.name;

    cout << "Input Nilai Tugas: ";
    cin >> f.tugas;

    cout << "Input Nilai Quiz: ";
    cin >> f.quiz;

    cout << "Input Nilai UTS: ";
    cin >> f.uts;

    cout << "Input Nilai UAS: ";
    cin >> f.uas;

    // Total Nilai Tugas
    f.total_tugas = f.tugas*10/100;

    // Total Nilai Quiz
    f.total_quiz = f.quiz*20/100;

    // Total Nilai UTS
    f.total_uts = f.uts*30/100;

    // Total Nilai UAS
    f.total_uas = f.uas*40/100;

    if (f.nilai_akhir >= 85){
        cout << "Nilai = A" << endl;
    }
    else if (f.nilai_akhir >= 70){
        cout << "Nilai = B" << endl;
    }
    else if (f.nilai_akhir >= 55){
        cout << "Nilai = C" << endl;
    }
    else if (f.nilai_akhir >= 40){
        cout << "Nilai = D" << endl;
    }
    else{
        cout << "Nilai = E" << endl;
    }

    f.nilai_akhir = f.total_quiz + f.total_tugas + f.total_uas + f.total_uts;

    cout << "Report Card: " << f.nilai_akhir << endl;
    cout << "=================" << endl;

    return 0;
}