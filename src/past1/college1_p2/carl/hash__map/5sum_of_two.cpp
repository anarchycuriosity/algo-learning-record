
#include <vector>
#include <unordered_map>
using namespace std;
// 给定数组，已知目标和，求两数下标
// Q:为什么要使用map而不使用set
// A:因为在找cp的另一个数的时候需要值,但是又需要返回下标,一个是value,一个是key,使用map刚好合适
// 同时因为不能重复,我们在unordered_map和map里面选

// map和multimap有序,但是map的key不可重复,后者的key可以重复
// unordered_map无序,key也不能重复
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        std::unordered_map<int, int> map;
        // 这里一定要用for循环,因为要使用下标
        for (int i = 0; i < nums.size(); i++)
        {
            int cpnum = target - nums[i];
            auto it = map.find(cpnum);
            if (it != map.end())
            {
                return {it->second, i};
            }

            map.insert(pair<int, int>(nums[i], i));
            // pair是一个标准库提供的结构体模板,组成一个单元
            // 这样也可以map.insert({nums[i], i});
        }
        return {};
    }
};