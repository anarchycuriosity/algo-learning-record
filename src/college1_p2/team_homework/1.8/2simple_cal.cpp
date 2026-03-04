#include <bits/stdc++.h>
int main()
{
    // 1/2是整数除法，结果是0
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    double a = std::pow(((1 + std::pow(5,0.5))/2.0),n);
    double b = std::pow(((1 - std::pow(5,0.5))/2.0),n);
    double Fn =(a - b)/(std::pow(5,0.5));
    std::cout << std::fixed << std::setprecision(2) << Fn;
}