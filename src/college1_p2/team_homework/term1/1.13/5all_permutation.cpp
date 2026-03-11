#include <bits/stdc++.h>
int main()
{
    int n;
    std::cin >> n;
    std::vector<int> nums;
    for (int i = 1; i <= n; i++)
    {
        nums.emplace_back(i);
    }
    do
    {
        for (int i = 0; i < nums.size(); i++)
        {
            std::cout << std::setw(5) << nums[i];
        }
        std::cout << std::endl;
    } while (std::next_permutation(nums.begin(), nums.end()));
}