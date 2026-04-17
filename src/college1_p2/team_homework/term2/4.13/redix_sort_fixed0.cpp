// 我们不需要引入额外的操作数组，排序它会花费更多时间
// 依旧3个即可

#define MAXN 1010
#define MAXW 100010
#include <iostream>
#include <string.h>
#include <cstring>
// N给原数组用，W给计数数组用
// 因为哪怕原数组只有两个元素但如果跨度很大也需要开很大的计数数组
// 只测一组就不用memset了
int ori[MAXN], count_arr[10], res[MAXN];
void redix_sort(int n, int digits)
{
    int div = 1;
    for (int k = 1; k <= digits; k++)
    {
        std::memset(count_arr, 0, sizeof(count_arr));
        // 不要维护额外的数组，我们只需要拿各个位置的数值然后排序
        // 对着res一直排序
        for (int i = 1; i <= n; i++)
        {
            int digit = (ori[i] / div) % 10;
            count_arr[digit]++;
        }

        // 求前缀和
        for (int i = 1; i <= 10; i++)
        {
            count_arr[i] += count_arr[i - 1];
        }

        // 对res排序
        for (int i = n; i >= 1; i--)
        {
            // 依然根据digit排序
            // digit其实取代了需要一直维护的操作数组
            int digit = (ori[i] / div) % 10;
            res[count_arr[digit]--] = ori[i];
        }

        // 把排序结果写回ori
        for (int i = 1; i <= n; i++)
        {
            ori[i] = res[i];
        }
        div *= 10;
    }
}
int main()
{
    // 输入要求先输入数组的长度再输入数组元素
    int n, w = 0;   // n是元素个数，w是最大元素
    int digits = 0; // digits是最大位数
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> ori[i];
        w = (w > ori[i]) ? w : ori[i];
        // digits = (digits > std::strlen(std::to_string(ori[i]).c_str())) ? digits : std::strlen(std::to_string(ori[i]).c_str());
    }
    int temp = w;
    if (temp == 0)
        digits = 1;
    while (temp > 0)
    {
        temp /= 10;
        digits++;
    }
    redix_sort(n, digits);
    for (int i = 1; i <= n; i++)
    {
        std::cout << res[i] << " ";
    }
}
