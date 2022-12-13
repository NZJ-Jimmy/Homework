#include <iostream>
#include "AddressBook.h"
using namespace std;
int main()
{
    AddressBook book;
    while (1)
    {
        cout << "Please select an action." << endl; // 功能选单
        cout << "1. Add a new contact." << endl;
        cout << "2. Show all contacts." << endl;
        cout << "3. Search a contact." << endl;
        cout << "4. Rank the Address Book by name." << endl;
        cout << "x. Exit." << endl;
        char cmd;
        cin >> cmd; // 输入指令
        switch (cmd)
        {
        case '1':
            cout << "Please enter the NAME ADDRESS PHONE BIRTHDAY" << endl;
            cout << "CAUTION: Every Field should not contain SPACE, because the fields split by SPACEs." << endl;
            cin >> book; // 调用重载>>，添加到地址簿
            break;
        case '2':
            cout << book; // 调用重载<<，输出整个地址簿
            break;
        case '3':
            char srch[100];
            cout << "Input the name you want to search." << endl;
            cin >> srch;               // 输入要查找的字段
            cout << book.search(srch); // 调用函数查找，并调用重载<<，输出查找结果
            break;
        case '4':
            book.rank(); // 调用rank函数
            cout << "Rank done. Here is the result." << endl;
            cout << book; // 直接输出地址簿
            break;
        case 'x':
            return 0; // 退出程序
        }
    }

    return 0;
}