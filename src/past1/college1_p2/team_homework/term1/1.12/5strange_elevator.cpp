#include <bits/stdc++.h>
// 一些改进的方法，可以把move_tot的容量上限改成top+1这样直接用楼层索引
//
struct Node
{
    int floor, step;
};

int bfs(int top, int A, int B, std::vector<int> move_tot)
{
    std::vector<bool> visited(top, false);
    visited[A - 1] = true;
    std::queue<Node> q;
    q.push({A, 0});
    while (!q.empty())
    {
        Node cur = q.front();
        q.pop();
        if (cur.floor == B)
        {
            return cur.step;
        }
        int num = move_tot[cur.floor - 1];
        std::vector<int> move;
        move.emplace_back(-num);
        move.emplace_back(num);
        for (int i = 0; i < move.size(); i++)
        {
            int n_floor = cur.floor + move[i];
            if (n_floor <= top && n_floor > 0)
            {
                if (visited[n_floor - 1] == false)
                {
                    visited[n_floor - 1] = true;
                    q.push({n_floor, cur.step + 1});
                }
            }
        }
    }
    return -1;
}

int main()
{
    int top, A, B;
    std::cin >> top >> A >> B;

    std::vector<int> move_tot;
    for (int i = 0; i < top; i++)
    {
        int num;
        std::cin >> num;
        move_tot.emplace_back(num);
    }
    std::cout << bfs(top, A, B, move_tot);
}