#include <unordered_map>
#include <iostream>
#include <map>
#include <vector>
int main()
{
    std::vector<std::map<std::string, int>> dictions;
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        std::map<std::string, int> dictionary;
        int L;
        std::cin >> L;
        for (int j = 1; j <= L; j++)
        {
            std::string str;
            std::cin >> str;
            dictionary[str]++;
        }
        dictions.push_back(dictionary);
    }
    int M;
    std::cin >> M;
    std::vector<std::string> ques(M, "");
    for (int i = 0; i < M; i++)
    {
        std::cin >> ques[i];
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (dictions[j][ques[i]] != 0)
            {
                std::cout << j + 1 << " ";
            }
        }
        std::cout << std::endl;
    }
}