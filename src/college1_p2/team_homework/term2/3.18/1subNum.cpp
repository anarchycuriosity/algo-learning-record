#include <iostream>
// 由于一个数有三个sub，三合一的结构，考虑结构体
struct One
{
    int sub1;
    int sub2;
    int sub3;
};

bool Ok(One &one, int k)
{
    if (one.sub1 % k != 0 || one.sub2 % k != 0 || one.sub3 % k != 0)
    {
        return false;
    }
    return true;
}
int main()
{
    int k;
    std::cin >> k;
    for (int i = 1e4; i <= 3e4; i++)
    {
        One one;
        one.sub1 = i % 1000;
        one.sub2 = (i % 10000 - i % 10) / 10;
        one.sub3 = (i - i % 100) / 100;
        if (Ok(one, k))
        {
            std::cout << i << std::endl;
        }
    }
}