#include <vector>
#include <iostream>
int main()
{
    int tar;
    std::cin >> tar;
    int x = 100;
    int k = 1;
    // 一个要最大，一个要最小，那么最外两层层循环用于更新数据
    // 如果能找到准确的值就返回，否则x--或者k++
    // 不可能同时更新两个数据，所以最外层k更新次外层更新x
    // k的范围不是固定的，所以我们应该把它作为外层，减少复杂度
    for (int k = 1;; k++)
    {
        for (x = 100; x >= 1; x--)
        {
            int get = (7 * x + 21 * k) * 52;
            if (get == tar)
            {
                std::cout << x << std::endl;
                std::cout << k;
                return 0;
            }
        }
    }
}