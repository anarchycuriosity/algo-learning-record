#include <bits/stdc++.h>
int main()
{
    int n;
    std::cin >> n;
    std::vector<int> fruits(n, 0);
    for (int i = 0; i < n; i++)
    {
        std::cin >> fruits[i];
    }
    int min = (int)std::pow(2, 31) - 1;
    do
    {
        int cost = 0;
        std::stack<int> mid;
        std::stack<int> st_fru;
        for (int i = 0; i < fruits.size(); i++)
        {
            st_fru.push(fruits[i]);
        }
        mid.push(st_fru.top());
        st_fru.pop();
        while (!st_fru.empty())
        {
            int merge = mid.top() + st_fru.top();
            mid.pop();
            st_fru.pop();
            cost += merge;
            mid.push(merge);
        }
        min = std::min(min, cost);
    } while (std::next_permutation(fruits.begin(), fruits.end()));
    std::cout << min;
}