#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> list1,list2,sames;
    for(int i = 0;i <10;i++)
    {
        int num;
        cin >> num;
        list1.push_back(num);
    }
    for(int i = 0;i <10;i++)
    {
        int num;
        cin >> num;
        list2.push_back(num);
    }
    for(int i = 0;i < 10;i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(list1[i] == list2[j])
            {
                sames.push_back(list1[i]);
            }
        }
    }
    sort(sames.begin(),sames.end());
    sames.erase(unique(sames.begin(),sames.end()),sames.end());
    for(int i = 0;i < sames.size();i++)
    {
        cout << sames[i] << " ";
    }
}