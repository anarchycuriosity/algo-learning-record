#include <algorithm>
#include <vector>
#include <iostream>
// 这里是求总方案数而不是数目最大值
// 对应的逻辑应该是像前缀和的累加而不是覆盖
int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> items(n, 0);
    for (int i = 0; i < n; i++)
    {
        std::cin >> items[i];
    }
    std::vector<int> dp(m + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = m; j >= items[i]; j--)
        {
            if (dp[j - items[i]] + dp[j] > dp[j])
            {
                dp[j] = dp[j - items[i]] + dp[j];
            }
        }
    }
    std::cout << dp[m];
}