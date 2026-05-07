#include <bits/stdc++.h>
// 前缀和用于快速求区间和，差分用于快速进行区间修改
// https://oi-wiki.org/basic/prefix-sum/#_8
// 差分是与前缀和相对的策略，是前缀和的逆运算
// 对比一下前缀和与差分的公式即可看出
// 前缀和：D[i] = D[i-1]+a[i]   d是a的前缀和
// 差分：D[i] = a[i] - a[i-1],a[0]=0    d是a的差分数列
/*实例：将a数组中[l,r]区间内的数字全部加k

设b数组存储差分信息，则易得 将b[l]加上k，然后再将b[r+1]减去k即为想要的结果

Q&A

Q1:为什么是b[l]?

A1:a[l]加k，则a[l]与a[l-1]的差增加k

Q2:那为什么是b[r+1]?

A2:a[r]加k，则a[r]与a[r+1]的差减小k。注意！此时操作的应该是b[r+1]而不是b[r]。

Q3:为什么b[l+1,r]不用更改？

A3:一起增加k，他们之间的差值不变

个人觉得差分/前缀和的本质就是把一个对线的的操作降维到了更低的维度,时间复杂度因此下降
所有操作都对差分数组进行,最后要得到结果只需要对差分数组进行一次前缀和运算即可

对前缀和求差分得到原数列这很好理解
但对于差分求前缀和就有点难以想象.
但其实前缀和的过程，其实就是把这些分散的“高度差”给一层层累加起来的过程,想象你在爬楼梯
差分值也就是每个台阶走了多高(假设台阶高度不一),当前高度是原数组
*/

int main()
{
    int N;
    int times; // N是学生数,times是修改次数
    std::cin >> N >> times;
    std::vector<int> origin(N + 1, 0); // 原始分数
    // 强烈建议约定三种数组(原,前缀和,差分)的索引为0的元素为0
    for (int i = 1; i < N + 1; i++)
    {
        std::cin >> origin[i];
    }
    std::vector<int> difference(N + 1, 0);
    for (int i = 1; i < N + 1; i++)
    {
        difference[i] = origin[i] - origin[i - 1];
    }
    while (times--)
    {
        int first;
        int end;
        int change;
        std::cin >> first >> end >> change;
        difference[first] += change;
        if (end != N) // 如果再多开一个空间就不需要这个判断了
        {
            difference[end + 1] -= change;
        }
    }
    std::vector<int> prefix(N + 1, 0);
    int min = 1e9;
    int sum = 0;
    for (int i = 1; i < N + 1; i++)
    {
        // 这没有正确求前缀和
        // prefix[i] = difference[i - 1] + difference[i];
        sum += difference[i];
        prefix[i] = sum;
        min = std::min(prefix[i], min);
    }
    std::cout << min;
}