/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
你会得到两个整数组 nums1 和 nums2，按非递减顺序排列，以及两个整数 m 和 n，分别表示 nums1 和 nums2 中的元素数。

Merge nums1 and nums2 into a single array sorted in non-decreasing order.
将 nums1 和 nums2 合并为一个按非递减顺序排序的数组。

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
最终排序后的数组不应由函数返回，而是存储在数组 nums1 中。为适应此，nums1 的长度为 m + n，前 m 个元素表示应合并的元素，后面 n 个元素设为 0，应忽略。nums2 的长度为 n。
*/
#include <iostream>
#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) 
    {
        /*
        int complete = m + n - nums1.size();
        if(complete > 0)
        {
            for(int i = 0;i < complete;i++)
            {
                nums1.emplace_back(0);
            }
        }
        for(int i = m + 1;i < m + n;i++)
        {
            for(int j = 0;j < n;j++)
            {
                nums1[i] = nums2[j];
            }
        }
        */
       //下面这个方法超时了，因为题目给的数组已经是非递减排序了，频繁插入挺耗时的
       /*
       for(int i = 0;i < n;i++)
       {
            int left = 0,right = m - 1;
            int tar = nums2[i];
            while(left <= right)
            {
                int mid = left + (right - left) / 2;
                if(nums1[mid] == tar)
                {
                    nums1.insert(nums1.begin() + mid + 1,tar);
                }
                else if(nums1[mid] < tar)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
            nums1.insert(nums1.begin() + left,tar);
       }
        */
       //这里引入一个双指针从后向前合并的方法
       int i = m - 1;
       int j = n - 1;
       int k = m + n - 1;
       //依旧不确定什么时候停, 主要是i和j都要减就比较复杂了
       while(j >= 0)
       {
            if(i >= 0 && nums1[i] > nums2[j])
            {
                nums1[k--] = nums1[i--];
            }
            else
            {
                nums1[k--] = nums2[j--];
            }
       }
    }
};