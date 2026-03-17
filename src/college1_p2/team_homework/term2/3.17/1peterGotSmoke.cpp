#include <iostream>

int main()
{
    int n, k;
    std::cin >> n >> k;
    int rest = n, count = 0, did = 0;
    // 每抽一根烟rest减少，若count到达k，rest++,did为确实抽到的烟
    while (rest--)
    {
        if (count == k)
        {
            rest++;
            count = 0;
        }
        count++;
        did++;
    }
    // 结尾需要补一次，因为可能吸完最后一根烟拿到烟蒂
    if (count == k)
    {
        did++;
    }
    std::cout << did;
}