#include <bits/stdc++.h>
bool is_prime(int num)
{
    for(int i = 2;i < num;i++)
    {
        if(num % i == 0)
        {
            return false;
        }
    }
    return true;
}
void print(int num)
{
    int find = 0;
    int i = 2;
    while(find == 0 && i <= num)
    {
        int complete = num - i;
        if(is_prime(i) && is_prime(complete))
        {
            std::cout << num << "=" << i << "+" << complete << "\n";
            find = 1;
        }
        i++;
    }
}
int main()
{
    int N;
    std::cin >> N;
    if(N <= 4 || N % 2 != 0)
    {
        return 0;
    }
    for(int i = 4;i <= N;i += 2)
    {
        print(i);
    }
}