#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    if (!getline(cin, s)) return 0;

    stack<string> st;

    for (char c : s) {
        if (c != ']') {
            // 普通字符或 '['，统一压成长度为 1 的字符串
            st.push(string(1, c));
        } else {
            // 遇到 ']'，开始弹出直到 '['
            string mid;
            while (!st.empty() && st.top() != "[") {
                mid = st.top() + mid; // 注意顺序
                st.pop();
            }
            if (!st.empty() && st.top() == "[") {
                st.pop(); // 弹掉 '['
            }

            // 此时 mid 形如： "3FUN"、"10ABC"、"3ABABABABCD" 等
            // 从开头读数字
            int i = 0, n = mid.size();
            int num = 0;
            while (i < n && isdigit(mid[i])) {
                num = num * 10 + (mid[i] - '0');
                ++i;
            }
            // 剩下的是要重复的内容
            string sub = mid.substr(i);

            // 展开 num 次
            string rep;
            while (num--) rep += sub;

            // 把展开结果压回栈中
            st.push(rep);
        }
    }

    // 把栈里所有内容拼成最终结果
    string ans;
    vector<string> tmp;
    while (!st.empty()) {
        tmp.push_back(st.top());
        st.pop();
    }
    // 栈是反的，需要倒回来
    for (int i = (int)tmp.size() - 1; i >= 0; --i) {
        ans += tmp[i];
    }

    cout << ans << '\n';
    return 0;
}
