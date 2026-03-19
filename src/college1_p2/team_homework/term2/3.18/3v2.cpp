#include <iostream>
#include <vector>
#include <algorithm>

struct race
{
    int start;
    int end;
};

// 比较函数只需要定义两个元素的先后逻辑
bool compare(const race &a, const race &b)
{
    return a.end < b.end;
}

int main()
{
    int n;
    if (!(std::cin >> n))
        return 0;

    std::vector<race> races;
    for (int i = 0; i < n; i++)
    {
        int start, end;
        std::cin >> start >> end;
        races.push_back({start, end});
    }

    std::sort(races.begin(), races.end(), compare);

    int count = 0;
    int current_end_time = 0; // 记录当前最后一场比赛的结束时间

    for (int i = 0; i < races.size(); i++)
    {
        // 着眼当下：如果这场比赛的开始时间不早于上一场的结束时间
        if (races[i].start >= current_end_time)
        {
            // 选它！因为它结束得早，对后面最有利
            count++;
            current_end_time = races[i].end;
        }
    }

    std::cout << count << std::endl;

    return 0;
}