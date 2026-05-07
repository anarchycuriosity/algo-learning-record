// 完全背包问题
// 纸币可以无限使用
#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
    int n, w;
    std::cin >> n >> w;
    std::vector<int> vals(n, 0);
    for (int i = 0; i < n; i++)
    {
        std::cin >> vals[i];
    }
    std::vector<int> dp(w + 1, 1e9);
    dp[0] = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = vals[i]; j <= w; j++)
        {
            if (dp[j - vals[i]] + 1 < dp[j])
            {
                dp[j] = dp[j - vals[i]] + 1;
            }
        }
    }
    std::cout << dp[w];
}