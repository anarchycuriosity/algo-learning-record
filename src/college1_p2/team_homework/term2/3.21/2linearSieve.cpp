// 同样是找范围内素数，先讲埃氏筛
// 2，划掉2的倍数，然后3，划掉3的倍数，也就是合数。接着是5，划掉5的合数，毕竟合数不可能是素数了
// 但埃氏筛的问题在于，会重复划掉数字，浪费时间

// 为了讲线性筛，我们需要引入一些数学定理：整数唯一分解定理：每个整数都可以唯一的分解为素数的乘积
// 比如12 = 2 * 2 * 3，并且顺序是定的，否则就不唯一。
// 乘法交换律。顺序不一样，结果一样

// 我们提前定义
// i 当前遍历的数
// p i的素数列表中的一个数。素数列表是比i小的素数组合，比如3的素数列表是2和3
// i的质因数分解，它可以重复包含p，但是是升序
// s 合数=p * i  需要被剔除.p*i有顺序
// 如果p比质因数分解的最小值要大，那么就break，因为乘法交换律导致重复，不满足整数唯一分解定理

// 由于我们不使用素数定义的方法去判断素数，所以我们默认所有数都是素数，否则改
// 因为是剔除原理，当然是假设都是素数再剔除不是素数的部分
// 如果p是i的最小质因数，就要及时break，因为如果p继续往素数列表之后选就会更大，
#include <iostream>
#include <vector>
int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    // 筛子的原料
    std::vector<bool> isPrime(n + 1, true);
    // 素数列表
    std::vector<int> primes;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
        }
        for (int p : primes)
        {
            if (p * i > n)
            {
                break;
            }
            isPrime[p * i] = false;
            if (i % p == 0)
            {
                break;
            }
        }
    }
    std::vector<int> tars(q, 0);
    for (int i = 0; i < q; i++)
    {
        std::cin >> tars[i];
        tars[i]--;
    }
    for (int i = 0; i < q; i++)
    {
        std::cout << primes[tars[i]] << std::endl;
    }
}