#include <vector>
#include <algorithm>
#include <iostream>
/*
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.
给定一个整数组 num 按非递减顺序排序，先原位移除重复元素，使每个唯一元素只出现一次 。元素的相对顺序应保持不变。

Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number of unique elements k.
考虑 num 中唯一元素  的数量为 k。去除重复后，返回唯一元素 k 的数量。

The first k elements of nums should contain the unique numbers in sorted order. The remaining elements beyond index k - 1 can be ignored.
num 的 前 k 个元素应包含唯一编号，按排序顺序排列。索引 k-1 之后 的剩余元素可以忽略。
*/
class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) 
    {
        //oops要原位去重。双指针遍历，i指向最后一个唯一元素，j用来遍历数组
        if(nums.empty()) return 0;

        int i = 0;
        for(int j = 1;j < nums.size();j++)
        {
            if(nums[i] != nums[j])
            {
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};

int main()
{

}