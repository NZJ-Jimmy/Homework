#include <iostream>
#include "Elevator00.h"
using namespace std;
int main()
{
    Elevator a;  //定义
    while (true) //操作列表
    {
        cout << "Please select the action below:" << endl;
        cout << "1. Display the current floor." << endl;
        cout << "2. Go to the specific floor." << endl;
        cout << "3. Exit" << endl;
        int act;
        cin >> act;
        switch (act)
        {
        case 1:
            a.show();
            break;
        case 2:
            int fl;
            cout << "Which floor do you want to go?";
            a.input();
            break;
        case 3:
            return 0;
        default:
            cout << "Error! Please check your input and try again!" << endl;
            break;
        }
        cout << endl;
    }
    return 0;
}