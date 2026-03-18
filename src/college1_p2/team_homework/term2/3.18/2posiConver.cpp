// 使用char(num - 10 + 'A')，当数字大于10的时候可以直接转高数
// 进制的本质是这一轮剩下什么东西，然后剔除剩下的东西进入下一轮
// 这其实涉及到一个递归的思想
// 而进制数一定全部是正数，转化出来的每一位置都是正数
// 比如15转-20进制是195
// 余数并不需要是实际意义上的余数，只要部分1（小）+部分2（大）可以组合为原本的东西即可

#include <iostream>
// 递归操作除数一直不变，被除数不断被削掉然后递归传下去
int n, m;
// n是被除数，m是除数
void solve(int n)
{
    if (n == 0)
    {
        return;
    }
    int _n = n % m; //_n是被削掉的余数
    int nn = n / m; // nn是能被传下去的东西,商
    if (_n < 0)
    {
        nn += 1;
        _n -= m;
    }
    solve(nn);
    if (_n < 10)
    {
        std::cout << _n;
    }
    else
    {
        std::cout << char(_n - 10 + 'A');
    }
}

int main()
{
    std::cin >> n >> m;
    std::cout << n << "=";
    solve(n);
    std::cout << "(base" << m << ")";
}