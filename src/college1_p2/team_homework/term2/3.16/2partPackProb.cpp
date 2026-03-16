// 背包问题并不能盯着单位价值高的物品去薅，因为物品无法被拆分为单位重量的价值，会超重
// 但是本题的金币可以，要想拿到最高价值的总量就要先把最高价值的那堆金币拿走
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
struct calPile
{
    double valPer;
    double weight;
    double tot;
};
bool compare(const calPile &a, const calPile &b)
{
    return a.valPer >= b.valPer;
}
int main()
{
    std::vector<calPile> cave;
    int N;
    double capacity;
    std::cin >> N >> capacity;
    for (int i = 0; i < N; i++)
    {
        double weight;
        double tot;
        std::cin >> weight >> tot;
        cave.push_back({tot / weight * 1.0, weight, tot});
    }
    // 使用lambda
    // std::sort(cave.begin(), cave.end(), [](const calPile &a, const calPile &b)
    //          { return a.valPer >= b.valPer; });
    std::sort(cave.begin(), cave.end(), compare);
    double curCap = capacity;
    double get = 0;
    for (int i = 0; i < cave.size(); i++)
    {
        if (curCap >= cave[i].weight)
        {
            get += cave[i].tot;
            curCap -= cave[i].weight;
        }
        else
        {
            get += curCap * cave[i].valPer;
            break;
        }
    }
    std::cout << std::fixed << std::setprecision(2) << get;
}