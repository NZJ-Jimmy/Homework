#include <iostream>
using namespace std;
int num[100];
int sUsers = 0;
void reverse(int a, int b) // a,b为首、末位，采用镜像反转的方式
{
    swap(num[a], num[b]); //交换位置
    if (a == (sUsers - 1) / 2) //停止条件：到了最中间的一对（或一个数字）
        return;
    reverse(a + 1, b - 1); //对下一对的首末数字进行交换
}
int main()
{
    do // 输入一行多个数字
    {
        cin >> num[sUsers];
        sUsers++;
    } while (getchar() != '\n'); // getchar可读掉空格，顺便用来判断换行以结束
    reverse(0, sUsers - 1);           //从数组的首、末元素开始反转
    for (int i = 0; i < sUsers; i++)
        cout << num[i] << ' ';
    return 0;
}