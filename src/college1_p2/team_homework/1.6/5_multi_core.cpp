#include <bits/stdc++.h>
int solve_one(std::vector<int> course)
{
    int sum_t = 0;
    int n = course.size();
    for(int t : course)
    {
        sum_t += t;
    }
    int l = sum_t / 2;
    std::vector<int> dp(l+1,0);
    for(int t:course)
    {
        for(int cap = l;cap >=t;cap--)
        {
            dp[cap] = std::max(dp[cap],dp[cap - t] + t);
        }
    }
    int l_t = dp[l];
    int r_t = sum_t - l_t;
    return std::max(l_t,r_t);
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int s1,s2,s3,s4;
    std::cin >> s1 >> s2 >> s3 >> s4;
    std::vector<int> course1(s1);
    std::vector<int> course2(s2);
    std::vector<int> course3(s3);
    std::vector<int> course4(s4);
    for(int i = 0;i < s1;i++)
    {
        std::cin >> course1[i];
    }
    for(int i = 0;i < s2;i++)
    {
        std::cin >> course2[i];
    }
    for(int i = 0;i < s3;i++)
    {
        std::cin >> course3[i];
    }
    for(int i = 0;i < s4;i++)
    {
        std::cin >> course4[i];
    }
    int sum = 0;
    sum += solve_one(course1);
    sum += solve_one(course2);
    sum += solve_one(course3);
    sum += solve_one(course4);
    std::cout << sum;
}