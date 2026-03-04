#include <bits/stdc++.h>
bool is_prime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int L;
    std::cin >> L;
    if (L < 2)
    {
        std::cout << 0;
        return 0;
    }
    else if (L > 2 && L < 5)
    {
        std::cout << 2 << std::endl;
        std::cout << 1;
        return 0;
    }
    std::cout << 2 << "\n";
    std::vector<int> poc{2};
    int i = 3;
    int sum = 2;
    // while (sum < L)这里特别容易错，会多放
    while (sum + i <= L)
    {
        if (is_prime(i))
        {
            sum += i;
            poc.emplace_back(i);
            std::cout << i << std::endl;
        }
        i += 2;
    }
    std::cout << poc.size();
}