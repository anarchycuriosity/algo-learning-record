// > 数组在内存地址中是联系的,不能单独删除数组中的某个元素,只能覆盖
// > 数组的内存地址是连续的,跨越维度也是连续的,比如从1行到2行
// 在移除元素中,不需要考虑数组中超出新长度后面的元素
// 两种解法,双层for循环,双指针法
// vector是基于array写出来的,vector严格来说应该是容器
// 这两种方法都不改变相对顺序的意思是说,删完之后谁前谁后依然不变
#include <vector>
#include <iostream>
class Solution
{
public:
    int rm1(std::vector<int> &nums, int val)
    {
        int size = nums.size(); // 数组往后的部分,我们都不管了
        for (int i = 0; i < size; i++)
        {
            if (nums[i] == val)
            {
                for (int j = i + 1; j < size; j++)
                {
                    nums[j - 1] = nums[j];
                }
                i--;
                size--;
            }
        }
        return size;
    }
    int rm2(std::vector<int> &nums, int val) // 用一个for循环解决两个for循环的事情
    {
        // 快指针只承担遍历的工作,但而确认并覆盖的工作交给慢指针
        int slow_ind = 0;
        int size = nums.size();
        for (int fast_ind = 0; fast_ind < size; fast_ind++)
        {
            if (nums[fast_ind] != val)
            {
                nums[slow_ind++] = nums[fast_ind];
            }
        }
        return slow_ind;
    }
};