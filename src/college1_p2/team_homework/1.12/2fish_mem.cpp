#include <bits/stdc++.h>
int main()
{
    std::stack<int> mem;
    int num = 1;
    while (num != 0)
    {
        std::cin >> num;
        mem.push(num);
    }
    mem.pop();
    while (!mem.empty())
    {
        std::cout << mem.top() << " ";
        mem.pop();
    }
}
