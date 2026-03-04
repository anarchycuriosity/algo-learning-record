#include <iostream>

int main()
{
    int all = 0;
    int now_peach = 1;
    for(int i = 0;i < 10;i++)
    {
        all = (now_peach + 1) * 2;
    }
    std::cout << all;
}