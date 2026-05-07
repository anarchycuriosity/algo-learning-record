// 第二版的思路有问题，想要减少复杂度并不是减少一层for循环这么简单
// 最终复杂度如何是看计算量，当然第二版确实有一定优化
#include <iostream>
#include <vector>
#include <algorithm>
// 前缀和的优化解法
int main()
{
    int n, m;
    std::cin >> n >> m;
    int sum = 0;
    std::vector<std::vector<int>> area(n, std::vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> area[i][j];
            sum += area[i][j];
        }
    }
    int gap = 1e9;
    std::vector<int> sum_d_r(n, 0);
    std::vector<int> sum_d_c(m, 0);
    int presum = 0;
    for (int i = 0; i < n; i++)
    {
        // int presum = 0;是累加直到这一行的结果而不是该行的结果
        for (int j = 0; j < m; j++)
        {
            presum += area[i][j];
        }
        sum_d_r[i] = presum;
    }
    presum = 0;
    for (int j = 0; j < m; j++)
    {
        // int presum = 0;
        for (int i = 0; i < n; i++)
        {
            presum += area[i][j];
        }
        sum_d_c[j] = presum;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int other = sum - sum_d_r[i];
        gap = std::min(gap, std::abs(other - sum_d_r[i]));
    }
    for (int j = 0; j < m - 1; j++)
    {
        int other = sum - sum_d_c[j];
        gap = std::min(gap, std::abs(other - sum_d_c[j]));
    }
    std::cout << gap;
}