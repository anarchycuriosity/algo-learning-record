#include <bits/stdc++.h>
int main()
{
    int n;
    std::cin >> n;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        pq.push(x);
    }
    int cost = 0;
    while (pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int merge = a + b;
        cost += merge;
        pq.push(merge);
    }
    std::cout << cost;
}