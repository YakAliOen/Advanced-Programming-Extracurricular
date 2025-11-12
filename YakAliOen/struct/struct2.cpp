#include <iostream>
using namespace std;

struct rapot
{
    string nama;
    int tugas;
    int quiz;
    int uts;
    int uas;
    float nilai;
    char grade;
};

float hitungNilaiAkhir(int tugas, int quiz, int uts, int uas);
char hitungGrade(float nilai);

int main()
{
    rapot r1;

    cout << "Nama: ";
    cin >> r1.nama;
    cout << "Nilai Tugas: ";
    cin >> r1.tugas;
    cout << "Nilai Quiz: ";
    cin >> r1.quiz;
    cout << "Nilai UTS: ";
    cin >> r1.uts;
    cout << "Nilai UAS: ";
    cin >> r1.uas;
    cout << endl;

    r1.nilai = hitungNilaiAkhir(r1.tugas, r1.quiz, r1.uts, r1.uas);


    cout << "Nilai: " << r1.nilai << endl;
    cout << "Grade: " << hitungGrade(r1.nilai) << endl;

    return 0;
}

float hitungNilaiAkhir(int tugas, int quiz, int uts, int uas)
{
    return (tugas * 0.1f) + (quiz * 0.2f) + (uts * 0.3f) + (uas * 0.4f);
}

char hitungGrade(float nilai)
{
    if (nilai >= 85) return 'A';
    else if (nilai >= 70) return 'B';
    else if (nilai >= 60) return 'C';
    else if (nilai >= 50) return 'D';
    else return 'E';
}