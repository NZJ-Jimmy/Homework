#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int max=INT_MIN,n; //使max最小
    do
    {
        cin>>n;
        if (n>max) max=n; //通过比较找到最大值
    } while (n!=0); //n等于0时跳出循环
    cout<<max;
    return 0;
}