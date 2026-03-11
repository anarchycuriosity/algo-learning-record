#include <iostream>
#include <vector>
void merge(std::vector<int> &nums, int left, int mid, int right) // 这里不小心写到按值传递，这会导致无法修改nums，最后完全不对
{
    std::vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right)
    {
        temp[k++] = (nums[i] <= nums[j] ? nums[i++] : nums[j++]);
    }
    while (i <= mid)
    {
        temp[k++] = nums[i++];
    }
    while (j <= right)
    {
        temp[k++] = nums[j++];
    }
    for (int p = 0; p < temp.size(); p++)
    {
        nums[left + p] = temp[p];
    }
}
void merge_sort(std::vector<int> &nums, int left, int right)
{
    if (left >= right) // 如果不加等号会遗漏情况
    {
        return;
    }
    int mid = left + (right - left) / 2;
    merge_sort(nums, left, mid);
    merge_sort(nums, mid + 1, right);
    merge(nums, left, mid, right);
}
int main()
{
    std::vector<int> data = {5, 2, 9, 1, 5, 6};
    merge_sort(data, 0, data.size() - 1);
    for (int n : data)
    {
        std::cout << n << " ";
    }
    return 0;
}