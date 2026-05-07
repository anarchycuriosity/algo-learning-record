#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
// 哈希：让独特的字符串有唯一对应的哈希值
// 哈希算法：使用进制哈希
// 当然，有时会出现虽然哈希值一样但是字符串其实不一样
// 我们使用多值哈希，如果算法1一样那就再比较算法2
int getHash1(std::string &s)
{
    int hash_code = 0;
    for (int i = 0; i < s.size(); i++)
    {
        // pow会返回浮点数值
        // base小很容易就哈希冲突
        hash_code += (int)s[i] * (int)std::pow(131, i);
    }
    return hash_code;
}
int getHash2(std::string &s)
{
    int code = 0;
    for (int i = 0; i < s.size(); i++)
    {
        code += (int)s[i] * (int)std::pow(13331, i);
    }
    return code;
}
int main()
{
    int n;
    std::cin >> n;
    std::vector<std::string> strings;
    std::vector<int> hashTable(n, 0);
    for (int i = 0; i < n; i++)
    {
        std::string s;
        std::cin >> s;
        strings.push_back(s);
        hashTable[i] = getHash1(s);
    }
    // sort来去重会导致错误，因为和原顺序不符合
    // std::sort(hashTable.begin(), hashTable.end());
    int count = 0; // 数相同的
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (hashTable[i] == hashTable[j])
            {
                if (getHash2(strings[i]) == getHash2(strings[j]))
                {
                    count++;
                }
            }
        }
    }
    if (count == n - 1)
    {
        std::cout << 0;
        return 0;
    }
    std::cout << n - count;
}