#include <stack>
#include <iostream>
#include <string>
int main()
{
    std::string str;
    std::cin >> str;
    std::stack<char> st;
    for (char ch : str)
    {
        if (ch == '(')
        {
            st.push('(');
        }
        else if (!st.empty() && ch == ')')
        {
            st.pop(); // 先检查空没空再决定是否弹出
        }
        else if (st.empty() && ch == ')')
        {
            std::cout << "NO";
            return 0;
        }
    }
    if (st.empty())
    {
        std::cout << "YES";
    }
    else
    {
        std::cout << "NO";
    }
}