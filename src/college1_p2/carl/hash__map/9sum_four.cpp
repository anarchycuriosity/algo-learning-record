#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 剪枝的核心逻辑只有一句话：如果当前这一步已经注定无法达成目标，就赶紧停下。
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        // 两层for循环，每层for循环进行剪枝和去重操作
        // 不需要一个容器去装前两个数了，因为i和j已经标记他们了
        // 剪枝逻辑因为target而变得不太一样：如果当前的数的和比target大，而且大于0
        // 因为nums已经排序过了，所以后面的数不可能大组成target了
        // 这是为了防止全是负数的情况下，target依然有被组成的可能，捡到负数和捡到正数是完全不一样的
        // 捡到负数就变小了
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        for (int i = 0; i < nums.size(); i++)
        {
            // 先剪枝
            if (nums[i] > target && nums[i] >= 0)
            {
                break;
            }
            // 去重
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            for (int j = i + 1; j < nums.size(); j++)
            {
                if ((long)nums[i] + nums[j] > target && nums[i] + nums[j] >= 0)
                {
                    break;
                }
                if (j > i + 1 && nums[j] == nums[j - 1]) // 一定要加起始位置判定，不然可能会因为i而误去重
                {
                    continue;
                }
                int left = j + 1, right = nums.size() - 1;
                while (left < right)
                {
                    // 这里的long不要忘记加，不然吃红牌
                    if ((long)nums[i] + nums[j] + nums[left] + nums[right] < target)
                    {
                        left++;
                    }
                    else if ((long)nums[i] + nums[j] + nums[left] + nums[right] > target)
                    {
                        right--;
                    }
                    else
                    {
                        // while内部的while循环也许应该为了防止做的太多了应该要嵌套上外层while的条件
                        // 对双指针去重
                        while (left < right && nums[left] == nums[left + 1])
                        {
                            left++;
                        }
                        while (left < right && nums[right] == nums[right - 1])
                        {
                            right--;
                        }
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        right--;
                        left++;
                    }
                }
            }
        }
        return res;
    }
};