// 记忆化数组防止递归保证，全局数组默认初始化为0
#include <bits/stdc++.h>
struct UN
{
    long long a, b, c, ans;
};
long long dp[21][21][21];
long long w(long long a, long long b, long long c)
{
    // 不要过早地判断数组是否为0，先看下标是否越界
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }
    if (a > 20 || b > 20 || c > 20)
    {
        return w(20, 20, 20);
    }
    // 这个一定要放在判断是否越界的后面
    if (dp[a][b][c] != 0)
    {
        return dp[a][b][c];
    }
    if (a < b && b < c)
    {
        // 不要直接return，而是存入记忆数组，在最后return记忆数组对应位置
        // return w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a - 1, b - 1, c - 1);
        dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    }
    else
    {
        // return w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
        dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    }
    return dp[a][b][c];
}
int main()
{
    std::vector<UN> uns;
    while (true)
    {
        long long a, b, c, ans;
        std::cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
        {
            break;
        }
        ans = w(a, b, c);
        UN un{a, b, c, ans};
        uns.emplace_back(un);
    }
    for (int i = 0; i < uns.size(); i++)
    {
        std::cout << "w(" << uns[i].a << ", " << uns[i].b << ", " << uns[i].c << ") = " << uns[i].ans << std::endl;
    }
}