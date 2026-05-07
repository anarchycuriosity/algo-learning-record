#include <bits/stdc++.h>
int main()
{
    int k;
    std::cin >> k;
    int coin = 0;
    int day = 1;
    for (int sal = 1; day <= k; sal++) // 有点复杂的for循环
    {
        // 下面那个for一定一定要加day <=k的判断，这非常的重要否则会多拿钱
        for (int j = 0; j < sal && day <= k; j++) // j是从薪水变换开始的计数器
        {
            // 这两行的顺序会产生很大的差别，这可能导致某天的薪水没领到那天就结束了
            coin += sal;
            day++;
        }
    }
    std::cout << coin;
}