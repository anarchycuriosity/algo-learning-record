#include <bits/stdc++.h>
int main()
{

    int s, v;
    std::cin >> s >> v;
    int tot_m = (s + v - 1) / v + 10;
    // 不要中途就提前转化为h和min来算否则会很混乱
    // int cost_m = tot_m % 60;
    // int cost_h = tot_m - tot_m % 60;别这样算了，直接/60（整数除法）就可以了
    int end_m = 8 * 60;
    int st_min = end_m - tot_m;
    if (st_min < 0)
    {
        st_min += 24 * 60;
    }
    int h = st_min / 60;
    int m = st_min % 60;
    // 有可能没有覆盖所有情况
    if (h < 10 && m < 10)
    {
        std::cout << 0 << h << ":" << 0 << m;
    }
    else if (h >= 10 && m < 10)
    {
        std::cout << h << ":" << m;
    }
    else if (h < 10 && m >= 10)
    {
        std::cout << 0 << h << ":" << m;
    }
    else if (h >= 10 && m >= 10)
    {
        std::cout << h << ":" << m;
    }
}