#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
int main()
{
    double a,b,c;
    std::cin >> a >> b >> c;
    std::vector<double> lens;
    lens.emplace_back(a);
    lens.emplace_back(b);
    lens.emplace_back(c);
    std::sort(lens.begin(),lens.end());
    if(lens[0] + lens[1] <= lens[2])
    {
        std::cout << "不合格";
    }
    else
    {
        if(lens[0] == lens[1] || lens[1] == lens[2])
        {
            if(std::pow(lens[0],2) + std::pow(lens[1],2) == std::pow(lens[2],2))
            {
                std::cout << "等腰直角";
            }
            else
            {
                std::cout << "等腰";
            }
        }
        else if(std::pow(lens[0],2) + std::pow(lens[1],2) == std::pow(lens[2],2))
        {
            std::cout << "直角";
        }
        else
        {
            std::cout << "普通三角形";
        }
    }
    return 0;
}