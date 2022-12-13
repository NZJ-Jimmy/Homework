# 2022级《高级语言程序设计》第4次作业

## 第1题

定义一个日期类``Date``，该类对象存放一个日期，可以提供的操作有：**提取日期**（年月日）值，**提取年份**，**提取月份**，**提取日期**，并能够计算两个日期相差多少天。要求提供**构造函数**、**析构函数**、**重载减法**(``-``)**运算符**（用于计算两个日期相差多少天）、**提取运算符** ``>>``和**插入运算符**``<<``。编写主程序使用这个``Date``类。

### 解题思路
1. 按照一般的类的写法来定义题目要求的各种函数
2. 计算2个日期相差的天数，可以通过分别计算他们各自从1年1月1日到现在有多少天，然后相减，就能实现了。

### 源代码

#### 头文件``date.h``

```cpp
#include <iostream>
using namespace std;
class Date
{
private:
   int year = 0, month = 0, day = 0;

public:
   Date(int y = 0, int m = 0, int d = 0);            // 构造函数，默认初始化为0
   ~Date();                                          // 析构函数
   operator int() { return countDay(); }             // 转换类型，返回int日期值
   operator string()                                 // 转换类型，返回string日期格式(Yyyy/Mm/Dd)
      { return to_string(year) + '/' + to_string(month) + '/' + to_string(day); } 
   int getYear() { return year; }                    // 获取年
   int getMonth() { return month; }                  // 获取月
   int getDay() { return day; }                      // 获取日
   int countDay();                                   // 用于计算此日期是从1年1月1日到现在第几天
   int operator-(Date &b);                           // 重载-，用于计算两个日期之差
   friend ostream &operator<<(ostream &os, Date &a); // 重载输出
   friend istream &operator>>(istream &is, Date &a); // 重载输入
};

Date::Date(int y, int m, int d)  //构造函数，用于简单地初始化
{
   year = y, month = m, day = d;
}

Date::~Date()  //析构函数，显示释放内存的信息
{
   cout << year << '/' << month << '/' << day << " has been released" << endl;
}

//之前的“某年某月1日是星期几”重新拿来用了，稍微改动一下。
bool leapYear(int y) 
{
   if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
      return 1;
   return 0;
}

int Date::countDay()
{
   int sumdays = day;
   for (int i = 1; i < year; i++) // 计算1~前一年一共有多少天
      sumdays += leapYear(i) ? 366 : 365;

   for (int i = 1; i < month; i++) // 计算最后一年有多少天，不需要计算最后一个月
   {
      switch (i)
      {
      case 1:case 3:case 5:case 7:case 8:case 10:case 12:
         sumdays += 31;
         break;
      case 2:
         sumdays += 28 + leapYear(year);
         break;
      default:
         sumdays += 30;
         break;
      }
   }
   return sumdays;
}

ostream &operator<<(ostream &os, Date &a) //输出日期（Yyyy/Mm/Dd）
{
   os << a.getYear() << '/' << a.getMonth() << '/' << a.getDay();
   return os;
}

istream &operator>>(istream &is, Date &a) //输入日期
{
   is >> a.year >> a.month >> a.day;
   return is;
}
int Date::operator-(Date &b)  //重载减号，计算两日期之距
{
   return countDay() - b.countDay();   //运用当前天-指定天，算出相差的天数
}
```

#### 主程序 ``date.cpp``

```cpp
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
```

#### 运行结果（功能过多，不逐一展示）
```
Please set a date. (YYYY MM DD)
> 1949 10 1
Current Day:1949/10/1
Please select an action:
r. Reset the date.
c. Calculate with another date.
s. Show current date.
t. How many days from 1/1/1 to now?       
y. Show current year.
m. Show current month.
d. Show current day.
x. Exit.
> c
Please Enter the date you want to calculate. (YYYY MM DD)
> 2022 10 1
There are 26663 day(s) between 1949/10/1 and 2022/10/1
Current Day:1949/10/1
Please select an action:
r. Reset the date.
c. Calculate with another date.
s. Show current date.
t. How many days from 1/1/1 to now?       
y. Show current year.
m. Show current month.
d. Show current day.
x. Exit.
> t
711766
Current Day:1949/10/1
Please select an action:
r. Reset the date.
c. Calculate with another date.
s. Show current date.
t. How many days from 1/1/1 to now?       
y. Show current year.
m. Show current month.
d. Show current day.
x. Exit.
> x
Releasing RAM.
2022/10/1 has been released
1949/10/1 has been released
```

## 第2题

编写面向对象程序。自己设计一个地址簿（类``AddressBook``，和主程序），功能自定义（具备输入、输出、查找、排序等功能），至少需要有输入、输出（需重载提取运算符 ``>>``和插入运算符``<<``）和查找功能。程序要求记录联系人的姓名，地址，电话号码，生日等信息。数据成员至少有一个是指针类型，如姓名或地址是``char *``类型。必须在类中定义和实现构造函数和析构函数；并在主程序中使用上这些函数。

### 解题思路

1. 按照题目定义各种函数
2. 要求用指针类型，那就麻烦点用``char*``（~~真的很麻烦~~）
3. 输入没办法了，如果重载``>>``，那就不能录到空格了，用``getline``的话重载``>>``就没用了……
4. 生日就不做输入检测了，不然重载``>>``就没用了……

### 源代码

