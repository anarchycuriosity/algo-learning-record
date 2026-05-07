#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
    int n;
    std::cin >> n;
    int max = 0;
    int min = 1e9;
    while (n--)
    {
        int num;
        std::cin >> num;
        max = std::max(max, num);
        min = std::min(min, num);
    }
    std::cout << max - min;
}