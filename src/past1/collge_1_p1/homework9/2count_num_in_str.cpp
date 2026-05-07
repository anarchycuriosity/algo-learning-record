#include <iostream>
#include <map>
using namespace std;
int *count(const string& s)
{
    map<char,int> numswithcount;
    for(int i = 0;i < s.size();i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            numswithcount[s[i]]++;
        }
    }
    int *counts = new int[10];
    for(int i = 0;i < 10;i++)
    {
        char digit = '0' + i;
        counts[i] = numswithcount[digit];
    }
    return counts;
    //后面的语句不会再执行
    //delete[] counts;
}
int main()
{
    string s;
    cin >> s;
    int *counts = count(s);
    for(int i = 0;i < 10;i++)
    {
        cout << i << ":" << counts[i] << endl;
    }
    delete[] counts;
    return 0;
}