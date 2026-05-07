// 递归的减法过于麻烦了会TLE
#include <iostream>
#include <algorithm>
// 首先要注意整型溢出导致的WA
long long ans = 0;
void plant(long long l, long long w)
{
    if (l == w)
    {
        ans += 4 * w;
        return;
    }
    else
    {
        // 使用除法优化
        if (l % w == 0)
        {
            ans += (l / w) * 4 * w;
            return;
        }
        else
        {
            long long times = l / w;
            long long res = l % w;
            ans += 4 * w * times;
            plant(std::max(w, res), std::min(w, res));
        }
    }
}

int main()
{
    long long x, y;
    std::cin >> x >> y;
    plant(std::max(x, y), std::min(x, y));
    std::cout << ans;
}
