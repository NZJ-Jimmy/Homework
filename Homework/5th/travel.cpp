#include "travel.h"
#include <iostream>
using namespace std;
int main()
{
    travel travel1(3100, "Mung Dak", "Lei Yut", 500000), travel2, travel3;
    // cout << "Please enter the travel information." << endl
    //      << "length, departure, destination, budget, and costs" << endl
    //      << "The costs contain N — the number of the objects" << endl
    //      << "Every object contains its name and its money." << endl
    //      << "You should split every field by ENTER." << endl;
    cin >> travel2;
    travel3 = travel2;
    cout << travel1;
    cout << travel3;
    return 0;
}
