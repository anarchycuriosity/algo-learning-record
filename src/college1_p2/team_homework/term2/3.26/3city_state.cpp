#include <bits/stdc++.h>
#define ll long long

ll setHash(std::string s)
{
    ll res = 0;
    for (int i = 0; i < 2; i++)
    {
        res += res * 13331 + (ll)s[i];
    }
    return res;
}
class cs_hash
{
public:
    ll hash_ci;
    ll hash_st;

    cs_hash(std::string ci, std::string st)
    {
        hash_ci = setHash(ci);
        hash_st = setHash(st);
    }
};
// 必须边读边找不然就超时了
// 利用unordered_map来快速查找
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::vector<cs_hash> table;
    for (int i = 0; i < n; i++)
    {
        std::string ci;
        std::string st;
        std::cin >> ci >> st;
        table.push_back({ci, st});
    }
    int pairs = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (table[i].hash_ci == table[j].hash_st && table[i].hash_st == table[j].hash_ci)
            {
                pairs++;
            }
        }
    }
    std::cout << pairs;
}