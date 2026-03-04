#include <bits/stdc++.h>

int main()
{
    std::string str;
    std::cin >> str;
    int n = str.size();

    std::vector<bool> match(n,false);
    std::stack<int> unmatch;
    for(int i = 0;i < n;i++)
    {
        if(str[i] == '(' || str[i] == '[')
        {
            unmatch.push(i);
        }
        else
        {
            if(!unmatch.empty())
            {
                int t = unmatch.top();
                if((str[i] == ')' && str[t] == '(') ||(str[i] == ']' && str[t] == '[') )
                {
                    match[i] = true;
                    match[t] = true;
                    unmatch.pop();
                }
            }
        }
    }
    for(int i = 0;i < n;i++)
    {
        if(match[i])
        {
            std::cout << str[i];
        }
        else
        {
            if(str[i] == '(' || str[i] == ')')
            {
                std::cout << "()";
            }
            else
            {
                std::cout << "[]";
            }
        }
    }
}