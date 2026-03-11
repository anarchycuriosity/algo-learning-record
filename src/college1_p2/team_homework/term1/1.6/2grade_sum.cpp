#include <bits/stdc++.h>
int main()
{
    int k;
    std::cin >> k;
    if(k >15)
    {
        return 0;
    }
    int n = 1;
    double Sn = 0;
    //取等很重要
    while(Sn <= k)
    {
        //啊啊这里的分数应该使用浮点数计算
        //Sn += 1/n;
        Sn += 1.0 / n;
        n++;
    }
    //记得-1
    std::cout << n - 1;
    return 0;
}