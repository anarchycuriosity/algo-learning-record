// 要找一条线段上最大区间和很简单
// 对于矩阵，比如3 * 3，其实答案只有可能在1 行，12行，123行，2行，23行，3行
// 我们只需要压缩，然后像找线段和一样即可
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
int n;
#define maxn 120
int zip[120];
// 最好是用全局变量吧
// 对全局变量进行操作这个很巧妙
int ans = -100;
int src[maxn][maxn];
int tmp[maxn];
int findMax()
{
    // 前缀和求最大区间和
    // 如果当前点减去之前的最低点，得到的差值就是以当前位置结尾的所有区间的最大值
    // 走完的时候就得到最大值了
    // int min_pre_sum = 0; // 仅仅记录，不走
    // int current_sum = 0;
    // // 以上两个都是前缀和
    // int max_sum = -100;
    // for (int i = 0; i < n; i++)
    // {
    //     int tmp = current_sum;
    //     current_sum += zip[i];
    //     min_pre_sum = std::min(tmp, current_sum);
    //     max_sum = std::max(max_sum, current_sum - min_pre_sum);
    // }
    // return max_sum;

    // // 这里假定zip已经被压缩好了
    // int max_sum = -100;
    // int min_sum = 0; // 不要动它.这是此前的最小和
    // // zip[i]其实就是current_sum
    // for (int i = 0; i < n; i++)
    // {
    //     // max_num = std::max(zip[i] - zip[i - 1], max_num); // 索引i - 1数
    //     min_sum = std::min(zip[i], min_sum); // 前i的最小和
    //     max_sum = std::max(max_sum, zip[i] - min_sum);
    // }
    // return max_sum;

    // 如果已经知道前缀和了那就用相位转移方程吧
    // 提前定义一个数组tmp来帮忙
    // tmp主要是用来实时拿到最新的最佳答案
    int tmp_ans = zip[0]; // 初始化要对
    memset(&tmp, 0, sizeof(tmp));
    tmp[0] = zip[0]; // 这里不能被跳过！
    for (int i = 1; i < n; i++)
    {
        tmp[i] = std::max(zip[i], tmp[i - 1] + zip[i]);
        tmp_ans = std::max(tmp_ans, tmp[i]);
    }
    return tmp_ans;
}

void zip_matrix()
{
    for (int i = 0; i < n; i++)
    {
        memset(&zip, 0, sizeof(zip));
        for (int j = i; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                zip[k] += src[j][k];
            }
            ans = std::max(findMax(), ans); // 更新答案
        }
        // 用zip压缩好了数组后，对zip进行findMax操作找最值
    }
}
int main()
{

    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> src[i][j];
        }
    }
    zip_matrix();
    std::cout << ans;
}