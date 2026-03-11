#include <bits/stdc++.h>
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
    vec.emplace_back(1);
    for (int i = 2; i <= N; i++)
    {
        int aim, choice;
        std::cin >> aim >> choice;
        int pos = std::find(vec.begin(), vec.end(), aim) - vec.begin();
        if (choice == 0)
        {
            vec.insert(vec.begin() + pos, i);
        }
        else
        {
            vec.insert(vec.begin() + pos + 1, i);
        }
    }
    int exe_time;
    std::cin >> exe_time;
    while (exe_time--)
    {
        int i;
        std::cin >> i;
        auto it = std::find(vec.begin(), vec.end(), i);
        if (it == vec.end())
        {
            continue;
        }
        vec.erase(it);
    }
    print(vec);
}