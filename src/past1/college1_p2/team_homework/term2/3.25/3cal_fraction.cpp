#include <iostream>
#include <vector>
#include <cmath>
#define ll long long
// 本题依然是考察一个解析字符串并处理
// 正负号就像个开关，让这个数变成正数或者负数
// 但是问题是我们需要一个东西去映射正负号，也就是一个全局int 正负1
// 如果遍历到了正负号就让这个int改变为对应的值
int gcd(int a, int b) // 拿最大公约数
{
    while (b != 0)
    {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}
// 冷知识，全局函数会被初始化为0
int main()
{
    // 这里引入一个控制每轮循环执行次数的ij循环
    // 不必死板的在for那里控制i自加几个
    // 而是留空，在让i = j自动控制每次循环去做什么
    // 双层for循环的复杂度并不一定是n * n，在这里是 1 * n，
    // 我们不必把结果存起来再遍历一次,在for循环中间截断
    // 每次把结果放到res1，re2清空
    // a和b的最小公倍数 * 最大公约数的结果是a * b
    // 这里涉及一个while的新写法，如果只拿到第一个结果

    // 外层循环的一个part是找一个完整的分数
    std::string s;
    std::cin >> s;
    int i = 0, j = 0;
    int swit1 = 1, swit2 = 1; // 控制分数正负
    int nume1 = 0;            // numerator
    int deno1 = 0;            // denominator
    int res1 = 0, res2 = 0;
    // 我们用res1/2来存累计的分子/分母，用nume和deno来存新遍历到的数据
    for (; i < s.size();)
    {
        swit1 = 1, swit2 = 1, nume1 = 0, deno1 = 0;
        for (j = i; j < s.size(); j++)
        {
            // 判断符号
            if (s[j] == '+')
            {
                swit1 = 1;
            }
            else if (s[j] == '-')
            {
                swit1 = -1;
            }
            else if (s[j] == '/')
            {
                break;
            }
            else
            {
                // 要处理可能是多位数
                nume1 = nume1 * 10 + s[j] - '0';
                // nume1 *= swit1;
            }
        }
        j++; // j额外跳的只有这一次，找完分母之后不需要跳
        // 这是为了让指针顺利地停在正负号上进行下一次的判断

        // swit2似乎无法缺少，因为需要一个默认为+的状态
        // 第二个for循环的break条件不一样,必须先手动跳一个
        if (s[j] == '+')
        {
            swit2 = 1;
            j++;
        }
        else if (s[j] == '-')
        {
            swit2 = -1;
            j++;
        }
        for (; j < s.size(); j++)
        {
            if (s[j] == '+' || s[j] == '-')
            {
                break;
            }
            else
            {
                deno1 = deno1 * 10 + s[j] - '0';
                // deno1 *= swit2;
            }
        }
        // 现在读入结束，开始约分
        // 让正负号交给分子判断吧
        int _gcd = gcd(std::abs(nume1), std::abs(deno1));
        swit1 *= swit2;
        swit2 = 1;
        nume1 *= swit1;
        deno1 *= swit2;
        nume1 /= _gcd;
        deno1 /= _gcd;

        if (!res1) // 如果前面没有数就不需要通分
        {
            res1 = nume1;
            res2 = deno1;
            i = j;
            continue;
        }
        // 曾经有过数，开始通分

        int _lcm = lcm(res2, deno1);
        int times1 = _lcm / res2;
        int times2 = _lcm / deno1;
        res2 = _lcm;
        deno1 = _lcm;
        res1 *= times1;
        nume1 *= times2;
        res1 += nume1;
        int gcd2 = gcd(std::abs(res1), std::abs(res2));
        // 不要忘了整合之后再次通分
        res1 /= gcd2;
        res2 /= gcd2;
        i = j;
    }
    if (res2 != 1)
    {
        std::cout << res1 << "/" << res2;
    }
    else
    {
        std::cout << res1;
    }
}