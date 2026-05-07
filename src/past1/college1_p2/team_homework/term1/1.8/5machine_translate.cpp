#include <bits/stdc++.h>
//两个结构来分别承担顺序正确(queue)和查找(unordered_set)快这两件事
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int M,N;
    std::cin >> M >> N;
    std::queue<int> cache_q;
    std::unordered_set<int> cache_s;
    int miss_count = 0;
    for(int i = 0;i < N;i++)
    {
        int x;
        std::cin >> x;
        if(cache_s.find(x) == cache_s.end())
        {
            miss_count++;
            if(cache_q.size() == M)
            {
                cache_s.erase(cache_q.front());
                cache_q.pop();
                //cache_q.push(x);满的时候只删去，不要重复push
            }
            
            cache_q.push(x);
            cache_s.insert(x);
            
        }
    }
    std::cout << miss_count;
}