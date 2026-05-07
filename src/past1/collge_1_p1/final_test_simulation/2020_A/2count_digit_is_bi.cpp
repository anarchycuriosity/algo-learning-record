#include <iostream>
#include <string>
#include <vector>
int main()
{
    std::vector<int> nums;
    int amount;
    std::cin >> amount;
    for(int i = 0;i < amount;i++)
    {
        int num;
        std::cin >> num;
        nums.emplace_back(num);
    }
    int count = 0;
    for(int num : nums)
    {
        std::string num_str = std::to_string(num);
        int digit = num_str.size() - 1;
        if(digit % 2 == 0)
        {
            count++;
        }
    }
    std::cout << count;
    return 0;
    
}