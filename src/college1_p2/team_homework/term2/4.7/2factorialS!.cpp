#include <iostream>
#include <string.h>
const int max_len = 10001;
int cur_S[max_len];
int to_add[max_len];
void transform(int &k) // 传入k算出k的阶乘并存入to_add数组
{
    int num = 1;
    while (k--)
    {
        num *= k;
    }
    for (int i = 0; i < max_len; i++)
    {
        if (num == 0)
        {
            return;
        }
        to_add[i] = num % 10;
        num /= 10;
    }
}

void add() // 把cur_S和to_add数组相加
{
    for (int i = 0; i < max_len; i++)
    {
        cur_S[i] += to_add[i];
    }
    for (int i = 0; i < max_len; i++)
    {
        int tmp = cur_S[i];
        if (tmp / 10 > 0)
        {
            cur_S[i + 1] += tmp / 10;
            cur_S[i] = tmp % 10;
        }
    }
}
int main()
{
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        memset(&to_add, 0, sizeof(to_add));
        transform(i);
        add();
    }
    // 去除结尾的0
    int len = max_len;
    for (int i = max_len - 1; i >= 0; i--)
    {
        if (cur_S[i] == 0)
        {
            len--;
        }
    }
    for (int i = len; i >= 0; i--)
    {
        std::cout << cur_S[i];
    }
}