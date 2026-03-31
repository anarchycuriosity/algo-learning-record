// 使用布尔数组模拟线段涂抹
#include <iostream>
#include <algorithm>
int main()
{
    int n;
    std::cin >> n;
    // bool allday[1001] = {false};
    int a[n];
    int b[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i] >> b[i];
    }
    // for (int i = 0; i < n; i++)
    // {
    //     int start, end;
    //     std::cin >> start >> end;
    //     a[i] = start;
    //     b[i] = end;
    //     if (end > dayend)
    //     {
    //         dayend = end;
    //     }
    //     for (int j = start; j <= end; j++)
    //     {
    //         if (allday[j] != true)
    //         {
    //             allday[j] = true;
    //             count++;
    //         }
    //     }
    // }
    // 这样算覆盖时间不对，因为人和人之间可能会重合
    // 可以尝试完全暴力，开除一个就重新计算一次剩余时间
    //  int maxcount = count - (b[0] - a[0]);
    //  for (int i = 1; i < n; i++)
    //  {
    //      if (count - (b[i] - a[i]) > maxcount)
    //      {
    //          maxcount = count - (b[i] - a[i]);
    //      }
    //  }
    int maxcountreal = 0;
    int maxcount = 0;
    for (int i = 0; i < n; i++)
    {
        bool allday[1001] = {false};
        // for (int j = 0; j != i && j < n; j++) // 这么写会让循环中断
        for (int j = 0; j < n; j++)
        {
            if (j == i)
            {
                continue;
            }
            int start = a[j];
            int end = b[j];
            for (int k = start; k < end; k++) // tmd这里不能取等
            {
                if (allday[k] != true)
                {
                    allday[k] = true;
                    maxcount++;
                }
            }
        }
        maxcountreal = std::max(maxcount, maxcountreal);
        maxcount = 0;
    }
    std::cout << maxcountreal;
}