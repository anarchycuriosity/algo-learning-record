#include <vector>
#include <iostream>
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
int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> nums(m, 0);
    for (int i = 0; i < m; i++)
    {
        std::cin >> nums[i];
    }
    merge_sort(nums, 0, nums.size() - 1);
    for (int i = 0; i < m; i++)
    {
        std::cout << nums[i] << " ";
    }
}