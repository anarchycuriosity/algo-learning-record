#include <iostream>
#include <cmath>
#include <iomanip>
int main()
{
    double a,b,c;
    std::cin >> a >> b >> c;
    double p = (a + b + c) / 2.0;
    double area = std::sqrt(p * (p - a) * (p - b) * (p - c)) * 1.0;
    std::cout << std::fixed << std::setprecision(1) <<  area;
}