#include <bits/stdc++.h>
int main()
{
    std::map<int,int> num_count;
    int M,N;
    std::cin >> M >> N;
    for(int i = M;i<=N;i++)
    {
        std::string str = std::to_string(i);
        for(char ch : str)
        {
            int i_ch = ch - '0';
            num_count[i_ch]++;
        }
    }
    for(int i = 0;i < 10;i++)
    {
        std::cout << num_count[i] << " ";
    }
}