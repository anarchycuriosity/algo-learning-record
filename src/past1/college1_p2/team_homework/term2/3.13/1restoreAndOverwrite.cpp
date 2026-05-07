#include <bits/stdc++.h>
// 其实没那么复杂，只要有人民碎片，就一定有一个人民
// 但是检查的i位置一定是起始的位置，也就是i一定对应b，i+1一定对应o
// i是起始位置,所以不会出现b算一次，o也算一次
// 其实本题也是贪心思想的一种变体，局部贡献分析，固定长度的窗口枚举
int main()
{
    std::string s;
    std::cin >> s;
    int countB = 0;
    int countG = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (i + 2 < s.size())
        {
            if (s[i] == 'b' || s[i + 1] == 'o' || s[i + 2] == 'y')
            {
                countB++;
            }
        }
        if (i + 3 < s.size())
        {
            if (s[i] == 'g' || s[i + 1] == 'i' || s[i + 2] == 'r' || s[i + 3] == 'l')
            {
                countG++;
            }
        }
    }
    std::cout << countB << std::endl
              << countG;
}