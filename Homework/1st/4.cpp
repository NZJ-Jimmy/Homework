#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int s[26]={};
    string str;
    cin>>str;
    for (int i=0;i<str.length();i++)
        s[str[i]-'a']++;        //用于统计字母数
    for (int i=0;i<str.length();i++)
        if (s[str[i]-'a']==1)   //找到等于1的s[i]
        {
            cout<<str[i];       //输出这个字母
            return 0;           //直接结束程序
        }
    cout<<"no";                 //找不到就输出no
    return 0;
}