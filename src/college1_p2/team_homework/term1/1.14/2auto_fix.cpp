#include <bits/stdc++.h>
int main()
{
    std::string str;
    std::cin >> str;
    // 这里必须加&
    for (char &ch : str)
    {
        if (ch >= 'a' && ch <= 'z')
        {
            ch -= 32;
        }
    }
    std::cout << str;
}