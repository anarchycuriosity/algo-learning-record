#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
    int n;
    std::cin >> n;
    std::vector<int> line(n, 0);
    for (int i = 0; i < n; i++)
    {
        std::cin >> line[i];
    }
    int sum = 0;
    int max_sum = -1e9;
    for (int i = 0; i < n; i++)
    {
        if (sum > 0) // 如果说之前的sum < 0，加了也是白加
        {
            sum += line[i];
        }
        else
        {
            sum = line[i];
        }
        max_sum = std::max(sum, max_sum);
    }
    std::cout << max_sum;
}