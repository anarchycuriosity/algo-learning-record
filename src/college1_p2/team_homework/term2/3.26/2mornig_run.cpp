#include <bits/stdc++.h>
using ll = long long;

ll gcb(ll a, ll b)
{

    while (b != 0)
    {
        ll remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}
ll lcm(ll a, ll b)
{
    return (a * b) / gcb(a, b);
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); // 之后就不要用endl来换行了

    ll a, b, c;
    std::cin >> a >> b >> c;
    ll tmp = lcm(a, b);
    std::cout << lcm(tmp, c);
}