#include <vector>
#include <iostream>

// 这道题的教训是
// 我一开始想到了要去除重复元素
// 但是又想到可以用模拟来写，但其实因为只需要输出洼地的数目所以其实不应该用模拟
// 如果使用很多分别的if-else对i进行变化，位置就很容易乱
// 如果用一个while循环做完，就需要用一个bool变量维护，判断当前i是从山上走下来的还是并不是
// 这种做法本文件做的要好很多，如果和i-1比是减少的，那上升布尔是false。
// 如果和i-1比是增加的并且上升bool是fase，那么count++并且改上升布尔为true
int main()
{
    int n;
    std::cin >> n;
    std::vector<int> earth(n, 0);
    for (int i = 0; i < n; i++)
    {
        std::cin >> earth[i];
    }
    int count = 0;
    // 如果这样会难以处理平的洼地

    /*     for (int i = 1; i < 10 - 1; i++)
        {
            if (earth[i - 1] >= earth[i] && earth[i] <= earth[i + 1])
            {
                count++;
            }
        } */

    int preH = earth[0]; // preheight代表上一次最高高度
    // 如果是单个谷底那就跳一个，否则多跳，用for不太合适
    int i = 1;
    while (i < n - 1) // 这里不取等因为里面有个j
    {
        // 写的太乱了
        /*         if (earth[i] < preH && earth[i] < earth[i + 1]) // 单底
                {
                    count++;
                    i++;
                    preH = earth[i + 1];
                }
                else if (earth[i] < preH && earth[i] >= earth[i + 1])
                {
                    i++;
                }
                if (earth[i] >= preH)
                {
                    preH = earth[i];
                    i++;
                } */

        if (earth[i] < preH) // 如果比曾经的最高点小，说明是在向下走或者洼地
        {
            // 我们要跳过所有的平地
            int j = i;
            // 引入j的本质是为了把寻找一段连续状态这一动作从主循环中剥离出来
            // 不然每次检查都是在重新跑一次while这层循环，每次都要做很多重复检查，ifelse臃肿容易出错
            while (j < n - 1 && earth[i] == earth[j]) // 不用到n-1，如果到了还没爬出来那就是平地而不是谷地
            {
                j++;
            }
            if (earth[j] > earth[i])
            {
                count++;
            }
            // 这里preh是洼地脚，i是洼地脚向上一格
            // 需要模拟一个爬山的过程
            preH = earth[j - 1];
            i = j;
        }
        else
        {
            // 如果当前不比左边低，那就是普通的爬坡或者平原，继续走而不计数
            // 我遗漏了高的平原的情况
            preH = earth[i];
            i++;
        }
    }
    std::cout << count;
}