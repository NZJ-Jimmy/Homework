#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
bool lenCompare(string str1,string str2)    //用于比较字符串长度的函数
{
    return str1.length()<str2.length();     //返回正确的顺序
}
int main()
{
    bool lenCompare(string str1,string str2);
    string str[1000];
    int n=0;
    do
    {
        getline(cin,str[n]);
    } while (str[n++]!="\\end");    //以"\end"退出循环
    n--;                            //减掉"\end"
    sort(str,str+n,lenCompare);     //sort str数组，按条件(lenCompare)排序
    for (int i=0;i<n;i++)
        cout<<str[i]<<endl;         //输出
    return 0;
}
