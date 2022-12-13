# 2022级《高级语言程序设计》第一次作业

## 第1题

从键盘输入数字，直到输入``0``结束，输出这些数字中最大的那个数，如果有重复的最大数，输出最后输入的那个数即可。

| 输入                           | 输出   |
| ------------------------------ | ------ |
| ``2  34  1  67  87  9  87  0`` | ``87`` |

#### 解题思路

不断输入一个数，在输入的**同时**比较得**最大值**，最终读到0时**跳出循环**，并输出最大值。

#### 源代码

```cpp
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
```

#### 程序运行
输入：
```
1353135
1313
131
3
0
```
输出：

```
1353135
```


## 第2题

输入一个正整数，将各位数字分别正序、逆序输出。

| 输入     | 输出                                                |
| -------- | --------------------------------------------------- |
| ``4356`` | ``正序：4   3   5  6``<br />``逆序：6   5   3  4 `` |

#### 解题思路

要把数字每位拆分，可以利用**字符串**，再用**循环**实现正向与逆向输出。

#### 源代码

```cpp
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
```

#### 程序运行
输入：
```
114514
```
输出：
```
正序：1 1 4 5 1 4 
逆序：4 1 5 4 1 1 
```
## 第3题

编写一个程序，它使用一个char数组和循环来每次读取一个单词，直到用户输入done为止。随后，该程序指出用户输入了多少个单词（不包括done在内）。下面是该程序的运行情况：

```
Enter words (to stop, type the word done):
> anteater birthday category dumpster
> envy finagle geometry done for sure
You entered a total of 7 words.
```

#### 解题思路

用``cin``循环读入单词（自动以空格间隔），再把 ``s``作为**计数器**边读边加，最终识别到 ``done``**结束循环**，输出 ``s``。

#### 源代码

```cpp
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char word[100];
    int s=0;
    cout<<"Enter words (to stop, type the word done):";
    do
    {
        cin>>word;
        s++;    //加计数器
    } while (strcmp(word,"done"));
    cout<<"You entered a total of "<<--s<<" words."; //s-1消去最后的done一词
    return 0;
}
```

#### 程序输入
输入：
```
Sing, Dance, Rap, Basketball, done Music!
```
输出：
```
You entered a total of 4 words.
```

## 第4题

键盘输入一串只包含小写字母的字符串，请找到第一个仅出现一次的字符。如果没有，输出``no``.

| 输入       | 输出   |
| ---------- | ------ |
| ``abcabd`` | ``c``  |
| ``aabbcd`` | ``c``  |
| ``aabb``   | ``no`` |

#### 解题思路

由于输入只有小写字母，可以用一个**数组**存放每个字母出现的次数，最终检查数组中1的字母，直接输出并结束程序，找不到再输出 ``no``

#### 源代码

```cpp
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
```

#### 程序运行
输入：
```
professional
```
输出：
```
p
```

## 第5题

设计一个名为``car``的结构，用它存储下述有关汽车的信息：生产商（存储在字符数组或 ``string``对象中的字符串）、生产年份（整数）。编写一个程序，向用户询问有多少辆汽车。随后，程序使用 ``new``来创建一个由相应数量的 ``car``结构组成的动态数组。接下来，程序提示用户输入每辆车的生产商（可能由多个单词组成）和年份信息。请注意，这需要特别小心，因为它将交替读取数值和字符串。最后，程序将显示每个结构的内容。该程序的运行情况如下：

```
How many cars do you wish to catalog?  > 2
Car #1:
Please enter the make: > Hudson Hornet
Please enter the year made: > 1952
Car #2:
Please enter the make: > Kaiser
Please enter the year made: > 1951
Here is your collection:
1952 Hudson Hornet
1951 Kaiser
```

#### 解题思路

用``new``创建一个 ``n``，输入 ``n``后再开辟一个**结构体** **动态数组**，用于存放车辆信息。

#### 源代码

```cpp
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
```

#### 程序运行：
```
How many cars do you wish to catalog?> 2
Car #1:
Please enter the make: > Hikari
Please enter the year made: > 616
Car #2:
Please enter the make: > Tairitsu
Please enter the year made: > -1  
Here is your collection:        
616 Hikari      
-1 Tairitsu 
```

## 第6题

    从键盘输入若干行英文句子，自定义输入的结束方式；按句子的长度从短到长，输出已输入的各句子。（要求分别实现两个不同的版本：（1）使用C风格的字符串，即``char``数组或 ``char*``; （2）使用C++风格的字符串，即 ``string``对象）

### 1.  使用C风格

#### 解题思路

    利用循环读入每行到**字符二维数组**（直到 ``\end``结束），再通过**冒泡排序**排好。最后输出。

#### 源代码

```cpp
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
```

### 2. 使用C++风格

#### 解题思路

    通过循环读入每行到**字符串数组**（``\end``结束），然后用 ``sort``进行**排序**~~（尝鲜）~~，最后输出。

#### 源代码

```cpp
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
```

#### 程序运行：
输入：
```
a      
quick brown fox
run over
a 
lazy dog
\end
```
输出：
```
a
a
run over
lazy dog
quick brown fox
```