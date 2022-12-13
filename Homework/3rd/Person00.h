#include <string>
#include <cstring>
using namespace std;
class Person
{
private:
    static const int LIMIT = 25;
    string lname;      // Person’s last name
    char fname[LIMIT]; // Person’s first name
public:
    Person() { lname = "", fname[0] = '\0'; }            //#1
    
    Person(const string &ln, const char *fn = "Heyyou") //#2
    {
        lname = ln;
        for (int i = 0; i < strlen(fn); i++)
            fname[i] = fn[i];
        *fname = *fn;
    }

    // the following methods display lname and fname

    void show() const; // firstname lastname format

    void FormalShow() const; // lastname, firstname format
};