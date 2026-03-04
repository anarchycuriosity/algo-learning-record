#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct Node
{
    int x, y, step;
};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(vector<string> &maze, int n, int m, int sx, int sy)
{
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<Node> q;
    q.push({sx, sy, 0});
    visited[sx][sy] = true;

    while (!q.empty())
    {
        Node cur = q.front();
        q.pop();

        if (maze[cur.x][cur.y] == 'E')
        {
            return cur.step;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (!visited[nx][ny] && maze[nx][ny] != '#')
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny, cur.step + 1});
                }
            }
        }
    }
    return -1; // 无法到达出口
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> maze(n);

    int sx = -1, sy = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> maze[i];
        for (int j = 0; j < m; j++)
        {
            if (maze[i][j] == 'S')
            {
                sx = i;
                sy = j;
            }
        }
    }

    int ans = bfs(maze, n, m, sx, sy);
    if (ans == -1)
    {
        cout << "无法到达出口" << endl;
    }
    else
    {
        cout << "最短步数: " << ans << endl;
    }

    return 0;
}
