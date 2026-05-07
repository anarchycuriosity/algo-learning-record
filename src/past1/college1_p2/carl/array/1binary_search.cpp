// 二分查找的前提，有序数组，只有唯一元素
// 二分查找有两种版本，取决于区间是tar所在的区间是双闭或者左闭右开
// 也许要问为什么没有别的情况,如果有需要更复杂的讨论比如left + 1 < right,但没必要
// 而STL标准库中所有的迭代器范围都是左闭右开,比如vec.begin()指向第一个元素,而vec.end()指向最后一个元素之后的位置

#include <vector>
#include <iostream>
class Solution
{
public:
    int search1(std::vector<int> &nums, int tar)
    {
        int left = 0, right = nums.size() - 1; // 这里-1
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > tar)
            {
                right = mid - 1;
            }
            else if (nums[mid] < tar)
            {
                left = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
    int search2(std::vector<int> &nums, int tar)
    {
        int left = 0, right = nums.size(); // 这里没有-1
        while (left < right)               // 因为left == right的时候，在[left, right)是无效的空间，所以使用 <
        {
            // 需要根据区间做边界处理,比如[5,5)的时候就应该退出,如果继续查,本来就没有
            int mid = left + (right - left) / 2;
            if (nums[mid] < tar)
            {
                left = mid + 1;
            }
            else if (nums[mid] > tar)
            {
                // right = mid - 1;这里容易写错
                right = mid;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
};

int main()
{
    Solution solution;

    // 准备测试数据
    std::vector<int> test_nums = {-1, 0, 3, 5, 9, 12};

    // 我们定义一个测试列表：{目标值, 预期下标}
    struct TestCase
    {
        int target;
        int expected;
    };

    std::vector<TestCase> cases = {
        {9, 4},  // 情况1：在右半部分
        {-1, 0}, // 情况2：在开头
        {12, 5}, // 情况3：在结尾
        {2, -1}, // 情况4：不存在于数组中（中间缺失）
        {13, -1} // 情况5：大于数组最大值
    };

    std::cout << "--- 开始测试 search1 (左闭右闭 [left, right]) ---" << std::endl;
    for (const auto &c : cases)
    {
        int result = solution.search1(test_nums, c.target);
        std::cout << "Target: " << c.target << " | Result: " << result
                  << (result == c.expected ? " [PASS]" : " [FAIL]") << std::endl;
    }

    std::cout << "\n--- 开始测试 search2 (左闭右开 [left, right)) ---" << std::endl;
    for (const auto &c : cases)
    {
        int result = solution.search2(test_nums, c.target);
        std::cout << "Target: " << c.target << " | Result: " << result
                  << (result == c.expected ? " [PASS]" : " [FAIL]") << std::endl;
    }

    // 额外测试：空数组
    std::vector<int> empty_vec;
    std::cout << "\n--- 空数组测试 ---" << std::endl;
    std::cout << "Search1 result: " << solution.search1(empty_vec, 5) << std::endl;
    std::cout << "Search2 result: " << solution.search2(empty_vec, 5) << std::endl;

    return 0;
}
