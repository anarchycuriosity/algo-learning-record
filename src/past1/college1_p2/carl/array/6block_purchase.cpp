#include <iostream>
#include <vector>
#include <algorithm>
// 每次重新划线的时候，我们都在使用以前其实以及计算出来的结果
// 这其实就启示我们使用前缀和
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
    for (int i = 1; i < n; i++) // 这里可能会错写陈n - 1，这样会遗漏
    {
        int sum_row = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            for (int k = 0; k < m; k++)
            {
                sum_row += area[j][k];
            }
        }
        int other = sum - sum_row;
        gap = (gap > std::abs(sum_row - other)) ? (std::abs(sum_row - other)) : gap;
    }
    for (int i = 1; i < m; i++)
    {
        int sum_col = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            for (int k = 0; k < n; k++)
            {
                sum_col += area[k][j];
            }
        }
        int other = sum - sum_col;
        gap = (gap > std::abs(sum_col - other)) ? (std::abs(sum_col - other)) : gap;
    }
    std::cout << gap;
}