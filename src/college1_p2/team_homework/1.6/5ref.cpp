#include <bits/stdc++.h>

int solve_one_course(const std::vector<int>& t_list) {
    int sum_t = 0;  // sum_time 当前课程总时间
    for (int t_c : t_list) sum_t += t_c;

    int half_t = sum_t / 2;  // half_time 背包容量
    std::vector<int> dp(half_t + 1, 0);

    // 01 背包
    for (int t_c : t_list) {  // t_c = time_cost
        for (int cap = half_t; cap >= t_c; --cap) {
            dp[cap] = std::max(dp[cap], dp[cap - t_c] + t_c);
        }
    }

    int l_t = dp[half_t];        // left_time 左脑时间
    int r_t = sum_t - l_t;       // right_time 右脑时间
    return std::max(l_t, r_t);   // 当前课程耗时
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int s1, s2, s3, s4;  // 每门课题目数量
    std::cin >> s1 >> s2 >> s3 >> s4;

    std::vector<int> A(s1), B(s2), C(s3), D(s4);

    for (int i = 0; i < s1; ++i) std::cin >> A[i];
    for (int i = 0; i < s2; ++i) std::cin >> B[i];
    for (int i = 0; i < s3; ++i) std::cin >> C[i];
    for (int i = 0; i < s4; ++i) std::cin >> D[i];

    int total_t = 0;  // total_time_all 所有课程总时间

    total_t += solve_one_course(A);
    total_t += solve_one_course(B);
    total_t += solve_one_course(C);
    total_t += solve_one_course(D);

    std::cout << total_t << '\n';
    return 0;
}
