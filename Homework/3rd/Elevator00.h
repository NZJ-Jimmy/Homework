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
        int show;
        cin >> show;
        cout << "Current floor: " << *floor << endl;
    }
};
