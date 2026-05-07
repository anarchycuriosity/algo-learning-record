#define MAXN 1010
#define MAXW 100010
#include <iostream>
#include <string.h>
#include <cstring>
// N给原数组用，W给计数数组用
// 因为哪怕原数组只有两个元素但如果跨度很大也需要开很大的计数数组
// 只测一组就不用memset了
int ori[MAXN], ori_op[MAXN], ori_digit[MAXN], count_arr[MAXW], res[MAXN];
void count_sort(int n, int w, int digits) // 对ori排序，经过中间count_arr数组输出到res
{
    for (int k = 1; k <= digits; k++)
    {
        memset(count_arr, 0, sizeof(count_arr));
        for (int i = 1; i <= n; i++)
        {
            ori_digit[i] = ori_op[i] % 10;
            ori_op[i] /= 10;
        }

        for (int i = 1; i <= n; i++)
        {
            // 统计个数
            count_arr[ori_digit[i]]++;
        }
        // 前缀和
        for (int i = 1; i <= w; i++)
        {
            count_arr[i] += count_arr[i - 1];
        }

        // 从后面开始，因为前缀和是大的
        for (int i = n; i >= 1; i--)
        {
            res[count_arr[ori_digit[i]]--] = ori[i];
        }
        for (int i = 1; i <= n; i++)
        {
            ori[i] = res[i];
        }
    }
}

int main()
{
    // 输入要求先输入数组的长度再输入数组元素
    int n, w = 0;   // n是元素个数，w是最大元素
    int digits = 0; // digit是最大位数
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> ori[i];
        ori_op[i] = ori[i];
        w = (w > ori[i]) ? w : ori[i];
        digits = std::strlen(std::to_string(ori[i]).c_str());
    }
    count_sort(n, w, digits);
    for (int i = 1; i <= n; i++)
    {
        std::cout << res[i] << " ";
    }
}