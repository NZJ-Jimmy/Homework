#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int *p = new int[100]; // 用new定义数组
    int i = 0;
    do //输入一行多个数字
    {
        cin >> p[i];
        i++;
    } while (getchar() != '\n'); // getchar可读掉空格，顺便用来判断换行以结束
    sort(p, p + i);              // algorithm库的sort排序：sort(首地址，尾地址)
    cout << "排好序后的数组是：";
    for (int j = 0; j < i; j++)
        cout << p[j] << ' ';
    cout << endl
         << "排好序后的数组中间值是：" << p[i / 2] << endl; //输出值
    cout << "中间值的地址是：" << p + i / 2;                //输出地址
    delete[] p;
    return 0;
}