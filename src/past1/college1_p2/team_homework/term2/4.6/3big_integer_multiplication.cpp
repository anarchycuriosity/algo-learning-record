#include <iostream>
// 高位应该在数组的后面，这是为了进位方便，毕竟进位的时候push要比前插要更好
#include <vector>
// #define maxlen 2000
#include <string>
#include <string.h>
const int max_len = 10001;
// 用全局初始化为0
char str1[max_len], str2[max_len];
int num1[max_len], num2[max_len];
int res[max_len];
int main()
{
    // std::vector<int> num1(2000, 0);
    // std::vector<int> num2(2000, 0);
    // std::vector<int> res(4000, 0);
    // // 先存第一个数
    // // for (int i = max_len - 1; i > 0; i--)
    // // {
    // //     std::cin >> num1[i];
    // // }

    std::cin >> str1 >> str2;
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // 倒着存入
    for (int i = 1; i <= len1; i++)
    {
        num1[i] = str1[len1 - i] - '0';
    }
    for (int i = 1; i <= len2; i++)
    {
        num2[i] = str2[len2 - i] - '0';
    }

    // 先加然后再检查进位
    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            // res[i + j - 1] = num1[i] * num2[j];应该是累加而不是赋值
            // 因为会收到不同位置的数
            res[i + j - 1] += num1[i] * num2[j];
        }
    }
    for (int i = 1; i < len1 + len2; i++)
    {
        if (res[i] > 9)
        {
            res[i + 1] += res[i] / 10;
            res[i] %= 10;
        }
    }
    // 消去0
    int len = len1 + len2;
    while (res[len] == 0 && len > 1)
    {
        len--;
    }
    for (int i = len; i >= 1; i--)
    {
        std::cout << res[i];
    }
    return 0;
}