#include <iostream>
// 本题的重点就是判断点的差值满足什么关系
// 相等就是正方形吗，否则长方形
int main()
{
    int n, m;
    int count_sq = 0, count_rectangle = 0;
    std::cin >> n >> m;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int k = i + 1; k <= n; k++)
            {
                for (int l = j + 1; l <= m; l++) // 其实就是在一个点处展开两条线呈现直角
                {
                    if (k - i == l - j)
                    {
                        count_sq++;
                    }
                    else
                    {
                        count_rectangle++;
                    }
                }
            }
        }
    }
    std::cout << count_sq << " " << count_rectangle;
    // 当然此时的复杂度有点夸张，可以改进
}