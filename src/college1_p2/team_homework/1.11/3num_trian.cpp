#include <bits/stdc++.h>
int main()
{
    int n;
    std::cin >> n;
    int sum = 0;
    for(int i = 1;i <= n;i++)
    {
        sum += i;
    }
    std::vector<std::string> tank;
    for(int i = 1;i <= sum;i++)
    {
        std::string str;
        if(i <=9)
        {
            str = "0" + std::to_string(i);
            tank.emplace_back(str);
        }
        else
        {
            str = std::to_string(i);
            tank.emplace_back(str);
        }
    }
    int count = 0;
    for(int i = 0;i < n;i++)
    {
        int len = n - i;
        for(int j = 0;j < len;j++)
        {
            std::cout << tank[count];
            count++;
        }
        std::cout << std::endl;
    }
}