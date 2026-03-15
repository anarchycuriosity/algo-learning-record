// 顺便复习一下重载和重写
// 重载发生在同一个类里面，函数名必须相同，但是参数列表必须不同
// 不能根据返回值的不同来区分重载
// 本质是为了让一个名字的函数能够处理多种数据类型

// 重写发生在继承之中
// 函数名参数列表和返回值必须完全相同

// 但其实本题主要涉及一个流的读取和解析
#include <stack>
#include <iostream>
#include <vector>
#include <cmath>
int transform(std::vector<int> &num)
{
    int res = 0;
    for (int i = 0; i < num.size(); i++)
    {
        res += std::pow(10, num.size() - 1) * num[i];
    }
    return res;
}
int main()
{
    std::stack<char> stL;
    std::stack<char> stR;
    std::stack<std::vector<int>> stRN;
    std::string s;
    std::cin >> s;
    int a = 0, b = 0, c = 0;
    std::vector<int> var = {a, b, c};
    for (int i = 0; i < s.size(); i++)
    {
        // 处理左值
        if (stL.empty() && (s[i] == 'a' || s[i] == 'b' || s[i] == 'c')) // 这里可能会让右值不小心被压入左值
        {
            stL.push(s[i]);
        }
        else if (s[i] == ':' && s[i + 1] == '=') // 处理右值
        {
            int j = i + 2;
            if (s[j] == 'a' || s[j] == 'b' || s[j] == 'c')
            {
                stR.push(s[j]);
            }
            else if (s[j] >= '0' && s[j] <= '9')
            {
                std::vector<int> num;
                while (s[j] != ';')
                {
                    num.push_back(s[j] - '0');
                    j++;
                }
                stRN.push(num);
            }
        }
        else if (s[i] == ';') // 当前循环结束，清除两个栈
        {
            if (!stL.empty() && !stR.empty())
            {
                // 没有考虑ab互换的情况
                /*
                if (stL.top() == 'a' && stR.top() == 'b')
                {
                    a = b;
                }
                else if (stL.top() == 'a' && stR.top() == 'c')
                {
                    a = c;
                }
                else if (stL.top() == 'b' && stR.top() == 'c')
                {
                    b = c;
                }
                stL.pop();
                stR.pop();
                */
                var[stL.top() - 'a'] = var[stR.top() - 'a'];
                stL.pop();
                stR.pop();
            }
            else if (!stL.empty() && !stRN.empty())
            {
                var[stL.top() - 'a'] = transform(stRN.top());
                stL.pop();
                stRN.pop();
            }
        }
    }
    std::cout << var[0] << " " << var[1] << " " << var[2];
}