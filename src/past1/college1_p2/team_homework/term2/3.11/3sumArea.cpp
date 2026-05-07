#include <vector>
#include <iostream>
int main()
{
    int N;
    std::cin >> N;
    std::vector<int> nums;
    for (int i = 0; i < N; i++)
    {
        int num;
        std::cin >> num;
        nums.push_back(num);
    }
    std::vector<int> sums;
    int sum = 0;
    sums.push_back(sum);
    for (int i = 0; i < nums.size(); i++)
    {
        // sums的i位置应该是前i-1的和
        sum += nums[i];
        sums.push_back(sum);
    }
    int m;
    std::cin >> m;
    std::vector<int> ans;
    while (m--)
    {
        int first;
        int end;
        std::cin >> first >> end;
        // 不必自加自减了，本身就代表了前first个数
        // 它包含了我要找的那个区间的末尾的数
        // 但是却不包含左端点的数，如果first不-1的话

        ans.push_back(sums[end] - sums[first - 1]);
    }
    for (int i = 0; i < ans.size(); i++)
    {
        std::cout << ans[i] << std::endl;
    }
}