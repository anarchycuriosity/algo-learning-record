#include <iostream>
#include <algorithm>
using namespace std;
const int SIZE = 8;
struct emp
{
    string name;
    int hours[8];
    int sum = 0;
};
int main()
{
    emp emps[8];
    for(int i = 0;i < 8;i++)
    {
        for(int j = 0;j < 7;j++)
        {
            cin >> emps[i].hours[j];
        }
    }
    for(int i = 0;i < 8;i++)
    {
        emps[i].name = "Employee " + to_string(i) + ": ";
        for(int j = 0;j < 7;j ++)
        {
            emps[i].sum += emps[i].hours[j];
        }
    }
    sort(begin(emps),end(emps),[](const emp &a,const emp &b)
    {
        if(a.sum == b.sum)
        {
            return a.name < b.name;
        }
        else
        {
            return a.sum > b.sum;
        }
        
    });
    for(int i = 0;i < 8;i++)
    {
        cout << emps[i].name << emps[i].sum << endl;
    }
    return 0;
}