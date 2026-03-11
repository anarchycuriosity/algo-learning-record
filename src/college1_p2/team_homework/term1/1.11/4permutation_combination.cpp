#include <bits/stdc++.h>
bool is_sort(std::vector<int> nums, int r)
{
    for (int i = 0; i < r - 1; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n, r;
    std::cin >> n >> r;
    std::vector<int> nums;
    std::set<std::string> strs;
    for (int i = 1; i <= n; i++)
    {
        nums.emplace_back(i);
    }
    do
    {
        if (is_sort(nums, r))
        {
            std::string str;
            for (int i = 0; i < r; i++)
            {

                str = str + std::to_string(nums[i]);
            }
            strs.insert(str);
        }
    } while (std::next_permutation(nums.begin(), nums.end()));
    // 可以直接return a < b因为string本身就支持字典序比较
    /*
    std::sort(strs.begin(), strs.end(), [](std::string &a, std::string &b)
              {for(int i = 0;i < a.size();i++)
    {
        return a[i] < b[i];
    } });
    */

    for (auto it = strs.begin(); it != strs.end(); it++)
    {
        for (int i = 0; i < r; i++)
        {
            // 这里是char值，如果直接cout会出来ascii码
            std::cout << std::setw(3) << (*it)[i] - '0';
        }
        std::cout << std::endl;
    }
}