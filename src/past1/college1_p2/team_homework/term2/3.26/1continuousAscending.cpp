#include <iostream>
#include <vector>
int main()
{
    int N;
    std::cin >> N;
    std::vector<int> tempers(N, 0);
    for (int i = 0; i < N; i++)
    {
        std::cin >> tempers[i];
    }
    int days = 1;
    int record = 1;
    for (int i = 1; i < N; i++)
    {
        if (tempers[i] >= tempers[i - 1])
        {
            days++;
        }
        else
        {
            record = record > days ? record : days;
            days = 1;
        }
    }
    // 如果一直上升忘记考虑这种情况了
    // 应该结尾补一刀
    record = record > days ? record : days;
    std::cout << record;
}