#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 两数之和函数
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> seen; // 哈希表：存储数值 -> 索引
    //与map相比，它查找会更快，乱序而不是顺序，但内存消耗会更多
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i]; // 计算补数
        if (seen.find(complement) != seen.end()) {
            return {seen[complement], i}; // 找到答案
        }
        seen[nums[i]] = i; // 存储当前数值和索引
    }
    return {}; // 理论上不会到这里
}

int main() {
    int n, target;
    cout << "请输入数组长度: ";
    cin >> n;

    vector<int> nums(n);
    cout << "请输入数组元素: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "请输入目标值: ";
    cin >> target;

    vector<int> result = twoSum(nums, target);

    cout << "结果索引: " << result[0] << ", " << result[1] << endl;
    return 0;
}
/*
for(auto &x : container){}引用元素，避免拷贝，提高效率
会被编译器展开为
for (auto it = container.begin(); it != container.end(); ++it) {
    auto &x = *it;  // 解引用迭代器，得到元素
    // 使用 x
}

    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    int &x = *it;   // 注意这里 auto & 被替换成具体类型
    cout << x << " ";
}

auto 会根据右边表达式的类型来推导。

在范围 for 循环里，右边是 *it（迭代器解引用）。

所以：

如果容器是 vector<int>，那么 *it 的类型是 int&。

如果写 auto x，就会推导成 int（拷贝）。

如果写 auto &x，就会推导成 int&（引用）。

如果写 const auto &x，就会推导成 const int&（只读引用）。

*/