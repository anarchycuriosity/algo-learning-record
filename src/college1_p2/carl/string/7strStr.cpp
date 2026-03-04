
// kmp,前缀表，next数组
// KMP的经典思想就是:当出现字符串不匹配时，可以记录一部分之前已经匹配的文本内容，利用这些信息避免从头再去做匹配。
// 利用已知信息规避重复劳动，失败并不是没用了，而是一种信息采集
// 前缀是指不包含最后一个字符的所有以第一个字符开头的连续子串；后缀是指不包含第一个字符的所有以最后一个字符结尾的连续子串。
/*
特别易错的是，拿aaabaaaf下标为6的这个模式串来解释
比如aaabaaa，最后一个的next数组元素并不是6而是3，取完来看，前缀是aaabaa，后缀是aabaaa，比较需要从左向右看
而不是前缀从左向右，后缀从右向左
若字符串是aaabaaab，当到第二个b的时候，回过头看看next数组的屁股，发现公共前后缀是3，也就是说我没必要回到头
而是可以直接去比较索引为3的模式串。
只要和回文区分即可，只要和回文区分即可，只要和回文区分即可
*/
#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    void getNext(int *next, const string &s)
    {
        // 主要包含两个操作，回退和判断是否相等，如果相等就赋值
        // 回退操作和判断可以调换顺序，回退操作其实也包含了相等的判断，只是需要while语句所以分离。二者是互斥的
        // 但是我们需要养成一个先排除干扰再确定成果的习惯
        // string不包含休止符sizeof(char [])常量会包含结束符
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.size(); i++)
        {
            // 回退操作
            while (j > 0 && s[i] != s[j])
            {
                j = next[j - 1];
            }
            if (s[i] == s[j])
            {
                j++;
            }
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle)
    {
        // if (needle == " ")
        if (needle.size() == 0)
        {
            return 0;
        }
        int *next = new int[needle.size()];
        getNext(next, needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); i++)
        {

            while (j > 0 && haystack[i] != needle[j])
            {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j])
            {
                j++;
            }
            if (j == needle.size())
            {
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};