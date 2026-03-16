#include <iostream>
#include <vector>
int main()
{
    int first, end;
    std::cin >> first >> end;
    // 先找到第一个闰年然后每4年一跳
    int cur = first;
    int count = 0;
    std::vector<int> runs;
    while (cur <= end)
    {
        if (!((cur % 4 == 0 && cur % 100 != 0) || cur % 400 == 0))
        {
            cur++;
        }
        else
        {
            break;
        }
    }
    for (; cur <= end; cur += 4)
    {
        if (((cur % 4 == 0 && cur % 100 != 0) || cur % 400 == 0))
        {
            runs.push_back(cur);
            count++;
        }
    }
    std::cout << count << std::endl;
    for (int i = 0; i < count; i++)
    {
        std::cout << runs[i] << " ";
    }
}