# 2022级《高级语言程序设计》第3次作业

## 第1题

编写面向对象程序，模拟一个电梯的工作过程。编写一个电梯类Elevator,要求写出构造函数和析构函数并编写主函数。

### 解题思路

运用``class``实现。因为我实在没想到需要实现电梯的什么功能，所以我只编了个 “**显示当前楼层**” 和 “**前往哪个楼层**”的功能。

1. 运用``class``，创建**构造函数**（用于简单初始化）和**析构函数**（用于删除内存并提示用户电梯运行结束）
2. 创建3个**成员函数**，分别用于输入楼层``input``、显示当前楼层``show``和前往指定楼层``to``
3. 在主函数里面搭建一个功能选单，对一个``Elevator``类进行操作

### 源代码
#### 头文件 ``Elevator00.h``
```cpp
#include <iostream>
using namespace std;
class Elevator
{
private:
    int *floor = new int;

public:
    Elevator(int fl = 1) //构造函数，对楼层进行初始化，默认在1层
    {
        *floor = fl;
    }
    ~Elevator() //析构函数，清除floor内存
    {
        delete floor;
        cout << "The elevator stopped.";
    }
    void input() //要求初始化输入楼层。
    {
        int x;
        do
        {
            cin >> x;
            if (x > 15 || x < 1)
                cout << "Error, this floor does not exist. Please retry." << endl;
        } while (x > 15 || x < 1); //判断输入的楼层是否合法（在1-15内）
        to(x);
    }
    void to(int fl) //前往指定楼层并展示电梯运行状况
    {
        if (fl > *floor)
            cout << "The elevator is going up." << endl;
        if (fl < *floor)
            cout << "The elevator is going down." << endl;
        if (fl == *floor)
            cout << "You are at this floor." << endl;
        *floor = fl;
        show();
    }
    void show() //展示当前所在楼层
    {
        cout << "Current floor: " << *floor << endl;
    }
};


```

#### 主函数程序 ``1.cpp``
```cpp
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
```

### 运行结果
```
Please select the action below:
1. Display the current floor.      
2. Go to the specific floor.       
3. Exit
1
Current floor: 1

Please select the action below:    
1. Display the current floor.      
2. Go to the specific floor.       
3. Exit
2
Which floor do you want to go?-1   
Error, this floor does not exist. Please retry.
3
The elevator is going up.
Current floor: 3

Please select the action below:    
1. Display the current floor.      
2. Go to the specific floor.       
3. Exit
3
The elevator stopped.
```

## 第2题

题目过长，仅简述大意：完善所给的代码段，实现姓名的多格式输出。

### 解题思路

熟练运用class而已，成员函数的一些应用，没什么解题思路😂

### 源代码
#### 头文件 ``Person00.h``
```cpp
#include <string>
#include <cstring>
using namespace std;
class Person
{
private:
    static const int LIMIT = 25;
    string lname;      // Person’s last name
    char fname[LIMIT]; // Person’s first name
public:
    Person() { lname = "", fname[0] = '\0'; }            //#1
    
    Person(const string &ln, const char *fn = "Heyyou") //#2
    {
        lname = ln;
        for (int i = 0; i < strlen(fn); i++)
            fname[i] = fn[i];
        *fname = *fn;
    }

    // the following methods display lname and fname

    void show() const; // firstname lastname format

    void FormalShow() const; // lastname, firstname format
};
```

#### 主函数程序 ``2.cpp``
```cpp
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
```

### 运行结果
```
 


Heyyou Smythecraft
Smythecraft, Heyyou

Sam Dimwiddy
Dimwiddy, Sam

```