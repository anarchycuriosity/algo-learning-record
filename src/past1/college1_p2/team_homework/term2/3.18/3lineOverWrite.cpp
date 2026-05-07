// 循环问题，我们只考虑其中的一次，其他的都是由这种一般的推论
// 一定一定不要看的太远，着眼当下，后面延申都是复制
#include <iostream>
#include <vector>
#include <algorithm>
struct race
{
    int start;
    int end;
};
bool compare(race &a, race &b)
{
    return a.end <= b.end;
}
int main()
{
    int n;
    std::cin >> n;
    std::vector<race> races;
    for (int i = 0; i < n; i++)
    {
        int start, end;
        std::cin >> start >> end;
        races.push_back({start, end});
    }
    race a, b;
    std::sort(races.begin(), races.end(), compare(a, b));
    int count = 0;
    int i = 0;
    for (; i < races.size(); i++)
    {
    }
}
