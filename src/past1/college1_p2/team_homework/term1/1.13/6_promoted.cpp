#include <bits/stdc++.h>
// 原版使用find会TLE，现在提速
// 屌用没有
void print(std::vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
}
int main()
{
    int N;
    std::cin >> N;
    std::vector<int> vec;
    std::unordered_map<int, int> pos_map; // 记录编号位置
    vec.emplace_back(1);
    pos_map[1] = 0;
    for (int i = 2; i <= N; i++)
    {
        int aim, choice;
        std::cin >> aim >> choice;
        int pos = pos_map[aim];
        if (choice == 0)
        {
            vec.insert(vec.begin() + pos, i);
            // 插入后更新位置映射
            for (int j = pos; j < vec.size(); j++)
                pos_map[vec[j]] = j;
        }
        else
        {
            vec.insert(vec.begin() + pos + 1, i);
            for (int j = pos + 1; j < vec.size(); j++)
                pos_map[vec[j]] = j;
        }
    }
    int exe_time;
    std::cin >> exe_time;
    while (exe_time--)
    {
        int i;
        std::cin >> i;
        if (!pos_map.count(i))
            continue; // 不存在就忽略
        int pos = pos_map[i];
        vec.erase(vec.begin() + pos);
        pos_map.erase(i);
        for (int j = pos; j < vec.size(); j++)
            pos_map[vec[j]] = j;
    }
    print(vec);
}
