// 上次那样二分是不对的，因为这是浮点数，而且似乎没有正确分而治之
// 注意看题目提示，两个解之间的差的绝对值大于1，这意味着在区间1内最多有一个解
// 不要对最大的这个范围尝试二分，而是切细了二分，同时要注意浮点数精度控制
// 如果不注意浮点数控制就会MLE，也许是使用了太多次函数
// 在很细的区间内，如果l与mid同号，说明在mid和r侧
#include <bits/stdc++.h>
double a, b, c, d;
std::set<double> ans;
namespace curio
{
    double getRes(double &x)
    {
        return a * std::pow(x, 3) + b * std::pow(x, 2) + c * x + d;
    }
    void binary(double &left, double &right)
    {
        double mid = (left + right) / 2;
        if (getRes(mid) == 0)
        {
            ans.insert(mid);
        }
        else if (getRes(left) == 0)
        {
            ans.insert(left);
        }
        else if (getRes(right) == 0)
        {
            ans.insert(right);
        }

        if (left > right) // 不能写等因为浮点数很不确定
        {
            return;
        }
        else if (right - left < 1e-9)
        {
            return;
        }
        if (getRes(mid) * getRes(left) < 0)
        {
            binary(left, mid);
        }
        if (getRes(mid) * getRes(right) < 0)
        {
            binary(mid, right);
        }
    }
}
int main()
{
    std::cin >> a >> b >> c >> d;
    for (double i = -100.0; i <= 100.0; i++)
    {
        double right = i + 1;
        curio::binary(i, right);
    }
    std::vector<double> ans2;
    for (double answer : ans)
    {
        ans2.push_back(answer);
    }
    std::sort(ans2.begin(), ans2.end());
    for (int i = 0; i < ans2.size(); i++)
    {
        std::cout << std::fixed << std::setprecision(2) << ans2[i] << " ";
    }
}