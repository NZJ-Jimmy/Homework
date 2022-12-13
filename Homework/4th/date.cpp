#include <iostream>
#include "date.h"
using namespace std;
int main()
{
    while (1)
    {
        Date a, b; // a是当前日期，b是用于比较的日期
        cout << "Please set a date. (YYYY MM DD)" << endl;
        cin >> a; // 因为重载了>>，所以可以直接输入
        while (1)
        {
            cout << "Current Day:" << a << endl; // 因为重载了<<，所以可以直接带格式输出日期
            cout << "Please select an action:" << endl;
            cout << "r. Reset the date." << endl;
            cout << "c. Calculate with another date." << endl;
            cout << "s. Show current date." << endl;
            cout << "t. How many days from 1/1/1 to now?" << endl;
            cout << "y. Show current year." << endl;
            cout << "m. Show current month." << endl;
            cout << "d. Show current day." << endl;
            cout << "x. Exit." << endl;
            char cmd;
            cin >> cmd; // 输入指令
            switch (cmd)
            {
            case 'r':
                cout << "Please set a date. (YYYY MM DD)" << endl;
                cin >> a; // 因为重载了>>，所以可以直接输入
                break;
            case 'c':
                cout << "Please Enter the date you want to calculate. (YYYY MM DD)" << endl;
                cin >> b; // 因为重载了>>，所以可以直接输入
                cout << "There are " << abs(b - a) << " day(s) between " << a << " and " << b << endl;
                // 因为重载了-，所以可以直接计算日期的相距；但一般为正，所以取绝对值。
                break;
            case 's':
                cout << (string)a << endl; // 运用转换函数转为string，带格式输出日期
                break;
            case 't':
                cout << (int)a << endl; // 运用转换函数转为int，输出日期值
                break;
            case 'y':
                cout << a.getYear() << endl; // 调用成员函数，输出年份
                break;
            case 'm':
                cout << a.getMonth() << endl; // 调用成员函数，输出月份
                break;
            case 'd':
                cout << a.getDay() << endl; // 调用成员函数，输出日
                break;
            case 'x':
                cout << "Releasing RAM." << endl; // 退出程序，自动调用析构函数。
                return 0;
            case '\n':
                break;
            default:
                cout << "Incorrect input, try again!" << endl; // 输入错误提示。
                break;
            }
        }
    }
    return 0;
}