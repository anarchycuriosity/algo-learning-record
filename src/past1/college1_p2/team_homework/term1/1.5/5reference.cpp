#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    vector<bool> match(n, false); // 标记每个位置是否已匹配
    stack<int> st;                // 存左括号的下标

    // 第一遍：匹配括号
    for (int i = 0; i < n; i++) {
        char c = s[i];

        if (c == '(' || c == '[') {
            st.push(i);
        } else {
            // c 是右括号
            if (!st.empty()) {
                int t = st.top();
                if ((s[t] == '(' && c == ')') || (s[t] == '[' && c == ']')) {
                    // 匹配成功
                    match[t] = match[i] = true;
                    st.pop();
                }
            }
        }
    }

    // 第二遍：输出结果
    for (int i = 0; i < n; i++) {
        if (match[i]) {
            cout << s[i];
        } else {
            // 未匹配的括号 → 输出完整括号对
            if (s[i] == '(' || s[i] == ')') {
                cout << "()";
            } else {
                cout << "[]";
            }
        }
    }

    return 0;
}