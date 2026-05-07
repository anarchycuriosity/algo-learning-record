#include <bits/stdc++.h>
int main()
{
    //考察的是dp问题
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int num;
    std::cin >> num;
    int dp[1001] = {0};
    for(int i = 1; i <= num;i++)
    {
        dp[i] = 1;
        for(int j = 1;j <= i / 2;j++)
        {
            dp[i] += dp[j];
        }
    }
    std::cout << dp[num];
    
}