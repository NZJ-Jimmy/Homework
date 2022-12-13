# 2022级《高级语言程序设计》第2次作业

## 第1题

定义一个整型数组（数组大小不超过100）以接受用户的无序数字输入，再定义一个指针``p``指向该数组，通过指针``p``的操纵将数组排好序输出，同时需要输出排好序后的数组中排在中间位置的数字的值和其地址。

### 输入输出

#### 输入

```text
3 3 7 9 5 7 9 2 3
```

#### 输出

```text
排好序后的数组是：2 3 3 3 5 7 7 9 9
排好序后的数组中间值是：5（如果数组元素个数是双数则输出第n/2位的值，n是数组元素个数）
中间值的地址是：00EFFA78
```

### 解题思路

1. **输入**：利用``while``搭配``getchar``进行没有结束标识符的一行一串数字输入
2. **数组**：使用``new``与指针搭配创建数组
3. **排序**：利用``sort``函数进行排序

### 源代码

```cpp
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int *p = new int[100]; // 用new定义数组
    int i = 0;
    do //输入一行多个数字
    {
        cin >> p[i];
        i++;
    } while (getchar() != '\n'); // getchar可读掉空格，顺便用来判断换行以结束
    sort(p, p + i);              // algorithm库的sort排序：sort(首地址，尾地址)
    cout << "排好序后的数组是：";
    for (int j = 0; j < i; j++)
        cout << p[j] << ' ';
    cout << endl
         << "排好序后的数组中间值是：" << p[i / 2] << endl; //输出值
    cout << "中间值的地址是：" << p + i / 2;                //输出地址
    delete[] p;
    return 0;
}
```

### 程序运行

```sh
> 1 1 4 5 1 4
排好序后的数组是：1 1 1 4 4 5 
排好序后的数组中间值是：4
中间值的地址是：0xd6194c
```

## 第2题

定义一个字符串数组，用以接受用户输入的英文单词列表（单词数不少于十个），随后再接受另外两个单词的输入（这两个单词必须是包含在前面的单词列表里面的单词），随后判断这两个单词在字符串数组中的最短距离，要求使用函数调用实现。

### 输入输出

#### 输入

```text
I am a Chinese I come from china and I am a college student
am Chinese
```

#### 输出

```text
2
```

### 解题思路

1. **输入**：借助第1题的思路，输入一行多个单词
2. **函数体**：用2个``for``循环分别找2个单词，比较得到最小距离
*虽然明显效率慢，但只是想程序简单一点😂*

### 源代码

```cpp
#include <iostream>
#include <climits>
using namespace std;
int n = 0; //单词数量
string words[1000];
int minDistance(string a, string b);
int main()
{
    do  //输入一行多个单词（字符串）
    {
        cin >> words[n];
        n++;
    } while (getchar() != '\n'); // getchar可读掉空格，顺便用来判断换行以结束
    string a, b;
    cin >> a >> b;
    cout << minDistance(a, b); //调用函数，a,b作为参数
    return 0;
}
int minDistance(string a, string b)
{
    int min = INT_MAX; //记录最小距离
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)                                 //两个循环分别用来找a和b
            if (words[i] == a && words[j] == b && abs(j - i) < min) //寻找a,b，abs是绝对值，防止b前a后的情况
                min = abs(j - i);                                   //小过最小就取最小
    return min;
}
```

### 程序运行

```sh
> Hello everyone, I am KUN, a personal trainee who has practiced lasting two and a half years. I like singing, dancing, rap, and basketball. Music
> I and
4
```

## 第3题（1）

用递归的方法将数组元素逆置然后输出

### 输入输出

#### 输入

*一个数组*

#### 输出

*逆置数组*

### 解题思路

1. **输入**：沿用祖传输入一行一串数字的方法
2. **递归体**：利用**左右对称**的方法，把从**前后**一对递归**执行交换**，往中间**逼近**，直到**到达中间结束递归**，从而实现逆序

### 源代码

```cpp
#include <iostream>
using namespace std;
int num[100];
int n = 0;
void reverse(int a, int b) // a,b为首、末位，采用镜像反转的方式
{
    swap(num[a], num[b]); //交换位置
    if (a == (n - 1) / 2) //停止条件：到了最中间的一对（或一个数字）
        return;
    reverse(a + 1, b - 1); //对下一对的首末数字进行交换
}
int main()
{
    do // 输入一行多个数字
    {
        cin >> num[n];
        n++;
    } while (getchar() != '\n'); // getchar可读掉空格，顺便用来判断换行以结束
    reverse(0, n - 1);           //从数组的首、末元素开始反转
    for (int i = 0; i < n; i++)
        cout << num[i] << ' ';
    return 0;
}
```

### 程序运行

```sh
> 1 1 4 5 1 4
4 1 5 4 1 1 
```

## 第3题（2）

小明想要走上一个一共有``n``级阶梯的楼梯，每次只能上一级或者两级，问小明一共有多少种上楼梯的方式？（用递归方法实现）

### 输入输出

#### 输入

*数字``n``，代表共有``n``级楼梯。*

#### 输出

*数字``a``，代表有``a``种上楼梯方式。*

### 解题思路

同样是利用**递归**，在递归体中上一步和两步，到了楼梯顶计数器``a``累加，**结束条件**是到了或过了楼梯顶。

### 源代码

```cpp
#include <iostream>
using namespace std;
int n, a = 0; // a种上楼梯方式，n级楼梯。
void go(int step)
{
    if (step == n)
        a++;    //到了楼梯顶就累积a
    if (step >= n)
        return; //无论到顶还是过顶，都得作为递归结束的终点
    go(step + 1);   //走1步
    go(step + 2);   //走2步
}
int main()
{
    cin >> n;
    go(0);  //从第0级开始走
    cout << a;
    return 0;
}
```

### 程序运行

```sh
> 4
5
```
