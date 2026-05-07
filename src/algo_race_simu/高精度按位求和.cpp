#include <iostream>
#include <string.h>
using namespace std;
const int maxn = 1001;
// int num;
// int anum[maxn];
int ans[maxn];
int mod = 998244353;
int solve(int num) // 对num按位求和然后取余
{
    int res = 0;
    // memset(anum, 0, sizeof(anum));
    // int dig = 1;
    while (num > 0)
    {
        // anum[dig] = num % 10;
        res += num % 10;
        res %= mod;
        num /= 10;
    }
    return res;
}
int main()
{
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++)
    {
        int sum = 0;
        int n;
        cin >> n;
        // while (n--)
        while (n)
        {

            sum += solve(n);
            sum %= mod;
            n--;
        }
        ans[k] = sum;
    }
    for (int i = 1; i <= t; i++)
    {
        cout << ans[i] << "\n";
    }
}