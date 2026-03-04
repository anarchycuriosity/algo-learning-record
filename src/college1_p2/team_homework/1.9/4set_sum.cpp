#include <bits/stdc++.h>

int main()
{
    std::vector<int> set;
    int x;
    while(std::cin >> x)
    {
        set.emplace_back(x);
    }
    int n = set.size();
    long long total_sum = 0;
    for(long long i = 0;i < 1LL<<n;i++)
    {
        int sub_sum = 0;
        for(int j = 0;j < n;j++)
        {
            if(i & 1LL<<j)
            {
                sub_sum+= set[j];
            }
        }
        total_sum+=sub_sum;
    }
    std::cout << total_sum;
}