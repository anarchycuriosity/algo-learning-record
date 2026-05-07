// 在carl的讲解中提到>如果哈希值比较少、特别分散、跨度非常大，使用数组就造成空间的极大浪费。
// 前面我们解决的是单词和字母的问题,所以datasize其实并不复杂,数据跨度不大,我们可以使用数组
// 但如果数据跨度很大,比如1,100,99999这三个数,如果需要装到"桶"中,也就是数组中
// 我们会发现需要开拓一个至少99999大小的数组,但我们其实完全用不到这三个数据以外的部分,这就是浪费
// 在数组的合并中,我们引入一种结构体set
// set系列的set和multiset底层实现是红黑树,unordered_set的底层实现是哈希表,使用后者的读写效率是最高的
// 而且还不要让数据重复

#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        std::unordered_set<int> res;
        unordered_set num1_set(nums1.begin(), nums1.end());
        for (int num : nums2)
        {
            if (num1_set.find(num) != num1_set.end())
            {
                res.insert(num);
            }
        }
        return std::vector<int>(res.begin(), res.end());
    }
};