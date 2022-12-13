#include <iostream>
#include <climits>
using namespace std;
int sUsers = 0; //单词数量
string words[1000];
int minDistance(string a, string b);
int main()
{
    do  //输入一行多个单词（字符串）
    {
        cin >> words[sUsers];
        sUsers++;
    } while (getchar() != '\n'); // getchar可读掉空格，顺便用来判断换行以结束
    string a, b;
    cin >> a >> b;
    cout << minDistance(a, b); //调用函数，a,b作为参数
    return 0;
}
int minDistance(string a, string b)
{
    int min = INT_MAX; //记录最小距离
    for (int i = 0; i < sUsers; i++)
        for (int j = 0; j < sUsers; j++)                                 //两个循环分别用来找a和b
            if (words[i] == a && words[j] == b && abs(j - i) < min) //寻找a,b，abs是绝对值，防止b前a后的情况
                min = abs(j - i);                                   //小过最小就取最小
    return min;
}