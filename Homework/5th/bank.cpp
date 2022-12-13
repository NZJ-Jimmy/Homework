#include "bank.h"
#include <iostream>
using namespace std;
int main()
{
    bank bank1((char*)"Ho-Lay", 600);     // 构造 我的银行账户
    bank bank2((char*)"Hak-Tsing", 5000); // 构造 朋友的银行账户
    bank bank3 = bank2;            // 拷贝构造函数，公司的账户 
    bank3.resetName((char*)"Mai-Hayau");  // company叫Mai-Hayau

    transfer(bank1, bank3, 648); // 调用成员函数转账，会余额不足
    transfer(bank2, bank1, 50);  // mate vivo 50
    transfer(bank1, bank3, 648); // 再课648，成功
    transfer(bank3, bank1, 324); // 首充半价返现

    cout << endl;
    bank1.showStatus(); // 调用成员函数，看看各自的状态与转账记录
    bank2.showStatus();
    bank3.showStatus();
    return 0;
}
