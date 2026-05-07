// 使用一些结构体来改进，因为原先进行多值哈希的时候查了两次
// 反正每个都要算一次，那不如写个结构体来存
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
long long getHash1(std::string &s)
{
    long long hash_code = 0;
    for (int i = 0; i < s.size(); i++)
    {
        // pow会返回浮点数值
        // base小很容易就哈希冲突
        hash_code = hash_code * 131 + (long long)(s[i]);
    }
    return hash_code;
}
long long getHash2(std::string &s)
{
    long long hash_code = 0;
    for (int i = 0; i < s.size(); i++)
    {
        hash_code = hash_code * 13331 + (long long)(s[i]);
    }
    return hash_code;
}
class str_hash
{
public:
    long long hash1;
    long long hash2;
    str_hash(std::string &_s)
    {
        hash1 = getHash1(_s);
        hash2 = getHash2(_s);
    }
};
int main()
{
    int n;
    std::cin >> n;
    std::vector<str_hash> table;
    for (int i = 0; i < n; i++)
    {
        std::string s;
        std::cin >> s;
        str_hash SH(s);
        table.push_back(SH);
    }
    std::sort(table.begin(), table.end(), [](str_hash &a, str_hash &b)
              { return a.hash1 <= b.hash1; });
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (table[i].hash1 == table[i + 1].hash1 && table[i].hash2 == table[i + 1].hash2)
        {
            continue;
        }
        else
        {
            count++;
        }
    }
    count++;
    // 这种计数法很有问题
    /*     if (count == n - 1)
        {
            std::cout << 0;
        } */

    std::cout << count;
}