// 区间求和如果只是遍历累加，很容易超时面对大数据量
// 所以来讲解数组上常用的解题技巧，前缀和
// 该思想在于重复利用计算过的子数组之和，从而降低区间查询需要累加计算的次数
// 其实就是用另一个容器来存储对应i位置之前的累加和，比如求2-5只要用p[5] - p[1]即可
// 面对大量数据的读取输出操作,最好用scanf和printf,耗时会小很多
#include <vector>
#include <iostream>
int main()
{
    int n;
    std::cin >> n;
    std::vector<int> nums(n, 0);
    std::vector<int> p(n, 0);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> nums[i];
        sum += nums[i];
        p[i] = sum;
    }
    int a, b;
    while (std::cin >> a >> b)
    {
        int resum;
        if (a == 0)
        {
            resum = p[b];
        }
        else
        {
            resum = p[b] - p[a - 1];
        }
        std::cout << resum << std::endl;
    }
}