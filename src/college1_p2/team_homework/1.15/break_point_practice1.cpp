#include <iostream>
#include <vector>

void filter_negative_numbers(std::vector<int> &nums)
{
    // 提示：注意循环删除元素时，下标的变化
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] < 0)
        {
            nums.erase(nums.begin() + i);
        }
    }
}

int main()
{
    std::vector<int> my_data = {1, -2, -3, 4, -5, 6};

    filter_negative_numbers(my_data);

    for (int n : my_data)
    {
        std::string separator = (n == my_data.back()) ? "" : ", ";
        std::cout << n << separator;
    }
    std::cout << std::endl;

    return 0;
}