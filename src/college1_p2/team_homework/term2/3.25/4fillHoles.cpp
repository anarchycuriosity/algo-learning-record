#include <iostream>
#include <vector>
int main()
{
    int n;
    std::cin >> n;
    std::vector<int> road(n, 0);
    for (int i = 0; i < n; i++)
    {
        std::cin >> road[i];
    }
    // 你可以想象往坑里面倒水，你一次可以倒任意量，但是你不能倒到溢出去
    // 我们会统计你每次倒水上升的最大高度
    // 水会从高处往低处流，也可以平着流，虽然这么说不太准确
    // 但我相信你可以理解这个水流的规律，虽然这不是普通的水
    // 无论你从区间的中间开始倒还是从区间的左边开始倒水
    // 其实结果都一样，你每次倒水的影响都会平行地延申
    int days = road[0]; // 这肯定要填
    for (int i = 1; i < n; i++)
    {
        if (road[i] <= road[i - 1])
        {
            continue;
        }
        else
        {
            days += road[i] - road[i - 1];
        }
    }
    std::cout << days;
}