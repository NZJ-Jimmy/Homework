#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    string n;
    cin>>n;
    cout<<"正序：";
    for (int i=0;i<n.length();i++)//正序
        cout<<n[i]<<' ';//每位输出
    cout<<endl;
    cout<<"逆序：";
    for (int i=n.length()-1;i>=0;i--)//逆序
        cout<<n[i]<<' ';//每位输出
    return 0;
}