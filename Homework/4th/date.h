#include <iostream>
using namespace std;
class Date
{
private:
   int year = 0, month = 0, day = 0;

public:
   Date(int y = 0, int m = 0, int d = 0);            // 构造函数，默认初始化为0
   ~Date();                                          // 析构函数
   operator int() { return countDay(); }             // 转换类型，返回int日期值
   operator string()                                 // 转换类型，返回string日期格式(Yyyy/Mm/Dd)
      { return to_string(year) + '/' + to_string(month) + '/' + to_string(day); } 
   int getYear() { return year; }                    // 获取年
   int getMonth() { return month; }                  // 获取月
   int getDay() { return day; }                      // 获取日
   int countDay();                                   // 用于计算此日期是从1年1月1日到现在第几天
   int operator-(Date &b);                           // 重载-，用于计算两个日期之差
   friend ostream &operator<<(ostream &os, Date &a); // 重载输出
   friend istream &operator>>(istream &is, Date &a); // 重载输入
};

Date::Date(int y, int m, int d)  //构造函数，用于简单地初始化
{
   year = y, month = m, day = d;
}

Date::~Date()  //析构函数，显示释放内存的信息
{
   cout << year << '/' << month << '/' << day << " has been released" << endl;
}

//之前的“某年某月1日是星期几”重新拿来用了，稍微改动一下。
bool leapYear(int y) 
{
   if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
      return 1;
   return 0;
}

int Date::countDay()
{
   int sumdays = day;
   for (int i = 1; i < year; i++) // 计算1~前一年一共有多少天
      sumdays += leapYear(i) ? 366 : 365;

   for (int i = 1; i < month; i++) // 计算最后一年有多少天，不需要计算最后一个月
   {
      switch (i)
      {
      case 1:case 3:case 5:case 7:case 8:case 10:case 12:
         sumdays += 31;
         break;
      case 2:
         sumdays += 28 + leapYear(year);
         break;
      default:
         sumdays += 30;
         break;
      }
   }
   return sumdays;
}

ostream &operator<<(ostream &os, Date &a) //输出日期（Yyyy/Mm/Dd）
{
   os << a.getYear() << '/' << a.getMonth() << '/' << a.getDay();
   return os;
}

istream &operator>>(istream &is, Date &a) //输入日期
{
   is >> a.year >> a.month >> a.day;
   return is;
}
int Date::operator-(Date &b)  //重载减号，计算两日期之距
{
   return countDay() - b.countDay();   //运用当前天-指定天，算出相差的天数
}