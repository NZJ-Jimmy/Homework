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