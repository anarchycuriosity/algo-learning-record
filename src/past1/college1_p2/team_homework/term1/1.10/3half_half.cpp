#include <bits/stdc++.h>
int main()
{
    int len;
    std::cin >> len;
    int time = 0;
    while(len != 1)
    {
        len /= 2;
        time++;
    }
    std::cout << time + 1;
}