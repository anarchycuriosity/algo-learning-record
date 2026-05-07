#include <iostream>
using namespace std;
int main()
{
    const int SIZE = 10;
    int nums[SIZE];
    for(int i = 0;i < SIZE;i++)
    {
        cin >> nums[i];
    }
    
    for(int i = 0;i < SIZE - 1;i++)
    {
        int minindex = i;
        for(int j = i;j < SIZE;j++)
        {
            if(nums[minindex] > nums[j])
            {
                swap(nums[minindex],nums[j]);
            }
        }
    }
    for(int i = 0;i < SIZE;i++)
    {
        cout << nums[i] << " ";
    }
}