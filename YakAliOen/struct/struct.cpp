#include <iostream>
using namespace std;

struct student
{
    string Name;
    int NIS;
    int NISN;
    string DOB;
    string Sex;
    string Valid_Until;
};

int main()
{
    student s;
    cout << "Enter name: ";
    cin >> s.Name;

    cout << "Enter NIS: ";
    cin >> s.NIS;

    cout << "Enter NISN: ";
    cin >> s.NISN;

    cout << "Enter Date of Birth (YYYY-MM-DD): ";
    cin >> s.DOB;

    cout << "Enter Sex (M/F): ";
    cin >> s.Sex;

    cout << "Enter Valid Until (YYYY-MM-DD): ";
    cin >> s.Valid_Until;

    cout << "=============================================" << endl;
    cout << "Name: " << s.Name << endl;
    cout << "NIS: " << s.NIS << endl;
    cout << "NISN: " << s.NISN << endl;
    cout << "DOB: " << s.DOB << endl;
    cout << "Sex: " << s.Sex << endl;
    cout << "Valid Until: " << s.Valid_Until << endl;
}