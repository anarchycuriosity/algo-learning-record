#include <bits/stdc++.h>
//子集枚举型
struct Dish
{
    int sour;
    int bitter;
};

int main()
{
    int n;
    std::cin >> n;
    std::vector<Dish> dishes;
    for(int i = 0;i < n;i++)
    {
        Dish dish;
        std::cin >> dish.sour >> dish.bitter;
        dishes.emplace_back(dish);
    }
    int min = std::abs(dishes[0].sour - dishes[0].bitter);
    for(int mask = 1;mask < (1 << n);mask++)//第一层是每一个子集
    {
        int tot_sour = 1;
        int tot_bitter = 0;
        for(int i = 0;i < dishes.size();i++)
        {
            if(mask & 1<<i)
            {
                tot_sour *= dishes[i].sour;
                tot_bitter += dishes[i].bitter;
            }
        }
        int tot_abs = std::abs(tot_sour - tot_bitter);
        min = std::min(min,tot_abs);
    }
    std::cout << min;
}