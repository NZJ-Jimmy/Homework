#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
class AddressBook
{
private:
    int n = 0;     // 用于记录当前存书量，初始化为0
    struct Address // 用于存储每个地址的结构体
    {
        char *name, *address, *phone, *birthday;
    } adrs[100];

public:
    AddressBook() {}                                                     // 保留空的构造函数，方便定义AddressBook
    AddressBook(char *name, char *address, char *phone, char *birthday); // 可用于初始化的构造函数
    ~AddressBook();                                                      // 析构函数
    friend istream &operator>>(istream &is, AddressBook &a);             // 重载>>，用于输入（新建联系人）
    friend ostream &operator<<(ostream &os, const AddressBook &a);       // 重载<<，用于输出整个地址簿
    void rank();                                                         // 按名字排序（次关键字为手机号）
    AddressBook search(char *str);                                       // 成员函数，搜索
    operator int() { return n; }                                         // 转换int类型函数，返回地址簿的联系人个数
};

void charaddcpy(char *&dest, char *source) // 此函数用于快速拷贝字符串到一个新开辟的地址
{
    char *t = new char[strlen(source)];
    strcpy(t, source);
    dest = t;
}

AddressBook::AddressBook(char *name, char *address, char *phone, char *birthday) // 构造函数，初始化
{
    charaddcpy(adrs[n].name, name);
    charaddcpy(adrs[n].address, address);
    charaddcpy(adrs[n].phone, phone);
    charaddcpy(adrs[n].birthday, birthday);
    n++; // 增加存书量n
}

istream &operator>>(istream &is, AddressBook &a)
{
    char *name = new char[100]; // 用new开辟内存段
    char *address = new char[100];
    char *phone = new char[100];
    char *birthday = new char[100];
    is >> name >> address >> phone >> birthday;
    a.adrs[a.n].name = name; // 把地址赋值过去
    a.adrs[a.n].address = address;
    a.adrs[a.n].phone = phone;
    a.adrs[a.n].birthday = birthday;
    a.n++; // 增加存书量n
    return is;
}

ostream &operator<<(ostream &os, const AddressBook &a)
{
    if (a.n == 0)
        os << "Eh... Nothing here." << endl; // 特殊情况：1.地址簿无地址；2.查找时找不到联系人
    else
        for (int i = 0; i < a.n; i++)
        {
            os << "Name: " << a.adrs[i].name << endl
               << "Address: " << a.adrs[i].address << endl
               << "Phone: " << a.adrs[i].phone << endl
               << "Birthday: " << a.adrs[i].birthday << endl
               << endl;
        }
    return os;
}

AddressBook::~AddressBook() // 析构函数：显示联系人簿已被删除
{
    cout << "The Address Book has been deleted." << endl;
}

void AddressBook::rank() // 冒泡排序：以姓名排序，若同名则以手机号排序
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (strcmp(adrs[i].name, adrs[j].name) > 0 || strcmp(adrs[i].address, adrs[j].address) == 0 && strcmp(adrs[i].phone, adrs[j].phone) > 0)
                swap(adrs[i], adrs[j]);
}

AddressBook AddressBook::search(char *str) // 搜索关键字
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(adrs[i].name, str) == 0)
            return AddressBook(adrs[i].name, adrs[i].address, adrs[i].phone, adrs[i].birthday);
    }                     // 搜索到直接返回一个地址簿类型的结果
    return AddressBook(); // 找不到就直接返回一个空的地址簿。
}