#include <string>
using namespace std;
namespace curio
{
    void reverse(std::string &s, int begin, int end) // end不是迭代器
    {

        while (begin < end)
        {
            std::swap(s[begin++], s[end--]);
        }
    }
    void remove(std::string &s)
    {
        int fastInd = 0, slowInd = 0;

        // 删去前面的空
        while (fastInd < s.size() && s[fastInd] == ' ')
        {
            fastInd++;
        }
        for (; fastInd < s.size(); fastInd++)
        {
            // 空格去重
            if (fastInd < s.size() && s[fastInd] == ' ' && s[fastInd] == s[fastInd - 1])
            {
                continue;
            }
            else
            {
                s[slowInd++] = s[fastInd];
            }
        }
        if (slowInd - 1 > 0 && s[slowInd - 1] == ' ') // 至少会带一个空格，同时slowInd - 1是为了查休止符前一个，因为前面++了
        {
            s.resize(slowInd - 1);
        }
        else
        {
            s.resize(slowInd);
        }
    }
}

class Solution
{
public:
    string reverseWords(string s)
    {
        // 禁止使用辅助空间，难度就变大了，否则没有意义
        // 如果整体翻转一次，虽然确实单词是反转了但是单词本身也反转了
        // 负负为正，再转一次就好了
        // 擦除空格的操作如果用erase，erase本身就达到了O(n)的复杂度
        // 简单总结一下，删去操作可以从左到右使用双指针遍历
        // 但是比如把数字换成number这样的扩容操作，则需要从右到左才不会导致相撞
        // 去掉冗余空格这一操作的本质其实就是和前面的找三数和的去重是一样的

        // while循环的条件，因为涉及删去操作，1，删去后的size要大于0，2，遍历的指针不能越界
        // 哪怕你明知在某个if中的那个索引大于0，但只要需要访问数组，就要&&ind > 0来保证不越界
        curio::reverse(s, 0, s.size() - 1);
        curio::remove(s);
        int start = 0;                      // start在每次循环后更新
        for (int i = 0; i <= s.size(); i++) // 这里要取等，才能读到休止符，并不是每次都读到有效数字，需求是休止符
        {
            if (i == s.size() || s[i] == ' ')
            {
                curio::reverse(s, start, i - 1);
                start = i + 1;
            }
        }
        return s;
    }
};