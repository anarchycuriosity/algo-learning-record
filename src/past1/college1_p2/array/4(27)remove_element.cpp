/*
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.
给定整数组 nums 和整数 val，原位移除所有 val 出现在 num 中的元素。元素的顺序可以更改。然后返回 num 中不等于 val 的元素数 。

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:
考虑 num 中不等于 val 的元素数为 k，要被接受，你需要做以下几件事：

Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
修改数组 num， 使得 num 的前 k 个元素包含不等于 val 的元素。num 的剩余元素和 num 的大小都不重要。
Return k.  返回 k。
*/
#include <iostream>
#include <vector>
class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) 
    {
        if(nums.empty()) return 0;

        int j = 0;
        for(int i = 0;i < nums.size();i++)
        {
           if(nums[i] != val)
           {
            nums[j] = nums[i];
            j++;
           }
        }
        return j;
    }
};
int main()
{
    std::vector<int> nums(5);
    int val;
    for(int i = 0;i < 5;i++)
    {
        std::cin >> nums[i];
    }
    std::cin >> val;
    Solution sol;
    int k = sol.removeElement(nums,0);
    for(int i = 0;i <k;i++)
    {
        std::cout << nums[i];
    }
}