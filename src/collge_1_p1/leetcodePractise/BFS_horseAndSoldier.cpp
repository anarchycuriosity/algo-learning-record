#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 判断是否是马的危险点
bool isHorseDanger(int x, int y, int hx, int hy) {
    int dx[] = {1, 2, -1, -2, 1, 2, -1, -2};
    int dy[] = {2, 1, 2, 1, -2, -1, -2, -1};
    for (int k = 0; k < 8; k++) {
        if (x == hx + dx[k] && y == hy + dy[k]) return true;
    }
    if (x == hx && y == hy) return true; // 马所在点也不能走
    return false;
}

int main() {
    int tx, ty, hx, hy;
    cin >> tx >> ty >> hx >> hy;

    // 棋盘大小至少要覆盖到终点
    vector<vector<long long>> ways(tx+1, vector<long long>(ty+1, 0));
    queue<pair<int,int>> q;

    // 起点
    ways[0][0] = 1;
    q.push({0,0});

    // BFS
    while (!q.empty()) {
        auto [x,y] = q.front();
        //相当于
        //int x = q.front().first;
        //int y = q.front().second;
        q.pop();

        // 三个方向：下、左、右
        int dx[] = {1,0,0};
        int dy[] = {0,-1,1};

        for (int k=0; k<3; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || ny < 0 || nx > tx || ny > ty) continue;
            if (isHorseDanger(nx, ny, hx, hy)) continue;

            // 累加路径数
            if (ways[nx][ny] == 0) q.push({nx,ny});
            ways[nx][ny] += ways[x][y];
        }
    }

    cout << ways[tx][ty] << endl;
    return 0;
}
