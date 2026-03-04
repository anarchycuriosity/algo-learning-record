/*
判断字母异位的暴力写法,一种是列出a词所有可能的排列,如果b词符合就ok
复杂度是n!

第二种两层for循环,第一层遍历a,第二层遍历b并标记对应词为不可用字符
复杂度为n*n

当我们需要快速查找,应该第一时间想到哈希查找
数组,set,map.本质就是根据索引拿到对应的值,下标也是一种索引
O(1)代表常数级,它不随参数的长度变化而变化,只要它是固定的,就是O(1)
我们可以记录已经出现的字母的数字，如果再出现就--，最后如果没剩下的就ok
*/

#include <string>
using namespace std;
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int record[26] = {0}; // 如果是{1}，剩下的25个会自动补充为0
        for (int i = 0; i < s.size(); i++)
        {
            record[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++)
        {
            record[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (record[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};