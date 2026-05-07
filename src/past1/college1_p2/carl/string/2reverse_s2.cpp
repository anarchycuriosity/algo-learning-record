
#include <string>
#include <vector>
#include <iostream>

using namespace std;

namespace curio
{
    void reverse(std::string &s, int begin, int end) // end不是迭代器
    {
        /*
        for (int i = begin; i < (begin + end) / 2; i++)
        {
            // std::swap(s[i], s[end - i]);  end - i并不对，因为i不是从0开始
            std::swap(s[i], s[end - i + begin]);
        }
        */
        while (begin < end)
        {
            std::swap(s[begin++], s[end--]);
        }
    }
}
class Solution
{
public:
    string reverseStr(string s, int k)
    {
        for (int i = 0; i < s.size(); i += 2 * k)
        {
            if (s.size() - i < 2 * k && s.size() - i >= k) // 剩下的大于k小于2k
            {
                curio::reverse(s, i, i + k - 1);
                break;
            }
            else if (s.size() - i < k)
            {
                curio::reverse(s, i, s.size() - 1);
                break;
            }
            else
            {
                curio::reverse(s, i, i + k - 1);
            }
        }
        return s;
    }
};