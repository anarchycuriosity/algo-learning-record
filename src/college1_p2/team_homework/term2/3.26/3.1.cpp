// 我们需要边读边处理数据否则会爆炸的
// 虽然是字符哈希，但其实不考察底层
// 使用一些现成的数据结构即可
#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
int main()
{
    std::string ci, st;
    int N;
    std::cin >> N;
    // std::unordered_map<std::pair<std::string, std::string>, int> UM;这个不支持pair的小于号比较
    std::map<std::pair<std::string, std::string>, int> UM;
    int pair_count = 0;
    for (int i = 0; i < N; i++)
    {
        std::cin >> ci >> st;
        ci = ci.substr(0, 2);
        if (ci != st) // 万一城市名和省名相同就会多+，比如ORxx OR
        {
            // 这个挺巧妙的
            pair_count += UM[{st, ci}];
        }

        UM[{ci, st}]++;
    }
    std::cout << pair_count;
}