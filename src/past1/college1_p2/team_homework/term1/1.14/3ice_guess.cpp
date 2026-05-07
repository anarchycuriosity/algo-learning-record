// 递归失败了
#include <bits/stdc++.h>
void recurse(int n, std::vector<int> &vec)
{
    vec.emplace_back(n);
    if (n == 1)
    {
        return;
    }
    if (n % 2 != 0)
    {
        recurse(3 * n + 1, vec);
    }
    else
    {
        recurse(n / 2, vec);
    }
}
int main()
{
    int n;
    std::cin >> n;
    std::vector<int> vec;
    recurse(n, vec);
    for (int i = vec.size() - 1; i >= 0; i--)
    {
        std::cout << vec[i] << " ";
    }
}