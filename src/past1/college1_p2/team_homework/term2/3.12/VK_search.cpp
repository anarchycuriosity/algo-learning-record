#include <bits/stdc++.h>
int main()
{
    int n;
    std::string s;
    std::cin >> n >> s;
    // 本题涉及一个贪心算法
    // 需要先处理掉已有的干扰项
    // 比如VVK，如果我们检测到VV然后改动为VK，其实数量没有发生变化，所以我们需要标记不需要更改的部分
    // 否则就是拆东墙补西墙

    // 第一次扫描标记错误的
    int count = 0;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == 'V' && s[i + 1] == 'K')
        {
            s[i] = 'X';
            s[i + 1] = 'X';
            count++;
        }
    }
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == 'V' && s[i + 1] == 'V')
        {
            count++;
            break;
        }
        else if (s[i] == 'K' && s[i + 1] == 'K')
        {
            count++;
            break;
        }
    }
    std::cout << count;
}