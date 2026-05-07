/*
如果暴力遍历复杂度是O(n*n),因为需要找重复的数，所以我们考虑
一条路走到黑，只遍历一次，遍历了就存进去
*/
#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> two_sum(std::vector<int> &nums,int target)
{
    std::unordered_map<int,int> seen;
    for(std::vector<int>::iterator it = nums.begin();it != nums.end();it++)
    {
        int complete = target - *it;
        //if(std::find(seen.begin(),seen.end(),complete) != seen.end())
        //这里用find不太好，因为find不能对unordered_map使用，不妨使用unordered_map本身的find函数
        if(seen.find(complete) != seen.end())
        {
            //return {seen[complete],it - nums.begin()};
            //隐式构造会报错
            return std::vector<int>{seen[complete],static_cast<int>(it - nums.begin())};
        }
        seen[*it] = static_cast<int>(it - nums.begin()); 
    }
    return {};
    //返回一个空，总得返回点东西
}
int main()
{
    //std::cout << "请输入数组长度并且输入数组\n";
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for(int i = 0; i < n;i++)
    {
        int num;
        std::cin >> num;
        nums[i] = num;
    }
    int tar;
    //std::cout << "请输入目标\n";
    std::cin >> tar;
    std::vector<int> res =  two_sum(nums,tar);
    std::cout << res[0] << " " << res[1];

}