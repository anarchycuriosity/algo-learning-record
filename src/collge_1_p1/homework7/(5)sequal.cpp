#include <iostream>
#include <vector>
using namespace std;
/*
bool sequal(vector<int> list1,vector<int> list2,int size)
{
    int count = 0;
    for(int i = 0;i < size;i++)
    {
        if(list1[i] != list2[i])
        {
            return false;
        }
        else
        count ++;
    }
    if(count == size)
    {
        return true;
    }
    return true;
}
*/
bool sequal(const vector<int>& list1, const vector<int>& list2, int size)
{
    for(int i = 0; i < size; i++)
    {
        if(list1[i] != list2[i])
            return false;
    }
    return true;
}


int main()
{
    int n1,n2;
    cin >> n1;
    cin.ignore();
    vector<int> list1,list2;
    for(int i = 0;i < n1;i++)
    {
        int num;
        cin >> num;
        list1.push_back(num);
    }
    cin >> n2;
    cin.ignore();
    for(int i = 0;i < n2;i++)
    {
        int num;
        cin >> num;
        list2.push_back(num);
    }
    int size = list1.size();
    if(n1 != n2)
    {
        cout << "非严格相同";
    }
    else if(sequal(list1,list2,size))
    {
        cout << "严格相同";
    }
    else
    {
        cout << "非严格相同";
    }
    return 0;
}