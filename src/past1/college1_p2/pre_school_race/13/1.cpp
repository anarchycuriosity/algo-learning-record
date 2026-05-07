// 在给定的长度为 $n$ 的字符串 $s$ 中，统计子串 "hfut" 出现的次数

// 直接暴力吧
// 其实可以用substr优化
#include <bits/stdc++.h>
using namespace std;
#define maxl 100003
char str[maxl];
int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> str[i];
    }
    int count = 0;
    char fut[3] = {'f', 'u', 't'};
    for (int i = 0; i < n - 4; i++)
    {
        if (str[i] == 'h')
        {
            int act = 0;
            for (int j = i + 1; j <= i + 3; j++)
            {
                if (str[j] != fut[j - i - 1])
                {
                    break;
                }
                else
                {
                    act++;
                }
            }
            if (act == 3)
            {
                count++;
            }
        }
    }
    std::cout << count;
}