

// 注意理解题目的意思，无限循环可以这么理解，有一组数会一直出现，也就是会有相同的数据
// 将已经出现的数据存入哈希表，如果重复出现了就返回false
#include <unordered_set>
int getSum(int n)
{
    int sum = 0;
    while (n)
    {
        sum += (n % 10) * (n % 10);
        n /= 10;
    }
    return sum;
}

class Solution
{
public:
    bool isHappy(int n)
    {
        std::unordered_set<int> set;
        while (1)
        {
            int sum = getSum(n);
            if (sum == 1)
            {
                return true;
            }
            if (set.find(sum) != set.end())
            {
                return false;
            }
            else
            {
                set.insert(sum);
            }

            n = sum;
        }
    }
};