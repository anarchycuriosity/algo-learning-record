#include <iostream>
#include <string>
#include <vector>
#include <cmath>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        //可以考虑一下如果参数啥也没塞进去的情况呢，虽然一般不会有
        //但是建议是总得进入出来点什么东西
        if(strs.empty())
        {
            return "";
        }

        int idx = 0;
        //这里的result没给数值，只能push_back
        std::string result = "";
        int min = strs[0].size();
        for(auto &str : strs)
        {
            if(min >= str.size())
            {
                min = str.size();
            }
        }
        /*
        for(int i = 0;i < strs.size();i++)
        {
            char ch = strs[0][idx];
            for(int j = 0;j < min;j++)
            {
                //
                if(ch != strs[i][j])
                {
                    break;
                }
                if(j == min - 1)
                {
                    result.push_back(ch);
                    idx++;
                }
                //
               //不匹配就应该直接返回，不要这么婆婆妈妈的
               if(ch != strs[i][j])
                {
                    return result;
                }
                if(j == min - 1)
                {
                    result.push_back(ch);
                    idx++;
                }
            }
        }

        //判断逻辑有点混乱了，你得拿着第i个字母取逐个找strs里面的j才对
        */
       for(idx;idx < min;idx++)
       {
        char ch = strs[0][idx];
        for(int i = 0;i < strs.size();i++)
        {
            if(ch != strs[i][idx])
            {
                return result;
            }
            //写到for循环里面了，这会push很多进去
            //result.push_back(ch);
        }
        result.push_back(ch);
       }
        return result;
    }
};

int main()
{
    int n;
    std::string result;
    std::cin >> n;
    std::vector<std::string> strs(n);
    for(int i = 0;i < n;i++)
    {
        std::string str;
        std::cin >> str;
        strs[i] = str;
    }
    Solution sol;
    result = sol.longestCommonPrefix(strs);
    std::cout << result;
}