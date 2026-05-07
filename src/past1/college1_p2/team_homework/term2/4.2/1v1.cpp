// 思路错了，没有考虑如果没有一家电影院使用最热门语言

// 本题的难度其实主要在于输入，他是连续输入n部电影的编号，如果数组开太大很容易爆掉
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <set>
struct Cine
{
    int voice;
    int sub;
};
int main()
{
    std::unordered_map<int, int> people; // 统计语言及其人数
    int n;                               // n个人
    std::cin >> n;
    int lang = 0;
    int max_lang;
    int max_amount = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> lang;
        people[lang]++;
        if (people[lang] > max_amount)
        {
            max_lang = lang;
            max_amount = people[lang];
        }
    }
    // 只有会的语言最多的语言是我们在意的，别的都不管
    int m; // m家影院
    std::cin >> m;
    std::set<int> firsts;
    int choose;
    for (int i = 1; i <= m; i++)
    {
        std::cin >> lang;
        if (lang == max_lang)
        {
            firsts.insert(i);
        }
    }

    // std::set<int> seconds;
    for (int i = 1; i <= m; i++)
    {
        std::cin >> lang;
        if (firsts.find(i) != firsts.end() && lang == max_lang)
        {
            std::cout << i;
        }
    }
}