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
    std::vector<std::vector<int>> area_row(n, std::vector<int>(m, 0));
    std::vector<std::vector<int>> area_col(n, std::vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < m; j++)
        {
            sum += area[i][j];
            area_row[i][j] = sum;
        }
    }
    for (int j = 0; j < m; j++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += area[i][j];
            area_col[i][j] = sum;
        }
    }
    for (int j = 1; j < m; j++)
    {
        int sum_d_c = 0;
        for (int i = j - 1; i >= 0; i--)
        {
            sum_d_c += area_row[i][j];
        }
        int other = sum - sum_d_c;
        gap = std::min(gap, std::abs(sum_d_c - other));
    }
    for (int i = 1; i < n; i++)
    {
        int sum_d_r = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            sum_d_r += area_col[i][j];
        }
        int other = sum - sum_d_r;
        gap = std::min(gap, std::abs(sum_d_r - other));
    }
    std::cout << gap;
}