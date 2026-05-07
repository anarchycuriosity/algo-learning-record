#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define ll long long
// 定义一个结构体来存储数位 DP 的返回结果
struct result_data
{
    ll count;
    ll digit_sum;
};

// 全局变量，用于存储记忆化结果
// dp[pos][tight]
// pos: 当前处理到第几位 (0 ~ 100000)
// tight: 是否受到约束 (0 或 1)
// 使用 vector 代替原始数组以避免栈溢出风险
std::vector<std::vector<result_data>> dp;
std::vector<std::vector<bool>> visited;
std::string n_str;
vector<ll> ans;
const ll mod = 998244353;

result_data dfs(ll pos, bool tight)
{
    // 如果已经处理完所有位，返回基础值
    if (pos == n_str.length())
    {
        return {1, 0};
    }

    // 检查是否已经计算过
    if (visited[pos][tight])
    {
        return dp[pos][tight];
    }

    ll current_count = 0;
    ll current_sum = 0;

    // 确定当前位可以填写的数字上限
    ll limit = tight ? (n_str[pos] - '0') : 9;

    for (ll digit = 0; digit <= limit; ++digit)
    {
        // 计算新的 tight 状态
        bool next_tight = tight && (digit == limit);

        // 递归进入下一层
        result_data next_res = dfs(pos + 1, next_tight);

        // 更新计数：所有合法的方案数累加
        current_count = (current_count + next_res.count) % mod;

        // 更新总和：
        // 1. 下一层的总和贡献 (next_res.digit_sum)
        // 2. 当前位数字 (digit) 的贡献，它在 next_res.count 种方案里都出现了
        ll current_digit_contribution = (static_cast<ll>(digit) * next_res.count) % mod;
        current_sum = (current_sum + next_res.digit_sum + current_digit_contribution) % mod;
    }

    visited[pos][tight] = true;
    dp[pos][tight] = {current_count, current_sum};

    return dp[pos][tight];
}

void solve()
{
    std::cin >> n_str;

    // 初始化 DP 状态表
    // 动态调整大小
    ll len = static_cast<ll>(n_str.length());
    dp.assign(len, std::vector<result_data>(2));
    visited.assign(len, std::vector<bool>(2, false));

    // 从第 0 位开始，初始 tight 为 true
    result_data final_result = dfs(0, true);

    // 题目要求的是 1 到 n，我们计算的是 0 到 n
    // 上面的 dfs 包含了 0 的情况，且 0 的数位和为 0，所以不需要额外减去，但要注意题目范围
    // 如果题目包含 0，这里输出即可；如果不包含 0，逻辑也是一样的因为 0 的贡献是 0
    // std::cout << final_result.digit_sum << std::endl;
    ans.push_back(final_result.digit_sum);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll t;
    if (std::cin >> t)
    {
        while (t--)
        {
            solve();
        }
    }
    for (auto it = ans.begin(); it < ans.end(); it++)
    {
        cout << *it << "\n";
    }
    return 0;
}
