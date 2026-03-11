#include <bits/stdc++.h>

int main()
{
    int n;
    std::cin >> n;
    int loc = 0,luo = 0;
    loc = 5 * n;
    luo = 3 * n + 11;
    std::cout << (loc > luo ? "Luogu" : "Local");
}