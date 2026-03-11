#include <bits/stdc++.h>
int main()
{
    std::vector<int> apples;
    for(int i = 0;i < 10;i++)
    {
        int apple;
        std::cin >> apple;
        apples.emplace_back(apple);
    }
    int hand;
    std::cin >> hand;
    if(hand < 100 || hand > 120)
    {
        return 0;
    }
    int chair = 30;
    int count = 0;
    for(int i = 0;i < 10;i++)
    {
        if(hand >= apples[i])
        {
            count++;
        }
        else
        {
            if(hand + chair >= apples[i])
            {
                count++;
            }
        }
    }
    std::cout << count;
}