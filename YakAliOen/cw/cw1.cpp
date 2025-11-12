#include <iostream>
using namespace std;

struct teacher
{
    string subject_name;
    int passing_grade;
    string teacher_name;
    int age_teacher;
};

int main()
{
    teacher t;

    cout << "Input Dengan Struct" << endl;

    cout << "Subject Name: ";
    cin >> t.subject_name;

    cout << "Passing Grade: ";
    cin >> t.passing_grade;

    cout << "Teacher Name: ";
    cin >> t.teacher_name;

    cout << "Age Teacher: ";
    cin >> t.age_teacher;

    cout << "========== Output ==========" << endl;

    cout << "Subject Name: " << t.subject_name << endl;
    cout << "Passing Grade: " << t.passing_grade << endl;
    cout << "Teacher Name: " << t.teacher_name << endl;
    cout << "Age Teacher: " << t.age_teacher << endl;
    return 0;
}