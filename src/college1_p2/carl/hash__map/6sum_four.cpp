#include <vector>
#include <unordered_map>
using namespace std;
// 有趣的一点是,我们并不需要对abcd数组采取一样的措施,或者说对ab和对cd采取的措施不一样
// 本体要求从四个数组中各取一个元素找到和为0的组合的数量
// 假如先查ab再查cd,cd属于临门一脚,不需要再花费一个unordered_map
class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        std::unordered_map<int, int> umap; // key存数字,val存出现次数
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                int sum = nums1[i] + nums2[j];
                umap[sum]++;
            }
        }
        int count = 0;
        for (int c : nums3)
        {
            for (int d : nums4)
            {
                if (umap.find(0 - c - d) != umap.end())
                {
                    count += umap[0 - c - d];
                }
            }
        }
        return count;
    }
};