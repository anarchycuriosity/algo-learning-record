#include <vector>
#include <iostream>

// 检查坐标是否在棋盘范围内
bool inside(int x, int y, int b_x, int b_y)
{
    if (x >= 0 && y >= 0 && x <= b_x && y <= b_y)
    {
        return true;
    }
    return false;
}

int main()
{
    // 马的 8 个跳跃方向
    std::vector<int> h_dx = {2, 2, 1, 1, -1, -1, -2, -2};
    std::vector<int> h_dy = {1, -1, 2, -2, 2, -2, 1, -1};

    int des_x = 0, des_y = 0;
    int h_x = 0, h_y = 0;

    if (!(std::cin >> des_x >> des_y >> h_x >> h_y))
    {
        return 0;
    }

    // 使用 long long 防止路径数溢出
    // 初始化地图大小为 (des_x + 1) * (des_y + 1)
    std::vector<std::vector<long long>> map(des_x + 1, std::vector<long long>(des_y + 1, 0));
    // 标记控制点的布尔数组，防止 DP 过程混乱
    std::vector<std::vector<bool>> is_danger(des_x + 1, std::vector<bool>(des_y + 1, false));

    // 1. 标记马的控制点
    is_danger[h_x][h_y] = true;
    for (int i = 0; i < 8; i++)
    {
        int danger_x = h_x + h_dx[i];
        int danger_y = h_y + h_dy[i];
        if (inside(danger_x, danger_y, des_x, des_y))
        {
            is_danger[danger_x][danger_y] = true;
        }
    }

    // 2. 初始化起点
    if (!is_danger[0][0])
    {
        map[0][0] = 1;
    }

    // 3. 动态规划填表
    for (int i = 0; i <= des_x; i++)
    {
        for (int j = 0; j <= des_y; j++)
        {
            // 如果是控制点或者起点，跳过计算
            if (is_danger[i][j] || (i == 0 && j == 0))
            {
                continue;
            }

            // 状态转移方程：当前格子的路径数 = 上方格子路径数 + 左方格子路径数
            if (i > 0)
            {
                map[i][j] += map[i - 1][j];
            }
            if (j > 0)
            {
                map[i][j] += map[i][j - 1];
            }
        }
    }

    // 4. 输出终点结果
    std::cout << map[des_x][des_y] << std::endl;

    return 0;
}