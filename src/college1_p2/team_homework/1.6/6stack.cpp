#include <bits/stdc++.h>
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int count;
    std::cin >> count;
    while(count --)
    {
        int n;
        std::cin >> n;

        std::vector<int> pushed;
        std::vector<int> popped;
        for(int i = 0;i < n;i++)
        {
            int push;
            std::cin >> push;
            pushed.emplace_back(push);
        }
        for(int i = 0;i < n;i++)
        {
            int pop;
            std::cin >> pop;
            popped.emplace_back(pop);
        }
        std::stack<int> st;
        int id_pop = 0;
        for(int i = 0;i < n;i++)
        {
            st.push(pushed[i]);
            while(!st.empty() && st.top() == popped[id_pop])
            {
                st.pop();
                id_pop++;
            }
        }
        if(id_pop == n)
        {
            std::cout << "Yes\n";
        }
        else
        {
            std::cout << "No\n";
        }
    }
    return 0;
}