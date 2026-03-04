#include <bits/stdc++.h>
int main()
{
    std::string s;
    //int n = s.size();
    //位置写的不对，此时还未读入
    long long N;
    std::cin >> s >> N;
    N--;
    int n = s.size();
    int change_time = 0;
    while(N > n * std::pow(2,change_time))
    {
        change_time++;
    }
    std::stack<std::string> st;
    for(int time = 0;time < change_time;time++)
    {
        /*
        误解题目了，给我好好读题
        for(int i = 0;i < n;i++)
        {
            st.push(std::string(1,s[i]));
        }
        for(int i = 0;i < n;i++)
        {
            s = s + st.top();
            st.pop();
        }
        n*=2;
        */
        for(int i = 0;i < n;i++)
        {
            st.push(std::string(1,s[i]));
        }
        std::vector<std::string> res;
        s = s + st.top();
        st.pop();
        for(int i = 0;i < n - 1;i++)
        {
            res.emplace_back(st.top());
            st.pop();
        }
        for(int i = res.size() - 1;i >= 0;i--)
        {
            s = s + res[i];
        }
        n*=2;
    }
    std::cout << s[N - 1];

}