#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        // 因为是字母所以我们可以不用map,这样可以保存更多的时间和空间
        int record[26] = {0};
        for (int i = 0; i < magazine.size(); i++)
        {
            record[magazine[i] - 'a']++;
        }
        for (int i = 0; i < ransomNote.size(); i++)
        {
            record[ransomNote[i] - 'a']--;
            if (record[ransomNote[i] - 'a'] < 0)
            {
                return false;
            }
        }
        return true;
    }
};