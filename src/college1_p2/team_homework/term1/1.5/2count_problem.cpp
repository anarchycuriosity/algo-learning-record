#include <iostream>
#include <vector>
#include <string>
int main()
{
    int n,x;
    std::cin >> n >> x;
    std::vector<int> nums;
    int count = 0;
    for(int i = 1;i <= n;i++)
    {
        std::string i_str = std::to_string(i);
        for(int j = 0;j < i_str.size();j++)
        {
            int digit = i_str[j] - '0';
            nums.emplace_back(digit);
        }
    }
    for(int num:nums)
    {
        if(num == x)
        {
            count++;
        }
    }
    std::cout << count;
}