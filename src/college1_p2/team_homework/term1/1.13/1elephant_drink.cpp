#include <bits/stdc++.h>
// 纯整数的向上取整和小数的向上取整不一样
// 这题属于后者
double PI = 3.14;
int main()
{
    int h, r;
    std::cin >> h >> r;
    double v_bucket = PI * r * r * h;
    double v_need = 20 * 1000;
    int need_bucket = ceil(v_need / v_bucket);
    std::cout << need_bucket;
}