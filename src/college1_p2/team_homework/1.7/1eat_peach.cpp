#include <bits/stdc++.h>
int main()
{
    int n;
    std::cin >> n;
    int sum = 1;
    for(int i = 0;i < n - 1;i++)
    {
        sum = (sum + 1)  * 2;
    }
    std::cout << sum;
}