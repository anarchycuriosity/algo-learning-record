// 由于本题需要在一定范围内找符合特定要求的数
// 我们通过控制最小质因子来确保时间复杂度小，实现线性筛
#include <iostream>
#include <vector>
const int limit = 40000;

int main()
{
    std::vector<int> ans;
    int start;
    std::cin >> start;

    // 使用筛来查找的思路其实很巧妙
    // 我们先查factor_sum的下标a的元素b
    // 然后再查下标b的元素，如果是a就对了
    // 关于内层j循环，j初始化为2 * i是为了防止把自己算进去，约数不包括这个数本身
    // 每次j+=i其实就是在找i的倍数
    std::vector<int> fac_sum(limit + 1, 0);
    for (int i = 1; i <= limit / 2; i++)
    {
        for (int j = 2 * i; j <= limit; j += i)
        {
            fac_sum[j] += i;
        }
    }

    for (int i = start; i <= limit; i++)
    {
        int sum = fac_sum[i];
        if (sum <= limit && sum != i && fac_sum[sum] == i) // 访问数组前打保险，不能是同一个数
        {
            std::cout << i << " " << sum << std::endl;
            break;
        }
    }
}