#include <iostream>
#include "Person00.h"
using namespace std;

void Person::show() const
{
    cout << fname << ' ' << lname << endl;
} // firstname lastname format

void Person::FormalShow() const
{
    cout << lname;
    if (fname[0] != '\0')
        cout << ", " << fname;
    cout<< endl;
} // lastname, firstname format

int main()
{
    Person one; // use default constructor
    Person two("Smythecraft"); // use #2 with one default argument
    Person three("Dimwiddy", "Sam"); // use #2, no defaults

    one.show();
    one.FormalShow();
    cout << endl;

    two.show();
    two.FormalShow();
    cout << endl;

    three.show();
    three.FormalShow();
    cout << endl;
    return 0;
}