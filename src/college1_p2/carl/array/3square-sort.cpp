// 如果使用先平方然后排序的办法，那么就是n  + nlogn的复杂度
// 但是数组本身是有序的，所以最大值**不在左边就在右边**
// 这么一说，是不是就有双指针的意思
/*
给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
*/

#include <iostream>
#include <vector>
class Solution
{
public:
    std::vector<int> sort_square(std::vector<int> &nums)
    {
        int ind1 = 0;
        int ind2 = nums.size() - 1;
        std::vector<int> res(nums.size(), 0);
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[ind1] * nums[ind1] > nums[ind2] * nums[ind2])
            {
                res[i] = nums[ind1] * nums[ind1];
                ind1++;
            }
            else if (nums[ind1] * nums[ind1] <= nums[ind2] * nums[ind2])
            {
                res[i] = nums[ind2] * nums[ind2];
                ind2--;
            }
        }
        return res;
    }
};
int main()
{
    std::vector<int> nums = {-4, -1, 0, 3, 10};
    Solution sol;
    std::vector<int> res = sol.sort_square(nums);
    for (int i = 0; i < res.size(); i++)
    {
        std::cout << res[i] << " ";
    }
}
