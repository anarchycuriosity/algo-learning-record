// 应该采用01背包的解决方法而不是完全背包
#include <vector>
#include <algorithm>
#include <iostream>
int main()
{
    int v;
    int n;

    if (!(std::cin >> v >> n))
    {
        return 0;
    }

    std::vector<int> items(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> items[i];
    }
    // 01背包和完全的背包的区别主要就是在于第二层for循环的顺序
    // 完全背包是正序，01背包是逆序
    // 正序能够让小的j先更新
    // 当更新大的j时，可以在刚才以及放过该物品的基础上再放一个
    // 本题的代价是重量而不是个数
    std::vector<int> dp(v + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = v; j >= dp[items[i]]; j--)
        {
            if (dp[j - items[i]] > dp[j])
            {
                dp[j] = dp[j - items[i]] + items[i];
            }
        }
    }
    std::cout << v - dp[v];
}