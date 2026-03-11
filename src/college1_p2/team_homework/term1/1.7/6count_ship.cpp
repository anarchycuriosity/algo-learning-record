#include <bits/stdc++.h>
struct Ship
{
    int t;
    int n;
    std::set<int> nations;
    
};
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int p;
    std::cin >> p;
    std::vector<Ship> ships;
    for(int i = 0;i < p;i++)
    {
        Ship ship;
        std::cin >> ship.t;
        std::cin >> ship.n;
        for(int j = 0;j < ship.n;j++)
        {
            int nation;
            std::cin >> nation;
            ship.nations.insert(nation);
        }
        ships.emplace_back(ship);
    }
    for(int i = 0;i < p;i++)
    {
        int bi = i;
        //int fi = i;
        std::set<int> b_nations;
        //std::set<int> f_nations;
        for(bi;bi >=0;bi--)
        {
            if(ships[i].t - ships[bi].t >= 86400)
            {
                break;
            }
            for(int nation : ships[bi].nations)
            {
                b_nations.insert(nation);
            }
        }
        std::cout << b_nations.size() << "\n";
        /*
        for(fi;fi <p;fi++)
        {
            if(ships[fi].t - ships[i].t >= 86400)
            {
                break;
            }
            for(int nation : ships[fi].nations)
            {
                f_nations.insert(nation);
            }
        }
        b_nations.merge(f_nations);
        */

    }
}