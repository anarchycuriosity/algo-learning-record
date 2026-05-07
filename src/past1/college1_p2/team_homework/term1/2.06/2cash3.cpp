#include <iostream>
#include <vector>
int main()
{
    int n, w;
    std::cin >> n >> w;
    std::vector<int> vals(n, 0);
    for (int i = 0; i < n; i++)
    {
        std::cin >> vals[i];
    }
    std::vector<int> dp(w + 1, 0);
    int mod = 1e9 + 7;
    dp[0] = 1;
    // 这是组合数，外层遍历纸币，内层遍历金额
    for (int i = 0; i < n; i++) // 排序数的外层循环时遍历金额，内层遍历纸币。
    {
        for (int j = vals[i]; j <= w; j++)
        {
            dp[j] = (dp[j] + dp[j - vals[i]]) % mod;
        }
    }
    std::cout << dp[w];
}