#include <bits/stdc++.h>
using namespace std;

int main() {
    long long sum_elements = 0;   // 所有元素之和
    long long count_elements = 0; // 元素个数
    long long current_value;

    // 持续读入，直到 EOF
    while (cin >> current_value) {
        sum_elements += current_value;
        count_elements += 1;
    }

    // 2^(n-1) ：n 至少为 1，题目保证集合非空
    long long subset_factor = 1LL << (count_elements - 1);

    long long answer = sum_elements * subset_factor;
    cout << answer << '\n';

    return 0;
}
/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<long long> s;
    long long x;
    while (cin >> x) { // 输入直到文件结束
        s.push_back(x);
    }

    int n = s.size();
    long long sum = 0;
    for (auto v : s) sum += v;

    // 公式法：元素和 * 2^(n-1)
    long long ans = sum * (1LL << (n - 1));
    cout << ans << endl;

    return 0;
}

*/