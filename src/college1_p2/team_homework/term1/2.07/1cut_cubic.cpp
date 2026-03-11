#include <iostream>
#include <vector>
#include <algorithm>
// 一定要记得看题目变量的区间啊，以及是0开始索引或者1开始索引
int main()
{
    int w, x, h;
    std::cin >> w >> x >> h;
    std::vector<std::vector<std::vector<int>>> cubic(w, std::vector<std::vector<int>>(x, std::vector<int>(h, 0)));
    int n;
    std::cin >> n;
    while (n--)
    {
        int x1, y1, z1, x2, y2, z2;
        std::cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        for (int i = x1 - 1; i <= x2 - 1; i++) // 这里有越界的风险
        {
            for (int j = y1 - 1; j <= y2 - 1; j++)
            {
                for (int k = z1 - 1; k <= z2 - 1; k++)
                {
                    // count++;如果是多次覆盖就废了
                    // 所以后面的n^3是不可缺少的
                    // 其实加个判断就可以不用多写一个n^3
                    cubic[i][j][k] = 1;
                }
            }
        }
    }
    int count = 0;
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < x; j++)
        {
            for (int k = 0; k < h; k++)
            {
                if (cubic[i][j][k] == 0)
                {
                    count++;
                }
            }
        }
    }

    std::cout << count;
}