#include <bits/stdc++.h>
// 使用next_permutation会TLE，慎用
// 还有这个版本也不能解决问题，因为合并的两堆果子不一定是前面合并过一次的那个果堆
// 新合并的果堆可能比右边的两个果堆要大
//  就比如三堆果子，a跟地球一样大，b，c和灰尘一样小。最终合并。
// 如果我先合并b，c再合a，只要和地球接触一次。如果先合并a与b或者c，我就要和地球接触两次
// 局部最优最终得到全局最优
int main()
{
    int n;
    std::cin >> n;
    std::vector<int> fruits(n, 0);
    for (int i = 0; i < n; i++)
    {
        std::cin >> fruits[i];
    }
    std::sort(fruits.begin(), fruits.end());
    int min = (int)std::pow(2, 31) - 1;

    int cost = 0;
    std::stack<int> mid;
    std::stack<int> st_fru;
    for (int i = fruits.size() - 1; i >= 0; i--)
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
    std::cout << min;
}