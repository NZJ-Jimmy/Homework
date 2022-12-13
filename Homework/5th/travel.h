#include <iostream>
#include <vector>
using namespace std;
class travel
{
private:
    int length, totalCost = 0, Budget = 0;
    string Departure, Destination;
    struct object
    {
        string object;
        int price;
    };
    vector<object> cost;

public:
    travel(){}
    travel(int len, string depart, string dest, int budget);
    ~travel();
    travel& operator=(travel &source);
    friend istream &operator>>(istream &is, travel &a);
    friend ostream &operator<<(ostream &os, travel &a);
    operator bool() { return totalCost < Budget; }
};

inline travel::travel(int len, string depart, string dest, int budget)
{
    length = len;
    Departure = depart;
    Destination = dest;
    Budget = budget;
}

inline travel& travel::operator=(travel &source)
{
    length = source.length;
    Departure = source.Departure;
    Destination = source.Destination;
    Budget = source.Budget;
    totalCost = source.totalCost;
    for (int i = 0; i < source.cost.size(); i++)
        cost.push_back({source.cost[i].object, source.cost[i].price});
    return *this;
}

istream &operator>>(istream &is, travel &a)
{
    cout << "Please enter the length:";
    is >> a.length;
    is.get();
    cout << "Please enter the departure:";
    getline(is, a.Departure);
    cout << "Please enter the destination:";
    getline(is, a.Destination);
    cout << "Please enter the budget:";
    is >> a.Budget;
    int n;
    cout << "How many objects?";
    is >> n;
    is.get();
    for (int i = 0; i < n; i++)
    {
        string str;
        int num;
        cout << "Object Name #" << i + 1 << ':';
        getline(is, str);
        cout << "Object Price #" << i + 1 << ':';
        is >> num;
        is.get();
        a.cost.push_back({str, num});
        a.totalCost += num;
    }
    return is;
}

ostream &operator<<(ostream &os, travel &a)
{
    os << a.Departure << " -> " << a.Destination << "\tLength: " << a.length << endl;
    os << "Cost list:" << endl;
    for (int i = 0; i < a.cost.size(); i++)
        os << a.cost[i].object << '\t' << a.cost[i].price << endl;
    os << "Total cost: " << a.totalCost << endl;
    if (a)
        os << "Money Enough." << endl;
    else
        os << "Money not enough." << endl;
    return os;
}

travel::~travel()
{
    cout << "The travel from " << Departure << " to " << Destination << " has been deleted." << endl;
}
