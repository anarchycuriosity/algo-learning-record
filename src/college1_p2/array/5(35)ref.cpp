#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) 
{
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid; // 找到目标
        } else if (nums[mid] < target) {
            left = mid + 1; // 去右边找
        } else {
            right = mid - 1; // 去左边找
        }
    }
    return left; // 没找到，返回插入位置
}

int main() {
    vector<int> nums = {1, 3, 5, 6};
    cout << searchInsert(nums, 5) << endl; // 输出 2
    cout << searchInsert(nums, 2) << endl; // 输出 1
    cout << searchInsert(nums, 7) << endl; // 输出 4
    cout << searchInsert(nums, 0) << endl; // 输出 0
    return 0;
}
