#include <bits/stdc++.h>
//第一次尝试：把所有的combines都塞进combines然后找最大值，优化方法是只对max维护。
//这确实减少了一部分的RE，取而代之的是超时判的WA，变好了一点但不多
//next_permutation的时间复杂度过于高了，
//拼接字符串成为long long的时候很大概率会爆，因为数字本来就很多
int main()
{
    int n;
    std::cin >> n;
    std::vector<std::string> nums(n);
    for(int i = 0;i < n;i++)
    {
        std::cin >> nums[i];
    }
    //如果选择存secs，可能会爆掉。
    //std::vector<long long> secs;
    long long max = 0;
    std::sort(nums.begin(), nums.end());
    do
    {
        long long combine;
        std::string str;
        for(std::string num : nums)
        {
            str += num;
        }
        combine = std::stoll(str);
        max = std::max(max,combine);
    }
    while(std::next_permutation(nums.begin(),nums.end()));
    std::cout << max;
}