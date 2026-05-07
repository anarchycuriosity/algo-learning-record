#include <iostream>
#include <vector>
using namespace std;
/*
在 C++ 里，& 是 按位与 运算符。

它会把两个整数的二进制形式逐位比较：

如果两个数在某一位上都是 1 → 结果这一位就是 1

否则 → 结果这一位就是 0
*/

int main() {
    vector<long long> s;
    long long x;
    while (cin >> x) {
        s.push_back(x);
    }
    int n = s.size();
    long long total_sum = 0;

    // 枚举所有子集
    for (long long mask = 0; mask < (1LL << n); mask++) {
        long long subset_sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1LL << i)) {
                subset_sum += s[i];
            }
        }
        total_sum += subset_sum;
    }

    cout << total_sum << endl;
    return 0;
}
