#include <vector>
#include <iostream>
// 冒泡排序的本质是相邻比较，每一轮循环对比j和j+1，如果前面大就交换
// 问题在于他会不断的交换位置，动作很频繁
// 选择排序的核心思想是定位最小
// 每一轮在未排序区间找到最小值的下标，整轮结束后只进行一次交换
// 与冒泡相比，交换次数少的多，每轮最多一次
std::vector<int> bub(std::vector<int> nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i; j < nums.size() - 1; j++) // 这里应该是-1
        {
            if (nums[j] < nums[j + 1])
            {
                // 这里有越界的风险
                // std::swap(nums[j], nums[j + 1]);
                std::swap(nums[j], nums[j + 1]);
            }
        }
    }
    std::vector<int> tmp;
    for (int i = nums.size(); i >= 0; i--)
    {
        tmp.push_back(nums[i]);
    }
    return tmp;
}
std::vector<int> sel(std::vector<int> nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        // int min = 1e9;
        int min_ind = i;
        for (int j = i; j < nums.size(); j++)
        {
            // 需要交换而不是覆盖
            // 值并不重要重要的是记录下标
            // min = (nums[j] < min) ? nums[j] : min;
            if (nums[j] < nums[min_ind])
            {
                min_ind = j;
            }
        }
        // nums[i] = min;
        // 每一轮结尾就进行交换
        std::swap(nums[min_ind], nums[i]);
    }
    // 曾经忘记写返回值
    return nums;
}
int main()
{
    std::vector<int> nums = {9, 8, 7, 4, 5, 6, 3, 1, 2};
    for (int i = 0; i < 9; i++)
    {
        std::cout << bub(nums)[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < 9; i++)
    {
        std::cout << sel(nums)[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < 9; i++)
    {
        std::cout << nums[i] << " ";
    }
}