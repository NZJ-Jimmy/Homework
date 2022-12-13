#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char str[100][100]; //二维字符数组（100个长度为100的字符串）
    int n=0;            //计数器（句数）
    do
    {
        cin.getline(str[n],100);
    } while (strcmp(str[n++],"\\end")); //以"\end"退出循环
    n--;                                //减掉"\end"
    for (int i=0;i<n;i++)
        for (int j=i;j<n;j++)           //冒泡排序
            if (strlen(str[i])>strlen(str[j]))
                swap(str[i],str[j]);
    for (int i=0;i<n;i++)
        cout<<str[i]<<endl;             //输出
    return 0;
}