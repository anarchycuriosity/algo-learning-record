// 第一次的写法是对一个未排序数组进行查找，结果复杂度是n*n会导致超时
// 如果是对值查找的话，显然处理一个已经排序好了的数组要方便的多
// 考虑使用二分查找法和双指针法
#include <vector>
#include <iostream>
#include <algorithm>
void merge(std::vector<int> &vec, int left, int mid, int right)
{
    std::vector<int> tmp(right - left + 1, 0);
    int index = 0;
    int ind1 = left;
    int ind2 = mid + 1;
    for (index; index < tmp.size(); index++)
    {
        if (ind1 <= mid && ind2 <= right)
        {
            if (vec[ind1] <= vec[ind2]) // 比较双指针
            {
                tmp[index] = vec[ind1++];
            }
            else
            {
                tmp[index] = vec[ind2++];
            }
        }
        else if (ind1 <= mid)
        {
            tmp[index] = vec[ind1++];
        }
        else
        {
            tmp[index] = vec[ind2++];
        }
    }
    for (int i = left; i <= right; i++)
    {
        vec[i] = tmp[i - left];
    }
}
void merge_sort(std::vector<int> &vec, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mid = left + (right - left) / 2;
    // merge_sort(vec, left, mid - 1);
    merge_sort(vec, left, mid);
    merge_sort(vec, mid + 1, right);
    merge(vec, left, mid, right);
}
// 不要忘记写引用
int get_pos1(std::vector<int> &nums, int tar) // 找到第一个>=tar的数的下标
{
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= tar)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}
int get_pos2(std::vector<int> &nums, int tar)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= tar)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return left;
}
int main()
{
    int n, c;
    std::cin >> n >> c;
    std::vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        std::cin >> nums[i];
    }
    merge_sort(nums, 0, nums.size() - 1);
    // 如果使用int，可能会导致一个测试点WA
    // 因为这会让count变成一个神秘负数
    long long count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int a = nums[i];
        int b = a + c;
        int pos1 = get_pos1(nums, b);
        int pos2 = get_pos2(nums, b);
        count += pos2 - pos1; // 不需要+1，因为pos2是第一个大于的索引
    }
    std::cout << count;
}