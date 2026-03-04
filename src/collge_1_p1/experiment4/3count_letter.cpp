#include <iostream>
#include <map>
using namespace std;
int main()
{
    char str[100];
    cin.getline(str,100);
    map<char,int> lettercount;
    map<char,int> allcount;
    for(int i = 0;str[i] != '\0';i++)
    {
        lettercount[str[i]]++;
    }
    for(char ch = 'a';ch <= 'z';ch++)
    {
        allcount[ch] = lettercount[ch] + lettercount[ch - 32];
    }
    for(char ch = 'a';ch <= 'z';ch++)
    {
        if(allcount[ch] !=0)
        {
            cout << ch << " happens " << allcount[ch] << "times" <<endl ;
        }
    }
    return 0;
}