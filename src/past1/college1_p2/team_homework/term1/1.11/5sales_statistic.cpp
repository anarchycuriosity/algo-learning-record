#include <bits/stdc++.h>
int find_wave(std::vector<int> daily_sales, int idx)
{
    int min = std::abs(daily_sales[0] - daily_sales[idx]);
    for (int i = 1; i < idx; i++)
    {
        int pro_min = std::abs(daily_sales[i] - daily_sales[idx]);
        min = std::min(min, pro_min);
    }
    return min;
}
int main()
{
    int n;
    std::cin >> n;
    std::vector<int> daily_sales;
    for (int i = 0; i < n; i++)
    {
        int daily_sale;
        std::cin >> daily_sale;
        daily_sales.emplace_back(daily_sale);
    }
    int sum = 0;
    sum += daily_sales[0];
    for (int i = 1; i < n; i++)
    {
        sum += find_wave(daily_sales, i);
    }
    std::cout << sum;
}