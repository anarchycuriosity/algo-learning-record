#include <iostream>
#include <vector>
namespace curio
{
    // 与原版那个递归相比去掉了更新real的步骤
    // real = (real > if_real) ? if_real : real;没有必要
    // 这其实是在找产量最低的锯子值，而我们要找的是锯子最高

    // 将 ans 作为一个引用传递，或者像下面这样通过返回值处理
    long long find_recursive(long long left, long long right, int aim, const std::vector<int> &trees)
    {
        // 1. 基准情况：当区间搜索完毕
        if (left > right) // 不能写等于号
        {
            return right; // 为什么返回 right？因为 right 是最后一个满足 total >= aim 的位置
        }

        long long mid = left + (right - left) / 2;
        long long total_wood = 0;

        // 2. 模拟砍树过程
        for (int i = 0; i < trees.size(); i++)
        {
            if (trees[i] > mid)
            {
                total_wood += (trees[i] - mid);
            }
        }

        // 3. 核心判定逻辑
        if (total_wood >= aim)
        {
            // 木材够了，尝试往更高的地方找
            // 此时 mid 可能是答案，但也可能有更高的答案在 [mid + 1, right]
            return find_recursive(mid + 1, right, aim, trees);
        }
        else
        {
            // 木材不够，必须往低处找 [left, mid - 1]
            return find_recursive(left, mid - 1, aim, trees);
        }
    }
}

int main()
{
    int N, aim;
    std::vector<int> trees;
    std::cin >> N >> aim;
    for (int i = 0; i < N; i++)
    {
        int hight;
        std::cin >> hight;
        trees.emplace_back(hight);
    }
    // 由于树的高度可能很高，不应该从0开始枚举最大高度
    long long real = 1e9;
    std::cout << curio::find_recursive(1, 1e9, aim, trees);
}
/*# P1873 [COCI 2011/2012 #5] EKO / 砍树

## 题目描述

伐木工人 Mirko 需要砍 $M$ 米长的木材。对 Mirko 来说这是很简单的工作，因为他有一个漂亮的新伐木机，可以如野火一般砍伐森林。不过，Mirko 只被允许砍伐一排树。

Mirko 的伐木机工作流程如下：Mirko 设置一个高度参数 $H$（米），伐木机升起一个巨大的锯片到高度 $H$，并锯掉所有树比 $H$ 高的部分（当然，树木不高于 $H$ 米的部分保持不变）。Mirko 就得到树木被锯下的部分。例如，如果一排树的高度分别为 $20,15,10$ 和 $17$，Mirko 把锯片升到 $15$ 米的高度，切割后树木剩下的高度将是 $15,15,10$ 和 $15$，而 Mirko 将从第 $1$ 棵树得到 $5$ 米，从第 $4$ 棵树得到 $2$ 米，共得到 $7$ 米木材。

Mirko 非常关注生态保护，所以他不会砍掉过多的木材。这也是他尽可能高地设定伐木机锯片的原因。请帮助 Mirko 找到伐木机锯片的最大的整数高度 $H$，使得他能得到的木材至少为 $M$ 米。换句话说，如果再升高 $1$ 米，他将得不到 $M$ 米木材。

## 输入格式

第 $1$ 行 $2$ 个整数 $N$ 和 $M$，$N$ 表示树木的数量，$M$ 表示需要的木材总长度。

第 $2$ 行 $N$ 个整数表示每棵树的高度。

## 输出格式

$1$ 个整数，表示锯片的最高高度。

## 输入输出样例 #1

### 输入 #1

```
4 7
20 15 10 17
```

### 输出 #1

```
15
```

## 输入输出样例 #2

### 输入 #2

```
5 20
4 42 40 26 46
```

### 输出 #2

```
36
```

## 说明/提示

对于 $100\%$ 的测试数据，$1\le N\le10^6$，$1\le M\le2\times10^9$，树的高度 $\le 4\times 10^5$，所有树的高度总和 $>M$。*/