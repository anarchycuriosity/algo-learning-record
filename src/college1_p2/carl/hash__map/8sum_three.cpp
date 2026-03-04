/*
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

注意： 答案中不可以包含重复的三元组。
*/
// 本题最难的其实是去重的过程
// 一开始的思路是先找两个数丢进一个vector,然后再去找第三个数,最后再在三元组里面去重,但这非常耗费时间
// 而且我必须返回具体的数,而不是下标或者组合数
// 如果坚持要用哈希来写,会有很多很复杂的剪枝操作和细节难以处理,面试的时候很容易出bug
// 个人想到:对于一个排序好的数组,具有很多意想不到的特性可以帮助解题
// 为什么当 nums[i] == nums[i-1] 的时候continue可以去重呢
// 因为这是一个排序好了的数组，i == i -1 去重意味着结束a的选拔时候把门关上，而i == i+1则意味着把路堵死
// 这题使用一个1+2指针，1指针从头遍历到尾巴，剩下两个left和right指针则在右侧的区间不断压缩去找数
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        std::vector<std::vector<int>> res;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            // 如果a>0就没必要算了
            if (nums[i] > 0)
            {
                break;
            }

            // 对a去重
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            // 接下来写双指针
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                if (nums[i] + nums[left] + nums[right] > 0)
                {
                    // 如果和大了，就缩右指针，否则提高左指针
                    right--;
                }
                else if (nums[i] + nums[left] + nums[right] < 0)
                {
                    left++;
                }
                else
                {
                    // 去重应该在找到每个三元组的时候去重
                    res.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[right] == nums[right - 1])
                    {
                        // 具体原理就是，结束的时候关门，如果前路还有一样的就不结束
                        right--;
                    }
                    while (left < right && nums[left] == nums[left + 1])
                    {
                        left++;
                    }
                    right--;
                    left++;
                }
            }
        }
        return res;
    }
};