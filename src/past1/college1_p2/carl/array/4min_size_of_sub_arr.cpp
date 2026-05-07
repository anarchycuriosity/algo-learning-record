/*
给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。
*/
#include <algorithm>
#include <vector>
#include <iostream>
class Solution
{
public:
    // 很显然如果使用两个for循环就超时了
    // 所以我们引入滑动窗口的方法
    int vio(int target, std::vector<int> nums)
    {
        int vio = 1e9;
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            int count = 0;
            for (int j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                count++;
                if (sum >= target)
                {
                    vio = std::min(vio, count);
                    break;
                }
            }
        }
        if (vio != 1e9)
        {
            return vio;
        }
        else
        {
            return 0;
        }
    }
    // 在一次遍历无法减少的情况下，我们不妨想象
    // 第一根指针拖着第二根指针向前遍历
    // 第二根指针被拖动的条件就是精妙之处，同时还有状态的变更
    // 本质其实也是双指针，双指针的本质就是在触发某种条件的时候
    // 第二根指针才开始移动
    int minSubArrayLen(int target, std::vector<int> &nums)
    {
        int res = INT32_MAX;
        int i = 0; // 第二根指针
        int sum = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            sum += nums[j];
            while (sum >= target)
            {
                res = (res > j - i + 1) ? (j - i + 1) : res;
                sum -= nums[i];
                i++;
            }
        }
        if (res == INT32_MAX)
        {
            return 0;
        }
        else
        {
            return res;
        }
    }
};
int main()
{
    int target = 7;
    std::vector<int> nums = {2, 3, 1, 2, 4, 3};
    Solution sol;
    std::cout << sol.minSubArrayLen(target, nums);
}