#include <bits/stdc++.h>

struct Day
{
    int fir;
    int sec;
    //他不会实时变化
    //int sum = fir + sec;
    int sum;
};
int main()
{
    std::vector<Day> days;
    for(int i = 0;i < 7;i++)
    {
        Day day;
        std:: cin >> day.fir >> day.sec;
        day.sum = day.fir + day.sec;
        days.emplace_back(day);
    }
    int index = 0;
    int bad = days[index].sum;
    for(int i = 0;i < 7;i++)
    {
        if(days[i].sum > bad)
        {
            bad = days[i].sum;
            index = i;
        }
    }
    if(bad > 8)
    {
        std::cout << index + 1;
    }
    else
    {
        std::cout << 0;
    }
}