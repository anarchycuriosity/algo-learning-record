// 我们也许应该反过来
// 其实最初是没有好好读题目
// 我们应该用一个map，key是询问的单词，value是在哪个组出现过
// 反正不用统计次数

#include <unordered_map>
#include <iostream>
#include <string>
#include <map>
#include <vector>
int main()
{
    int N;
    std::cin >> N;
    std::map<std::string, std::vector<int>> diction;
    for (int i = 1; i <= N; i++)
    {
        int L;
        std::cin >> L;
        for (int j = 0; j < L; j++)
        {
            std::string str;
            std::cin >> str;

            diction[str].push_back(i);
        }
    }
    int M;
    std::cin >> M;
    std::string ques[M];
    for (int i = 0; i < M; i++)
    {
        std::cin >> ques[i];
    }
    for (int i = 0; i < M; i++)
    {
        if (!diction[ques[i]].empty())
        {
            for (int j = 0; j < diction[ques[i]].size(); j++)
            {
                std::cout << diction[ques[i]][j] << " ";
            }
            std::cout << std::endl;
        }
    }
}