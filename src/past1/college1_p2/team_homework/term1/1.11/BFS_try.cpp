#include <bits/stdc++.h>
struct Node
{
    int x, y, step;
};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
// 养成写引用传参的习惯吧，不然就又复制一次了
int bfs(std::vector<std::vector<char>> &maze, int sx, int sy, int n, int m)
{
    std::queue<Node> q;
    q.push({sx, sy, 0});
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
    visited[sx][sy] = true;
    while (!q.empty())
    {
        Node cur = q.front();
        q.pop();
        if (maze[cur.x][cur.y] == 'T')
        {
            return cur.step;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (maze[nx][ny] != '#' && !visited[nx][ny])
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny, cur.step + 1});
                }
            }
        }
    }
    // 如果不返回点什么可能就拿不到满分了
    return 0;
}
int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<char>> maze(n, std::vector<char>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> maze[i][j];
        }
    }
    int sx, sy;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (maze[i][j] == 'S')
            {
                sx = i;
                sy = j;
            }
        }
    }
    std::cout << bfs(maze, sx, sy, n, m);
}