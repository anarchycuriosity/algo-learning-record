#include <vector>
#include <iostream>
#include <algorithm>
int main()
{
    int n, c;
    std::cin >> n >> c;
    std::vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        std::cin >> nums[i];
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (std::abs(nums[i] - nums[j]) == c)
            {
                count++;
            }
        }
    }
    std::cout << count;
}