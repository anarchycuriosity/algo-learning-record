#include <iostream>
#include <vector>
using namespace std;
bool isconse(vector<int> values,int size)
{
    int count = 0;
    for(int i = 1;i < size;i++)
    {
        if(values[i] == values[i - 1])
        {
            count += 1;
        }
        if(values[i] != values[i - 1])
        {
            count = 0;
        }
        if(count == 3)
        {
            return true;
        }
        else if(i == size -1 && count != 3)
        {
            return false;
        }
    }
    return false;
}
int main()
{
    int size;
    cin >> size;
    cin.ignore();
    vector<int> values;
    for(int i = 0;i < size;i++)
    {
       int num;
       cin >> num;
       values.push_back(num);
    }
    if(isconse(values,size))
    {
        cout << "有";
    }
    else
    {
        cout << "无";
    }
    return 0;
}