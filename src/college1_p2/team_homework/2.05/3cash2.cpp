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
    const int mod = 1e9 + 7;
    dp[0] = 1;

    for (int i = 1; i <= w; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= vals[j])
            {
                dp[i] = (dp[i] + dp[i - vals[j]]) % mod;
                // 如果我们要放入这个val，那么就需要提前凑i - val元，所以需要累加i - val的dp
            }
        }
    }
    std::cout << dp[w];
}