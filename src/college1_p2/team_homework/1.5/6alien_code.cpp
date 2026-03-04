#include <bits/stdc++.h>
int main()
{
    std::string code;
    std::getline(std::cin,code);

    int n = code.size();
    std::stack<std::string> st;
    for(char ch : code)
    {
        if(ch != ']')
        {
            st.push(std::string(1,ch));
        }
        else
        {
            std::string tmp;
            //注意边界判定，前面还要保证不要被弹完了
            while(!st.empty() && st.top() != "[")
            {
                //tmp = tmp + st.top();top相较于tmp来说一直都是在它前面的，字符串a + b严格按照左右顺序拼接
                tmp = st.top() + tmp;
                st.pop();
            }
            if(!st.empty() && st.top() == "[")
            {
                st.pop();
            }
            int num = 0;
            //因为要截取字符串，所以要想办法记录下数字部分的索引
            /*
            for(int i = 0;i < tmp.size();i++)
            {
                if(std::isdigit(tmp[i]))
                {
                    num = num * 10 + (tmp[i] - '0');
                }
            }
            */
            int i = 0;
            while(i < tmp.size() && std::isdigit(tmp[i]))
            {
                num = num * 10 + (tmp[i] - '0');
                i++;
            }
            std::string str_part = tmp.substr(i);
            std::string to_st;
            while(num--)
            {
                to_st += str_part;
            }
            st.push(to_st);
        }
    }
    std::string ans;
    std::vector<std::string> pre_ans;
    while(!st.empty())
    {
        pre_ans.emplace_back(st.top());
        st.pop();
    }
    for(int i = pre_ans.size() - 1;i >=0;i--)
    {
        ans += pre_ans[i];
    }
    std::cout << ans;
}