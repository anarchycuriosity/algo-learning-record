#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    void getNext(int *next, const string &s)
    {
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.size(); i++)
        {
            while (j > 0 && s[j] != s[i])
            {
                j = next[j - 1];
            }
            if (s[j] == s[i])
            {
                j++;
            }
            next[i] = j;
        }
    }
    bool repeatedSubstringPattern(string s)
    {
        // 最小单元不能靠全是0来判断，因为最小单元里面依然有可能存在重复的字母，这会导致提前拿到count
        /*         int *next = new int[s.size()];
                getNext(next, s);
                int count = 0;
                int ind = 0;
                while (ind < s.size() && next[ind] == 0)
                {
                    ind++;
                }
                count = ind;
                int times = next[s.size() - 1];
                if (count == 0)
                {
                    return false;
                }
                else
                {
                    if (times != 0 && times % count == 0)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }

        */

        // 虽然从头到尾很难获得单元模组串的长度，但是从到前其实很简单
        // 因为一旦第一个模组串结束，后面都是递增了
        int next[s.size()];
        getNext(next, s);
        int len = s.size();
        if (next[len - 1] != 0 && len % (len - next[len - 1]) == 0)
        {
            return true;
        }
        return false;
    }
};