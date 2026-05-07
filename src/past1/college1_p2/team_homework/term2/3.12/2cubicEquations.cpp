#include <bits/stdc++.h>
double a, b, c, d;
std::vector<double> ans;
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
            ans.push_back(mid);
        }
        if (left > right)
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
    double left = -100.0;
    double right = 100.0;
    curio::binary(left, right);
    for (int i = 0; i < ans.size(); i++)
    {
        std::cout << ans[i] << " ";
    }
}