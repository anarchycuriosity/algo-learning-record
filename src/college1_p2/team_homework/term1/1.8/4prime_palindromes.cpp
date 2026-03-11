#include <bits/stdc++.h>
bool is_prime(int num)
{
    if(num <2) return false;
    if(num == 2) return true;
    if(num % 2 == 0) return false;
    //不要用i <=num,不要对每个偶数都用一次for
    //同时注意这里的取等
    for(int i = 3;i * i <= num;i+=2)
    {
        if(num % i == 0)
        {
            return false;
        }
    }
    return true;
}
bool is_palin(int num)
{
    std::string str = std::to_string(num);
    int size = str.size();
    for(int i = 0;i < size / 2;i++)
    {
        if(str[i] != str[size - 1 - i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int a,b;
    std::cin >> a >> b;
    //回文数的检查只对非偶数位
    //偶数位回文数一定能被11整除
    for(a; a <= b; a++)
    {
        int len = std::to_string(a).size();
        if(len % 2 == 0 && a != 11) continue;
        
        if(is_palin(a) && is_prime(a))
        {
            std::cout << a << "\n";
        }
    }
}