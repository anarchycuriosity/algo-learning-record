
#include <string>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    std::vector<char> lefts = {'(', '[', '{'};
    std::vector<char> rights = {')', ']', '}'};
    std::stack<char> stL;
    std::stack<char> stR;
    bool isValid(string s)
    {
        // 这里不是很好用lefts和rights数组来偷懒了
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                stL.push(s[i]);
            }
            else if (s[i] == ')')
            {
                if (stL.top() == s[i])
                {
                    stL.pop();
                    continue;
                }
            }
        }
    }
};