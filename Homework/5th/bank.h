#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
class bank
{
private:
    char *Name;
    int Balance = 0;
    struct transaction
    {
        char *objectName; // 转账的来源或目标的Name，只存指针以应付改名
        int amount;       // 转账的金额
    };
    vector<transaction> record;

public:
    bank(char *name, int balance = 0); // 有参构造函数
    bank(const bank &source);          // 深拷贝构造函数
    void resetName(char *name);
    friend void transfer(bank &source, bank &target, unsigned int amount); // 用于转账
    void showStatus();
    ~bank();
    operator int() { return Balance; }
    operator char *() { return Name; }
};
inline void bank::resetName(char *name)
{
    Name = new char[strlen(name)];
    strcpy(Name, name);
}

inline bank::bank(char *name, int balance)
{
    Name = new char[strlen(name)];
    strcpy(Name, name);
    Balance = balance;
}

inline bank::bank(const bank &source)
{
    Balance = source.Balance;
    Name = new char[strlen(source.Name)];
    strcpy(Name, source.Name);
    for (int i = 0; i < source.record.size(); i++)
        record.push_back({source.record[i].objectName, source.record[i].amount}); // 考虑到可能改名的情况，在这里只作浅复制
                                                                                  // 这样的话名字只复制了指针，如果出现改名也能应付
}

inline void transfer(bank &source, bank &target, unsigned int amount)
{
    // 用unsigned是防止有出现从别人钱包拿钱的非法转账。
    if (source.Balance < amount)
        cout << "Insufficient balance." << endl;
    else
    {
        source.Balance -= amount;
        target.Balance += amount;
        source.record.push_back({target.Name, (int)-amount});
        target.record.push_back({source.Name, (int)amount});
        cout << "Successfully transfered " << amount << " from " << (char *)source << " to " << (char *)target << endl;
    }
}

inline void bank::showStatus()
{
    cout << "Here are " << Name << " 's " << record.size() << " transaction record(s):" << endl;
    for (int i = 0; i < record.size(); i++)
    {
        if (record[i].amount > 0)
            cout << record[i].objectName << " -> " << Name << "\t+" << record[i].amount << endl;
        else
            cout << Name << " -> " << record[i].objectName << "\t-" << -record[i].amount << endl;
    }
    cout << "Balance:" << Balance << endl;
}

inline bank::~bank()
{
    cout << Name << "'s bank account has been deleted." << endl;
    // delete[] Name;
}
