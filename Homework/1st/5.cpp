#include <iostream>
#include <cstring>
using namespace std;
struct car
{
    string vendor;
    int year;
};              //定义结构体

int main()
{
    int *n = new int;   //定义指针
    cout<<"How many cars do you wish to catalog?";
    cin>>*n;
    getchar();          //消掉缓冲区里的回车
    car cars[*n+1];     //创建动态数组（防止大开小用）
    for (int i=1;i<=*n;i++)
    {
        cout<<"Car #"<<i<<':'<<endl;
        cout<<"Please enter the make: ";
        getline(cin,cars[i].vendor);    //读入一整行
        cout<<"Please enter the year made: ";
        cin>>cars[i].year;
        getchar();                      //消掉缓冲区里的回车
    }
    cout<<"Here is your collection:"<<endl;
    for (int i=1;i<=*n;i++)
        cout<<cars[i].year<<' '<<cars[i].vendor<<endl;
    return 0;
}