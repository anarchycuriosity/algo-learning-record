#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <set>
using namespace std;

// 生成随机答案：四位数，每位 1-9 且互不相同
vector<int> generateAnswer() {
    vector<int> digits = {1,2,3,4,5,6,7,8,9};

    // 使用随机种子
    random_device rd;
    mt19937 gen(rd());

    shuffle(digits.begin(), digits.end(), gen);

    return vector<int>(digits.begin(), digits.begin() + 4);
}

// 检查输入是否合法
bool isValid(const string& s) {
    if (s.size() != 4) return false;

    set<char> used;
    for (char c : s) {
        if (c < '1' || c > '9') return false; // 必须是 1-9
        if (used.count(c)) return false;      // 不能重复
        used.insert(c);
    }
    return true;
}

// 计算 A 和 B
pair<int,int> getHint(const vector<int>& ans, const string& guess) {
    int A = 0, B = 0;

    for (int i = 0; i < 4; i++) {
        int g = guess[i] - '0';
        if (g == ans[i]) A++;
        else if (find(ans.begin(), ans.end(), g) != ans.end()) B++;
    }

    return {A, B};
}

int main() {
    auto answer = generateAnswer();

    int attempts = 0;
    string guess;

    while (attempts < 10) {
        cout << "请输入你的猜测（四位数，1-9，不能重复）：";
        cin >> guess;

        if (!isValid(guess)) {
            cout << "输入不正确，请重新输入。\n";
            continue;
        }

        auto [A, B] = getHint(answer, guess);
        cout << A << "A" << B << "B\n";

        if (A == 4) {
            cout << "你赢了！\n";
            return 0;
        }

        attempts++;
    }

    cout << "你输了，正确答案是：";
    for (int d : answer) cout << d;
    cout << endl;

    return 0;
}
