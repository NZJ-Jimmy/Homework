#include <iostream>
using namespace std;
int sUsers, a = 0; // a种上楼梯方式，n级楼梯。
inline void go(int step)
{
    if (step == sUsers)
        a++;    //到了楼梯顶就累积a
    if (step >= sUsers)
        return; //无论到顶还是过顶，都得作为递归结束的终点
    go(step + 1);   //走1步
    go(step + 2);   //走2步
}
int main()
{
    cin >> sUsers;
    go(0);  //从第0级开始走
    cout << a;
    return 0;
}