#include <iostream>
#include <string.h>

using namespace std;

class Student
{
public:
    int id;
    string name;
    Student() {}
    // //copy constructor
    // Student(Student &t)
    // {
    //     this->id = t.id;
    //     this->name = t.name;
    // }
};

int main()
{
    Student s1;
    s1.id = 1;
    s1.name = "Dhanuj";
    cout << s1.id << ":" << s1.name << endl
         << endl;

    cout << "After copy: " << endl;

    Student s2(s1);
    s2.name = "harshita";

    cout << s1.id << ":" << s1.name << endl;
    cout << s2.id << ":" << s2.name << endl;

    return 0;
}