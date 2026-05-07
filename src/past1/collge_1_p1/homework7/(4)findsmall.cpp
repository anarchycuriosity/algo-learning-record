#include <iostream>
#include <vector>
using namespace std;
int indexofsmallest(int arr[],int size)
{
    int small = arr[0];
    int index = 0;
    for(int i = 0;i < size;i++)
    {
        if(small > arr[i] || (small == arr[i] && index > i))
        {
            small = arr[i];
            index = i;
        }
    }
    return index;
}
int main()
{
    int nums[10],size = 10;
    for(int i = 0;i < size;i++)
    {
        int num;
        cin >> num;
        nums[i] =num;
    }
    cout << indexofsmallest(nums,size);
    return 0;
}












