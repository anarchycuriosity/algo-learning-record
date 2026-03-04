#include <iostream>
using namespace std;
bool issorted(const int list[],int size)
{
    int count = 0;
    int i = 1;
    for(i;i < size;i++)
    {
        if(list[i] > list[i-1])
        {
            count++;
            
        }
    }
    if(count == size -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int size;
    cin >> size;
    int nums[100];
    for(int i=0;i < size;i++)
    {
        cin >> nums[i];
    }
    if(issorted(nums,size))
    {
        cout << "已排序";
    }
    else
    {
        cout << "未排序";
    }
    return 0;
    
}