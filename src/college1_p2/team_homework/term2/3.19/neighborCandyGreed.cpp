// 本题的贪心策略是：如果从左到右遍历，如果遇到i 和i+1之和大于x的时候
// 有两种选择，一个是吃掉左边的，一个是吃掉右边的
// 显然最好是吃掉右边的，因为当吃掉右边的时候可以帮助更右边的部分减轻压力
// 而吃掉左边的时候则完全没有帮助

// 这其实就是决策序列化和贡献最大化
// 常见贪心的题型：区间覆盖型(如何参加尽可能多的活动)
// 相邻约束性,比如这题,修改交集部分让一次修改影响多个约束
// 代价排序类:如何用最少的钱买最多的东西,性价比排序,比如阿里拿金币堆

// 注意一下数据的类型,可能会整形移除
// while循环-太慢了
// 直接减去差值
#include <iostream>
#include <vector>
int main()
{
    int n, x; // n是盒子数,x是相邻盒子的最大和
    std::cin >> n >> x;
    std::vector<int> candies(n, 0);
    // 不要这样自减后又用n
    /*     while (n--)
        {
            int a;
            std::cin >> a;
            candies.push_back(a);
        } */

    for (int i = 0; i < n; i++)
    {
        std::cin >> candies[i];
    }
    long long count = 0; // 表示吃掉的糖果

    // 第一个盒子应该特别处理
    if (candies[0] > x)
    {
        long long eaten = (long long)candies[0] - x;
        candies[0] -= eaten;
        count += eaten;
    }
    for (int i = 0; i < n - 1; i++)
    {
        // 不要查i-1,因为根本是要查和,这可能会导致多吃
        // 而且我们其实只需要查相邻两个盒子,哪怕它可能影响前一个我们也不管
        /*         if (candies[i - 1] > x)
                {
                    int eaten = candies[i - 1] - x;
                    candies[i - 1] -= eaten;
                    count += eaten;
                } */
        /*         if (candies[i] > x)
                {
                    long long eaten = candies[i] - x;
                    candies[i] -= eaten;
                    count += eaten;
                } */
        if (candies[i] + candies[i + 1] > x)
        {
            long long eaten = (long long)candies[i] + candies[i + 1] - x;
            candies[i + 1] -= eaten;
            count += eaten;
        }
    }
    std::cout << count;
}