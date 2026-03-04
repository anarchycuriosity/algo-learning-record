#include <iostream>
using namespace std;
//bool isdiff(auto &diffnums,int & n,int& num)
bool isdiff(int *diffnums,int n,int num)
{
    for(int i =0;i < n;i++)
    {
        if(diffnums[i] == num)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    int *nums,*diffnums;
    nums = new int[n];
    diffnums = new int[n];
    for(int i = 0;i < n;i++)
    {
        cin >> nums[i];
    }
    //开始往diffnums里面塞nums里面不相同的数
    int idx = 0;
    for(int i = 0;i < n;i++)
    {
        if(isdiff(diffnums,idx,nums[i]))
        {
            diffnums[idx++] = nums[i];
        }
    }
    //输出
    for(int i =0;i < idx;i++)
    {
        cout << diffnums[i] << " ";
    }
    delete[] nums;
    delete[] diffnums;
}