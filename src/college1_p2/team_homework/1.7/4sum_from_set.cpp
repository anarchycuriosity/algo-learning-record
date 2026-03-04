#include <bits/stdc++.h>
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    std::set<int> pronums;
    for(int i = 0;i < n;i++)
    {
        std::cin >> nums[i];
    }
    for(int num:nums)
    {
        pronums.insert(num);
    }
    int count = 0;
    for(int num:nums)
    {
        int triger = 0;
        for(int pronum:pronums)
        {
            int complete = num - pronum;
            if(complete == pronum)
            {
                continue;
            }
            if(pronums.find(complete) != pronums.end())
            {
                triger = 1;
            }
        }
        if(triger == 1)
        {
            count++;
        }
    }
    std::cout << count;
}