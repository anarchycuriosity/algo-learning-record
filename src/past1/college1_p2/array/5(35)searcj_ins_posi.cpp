/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
给定一个已排序的数组和一个目标值，如果找到目标，返回该索引。如果没有，则返回按顺序插入时应在的位置。

You must write an algorithm with O(log n) runtime complexity.
你必须编写一个运行时复杂度为 O（log n） 的算法。
*/
//这其实就是二分查找的雏形
//常见的算法复杂度里，能稳定做到O（logn）的几乎就是二分查找及其变体
//二分查找不仅能够找到目标还能找到应该插入的位置
//有序数组->二分查找

//问题：边界判断不是很准
/*
当 nums[mid] < target 时，说明目标值一定在 右半部分。

因为 mid 这个位置已经检查过了，并且它比目标小，所以目标不可能在 mid。

所以我们把搜索区间缩小到右边：left = mid + 1。

 直观理解：排除掉 mid 以及它左边的部分，只保留右边。

 为什么 right = mid - 1
当 nums[mid] > target 时，说明目标值一定在 左半部分。

因为 mid 已经检查过了，并且它比目标大，所以目标不可能在 mid。

所以我们把搜索区间缩小到左边：right = mid - 1。

 直观理解：排除掉 mid 以及它右边的部分，只保留左边。
*/
//为什么一定是left<=right呢，=号有什么说法
/*
比如1 3 5 找5 left = 0.right = 2,mid = 1;
left = 2.right = 2,mid = 2;如果是=依然会检查这个元素，哪怕只剩下一个
如果不写=就检查不到了
*/

#include <iostream>
#include <vector>
class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) 
    {
        int left = 0,right = nums.size() - 1;
        while(left <= right)
        {
            //int mid = (left + right) / 2;
            //做点什么来防止溢出
            int mid = left + (right - left) / 2;
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] < target)
            {
                left = mid + 1;
            }
            else if(nums[mid] > target)
            {
                right = mid - 1;
            }
        }
        return left;
    }
};