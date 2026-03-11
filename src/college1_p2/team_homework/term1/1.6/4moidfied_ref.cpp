#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    long long N;
    cin >> s >> N;
    N--; // 题目一般是1-based，这里转成0-based

    long long n = s.size();
    long long len = n;

    // 找到最终长度 >= N+1
    while (len <= N) {
        len *= 2;
    }

    // 反映射 N
    while (len > n) {
        long long half = len / 2;

        if (N < half) {
            // 在前半部分，不变
        } else {
            long long k = N - half; // 后半部分的第 k 个字符

            if (k == 0) {
                N = half - 1; // 对应上一层的最后一个字符
            } else {
                N = k - 1;    // 对应上一层的 (k-1)
            }
        }

        len /= 2; // 回到上一层
    }

    cout << s[N];
    return 0;
}
