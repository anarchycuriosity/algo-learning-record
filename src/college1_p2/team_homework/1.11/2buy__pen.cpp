//向上取整的技巧，贪心算法greed
#include <bits/stdc++.h>
int main()
{
    int n;
    std::cin >> n;
    int min = 1e9;
    for(int i = 0;i < 3;i++)
    {
        int amo,price;
        std::cin >> amo >> price;
        int pacs = (n + amo - 1) / amo;
        int tot_cost = pacs * price;
        min = std::min(tot_cost,min);
    }
    std::cout << min;
}