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
        ans += 4 * w;
        long long ll = std::max(l - w, w);
        long long ww = std::min(l - w, w);
        plant(ll, ww);
    }
}

int main()
{
    long long x, y;
    std::cin >> x >> y;
    plant(std::max(x, y), std::min(x, y));
    std::cout << ans;
}