#### 头文件``AddressBook.h``
```cpp
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
class AddressBook
{
private:
    int n = 0;     // 用于记录当前存书量，初始化为0
    struct Address // 用于存储每个地址的结构体
    {
        char *name, *address, *phone, *birthday;
    } adrs[100];

public:
    AddressBook() {}                                                     // 保留空的构造函数，方便定义AddressBook
    AddressBook(char *name, char *address, char *phone, char *birthday); // 可用于初始化的构造函数
    ~AddressBook();                                                      // 析构函数
    friend istream &operator>>(istream &is, AddressBook &a);             // 重载>>，用于输入（新建联系人）
    friend ostream &operator<<(ostream &os, const AddressBook &a);       // 重载<<，用于输出整个地址簿
    void rank();                                                         // 按名字排序（次关键字为手机号）
    AddressBook search(char *str);                                       // 成员函数，搜索
    operator int() { return n; }                                         // 转换int类型函数，返回地址簿的联系人个数
};

void charaddcpy(char *&dest, char *source) // 此函数用于快速拷贝字符串到一个新开辟的地址
{
    char *t = new char[strlen(source)];
    strcpy(t, source);
    dest = t;
}

AddressBook::AddressBook(char *name, char *address, char *phone, char *birthday) // 构造函数，初始化
{
    charaddcpy(adrs[n].name, name);
    charaddcpy(adrs[n].address, address);
    charaddcpy(adrs[n].phone, phone);
    charaddcpy(adrs[n].birthday, birthday);
    n++; // 增加存书量n
}

istream &operator>>(istream &is, AddressBook &a)
{
    char *name = new char[100]; // 用new开辟内存段
    char *address = new char[100];
    char *phone = new char[100];
    char *birthday = new char[100];
    is >> name >> address >> phone >> birthday;
    a.adrs[a.n].name = name; // 把地址赋值过去
    a.adrs[a.n].address = address;
    a.adrs[a.n].phone = phone;
    a.adrs[a.n].birthday = birthday;
    a.n++; // 增加存书量n
    return is;
}

ostream &operator<<(ostream &os, const AddressBook &a)
{
    if (a.n == 0)
        os << "Eh... Nothing here." << endl; // 特殊情况：1.地址簿无地址；2.查找时找不到联系人
    else
        for (int i = 0; i < a.n; i++)
        {
            os << "Name: " << a.adrs[i].name << endl
               << "Address: " << a.adrs[i].address << endl
               << "Phone: " << a.adrs[i].phone << endl
               << "Birthday: " << a.adrs[i].birthday << endl
               << endl;
        }
    return os;
}

AddressBook::~AddressBook() // 析构函数：显示联系人簿已被删除
{
    cout << "The Address Book has been deleted." << endl;
}

void AddressBook::rank() // 冒泡排序：以姓名排序，若同名则以手机号排序
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (strcmp(adrs[i].name, adrs[j].name) > 0 || strcmp(adrs[i].address, adrs[j].address) == 0 && strcmp(adrs[i].phone, adrs[j].phone) > 0)
                swap(adrs[i], adrs[j]);
}

AddressBook AddressBook::search(char *str) // 搜索关键字
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(adrs[i].name, str) == 0)
            return AddressBook(adrs[i].name, adrs[i].address, adrs[i].phone, adrs[i].birthday);
    }                     // 搜索到直接返回一个地址簿类型的结果
    return AddressBook(); // 找不到就直接返回一个空的地址簿。
}
```

#### 主程序 ``AddressBook.cpp``

```cpp
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
```

### 运行结果

```
Please select an action.
1. Add a new contact.
2. Show all contacts.
3. Search a contact.
4. Rank the Address Book by name.
x. Exit.
> 1
Please enter the NAME ADDRESS PHONE BIRTHDAY
CAUTION: Every Field should not contain SPACE, because the fields split by SPACEs.  
> China Asia +86 1949
Please select an action.
1. Add a new contact.
2. Show all contacts.
3. Search a contact.
4. Rank the Address Book by name.
x. Exit.
> 1
Please enter the NAME ADDRESS PHONE BIRTHDAY
CAUTION: Every Field should not contain SPACE, because the fields split by SPACEs.  
> US America +1 1776
Please select an action.
1. Add a new contact.
2. Show all contacts.
3. Search a contact.
4. Rank the Address Book by name.
x. Exit.
> 2
Name: China
Address: Asia
Phone: +86
Birthday: 1949

Name: US
Address: America
Phone: +1
Birthday: 1776

Please select an action.
1. Add a new contact.
2. Show all contacts.
3. Search a contact.
4. Rank the Address Book by name.
x. Exit.
> 3
Input the name you want to search.        
> China
Name: China
Address: Asia
Phone: +86
Birthday: 1949

The Address Book has been deleted.        
Please select an action.
1. Add a new contact.
2. Show all contacts.
3. Search a contact.
4. Rank the Address Book by name.
x. Exit.
> 3
Input the name you want to search.        
> Japan
Eh... Nothing here.
The Address Book has been deleted.        
Please select an action.
1. Add a new contact.
2. Show all contacts.
3. Search a contact.
4. Rank the Address Book by name.
x. Exit.
> 4
Rank done. Here is the result.
Name: China
Address: Asia
Phone: +86
Birthday: 1949

Name: US
Address: America
Phone: +1
Birthday: 1776

Please select an action.
1. Add a new contact.
2. Show all contacts.
3. Search a contact.
4. Rank the Address Book by name.
x. Exit.
> x
The Address Book has been deleted. 
```