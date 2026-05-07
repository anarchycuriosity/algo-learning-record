#include <bits/stdc++.h>
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int a,b,c;
    std::cin >> a >> b >> c;
    int sum = (a * 20 + b * 30 + c * 50 ) / 100;
    std::cout << sum;
}