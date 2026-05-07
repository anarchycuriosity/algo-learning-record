#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
bool my_compare(int a, int b)
{
    return a > b;
}
int main()
{
    int n, w;
    std::cin >> n >> w;
    std::vector<int> vec;
    std::vector<int> ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        int num;
        std::cin >> num;
        vec.push_back(num);
        int posi = std::max(1, w * (i + 1) / 100); // posi从1开始，i从0开始
        std::sort(vec.begin(), vec.end(), my_compare);
        ans[i] = vec[posi - 1];
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << ans[i] << " ";
    }
}