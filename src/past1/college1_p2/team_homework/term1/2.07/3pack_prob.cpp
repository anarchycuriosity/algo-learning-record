#include <vector>
#include <algorithm>
#include <iostream>
int main()
{
    int v;
    std::cin >> v;
    int n;
    std::cin >> n;
    std::vector<int> items(n, 0);
    while (n--)
    {
        std::cin >> items[n];
    }
    std::vector<int> dp(v + 1, 1e9 + 7);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = items[i]; j <= v; j++)
        {
            if (dp[j - items[i]] + 1 < dp[j])
            {
                dp[j] = dp[j - items[i]] + 1;
            }
        }
    }
    int max = 0;
    for (int i = 0; i < v + 1; i++)
    {
        if (dp[i] != 1e9 + 7)
        {
            max = std::max(max, i);
        }
    }
    std::cout << v - max;
}