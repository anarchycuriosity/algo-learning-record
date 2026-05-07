#include <vector>
#include <iostream>
bool inside(int x, int y, int b_x, int b_y) // b(bound)
{
    if (x >= 0 && y >= 0 && x <= b_x && y <= b_y)
    {
        return true;
    }
    return false;
}
int main()
{
    // 一开始跳跃方向写少了
    std::vector<int> h_dx = {2, 2, -2, -2, 1, 1, -1, -1};
    std::vector<int> h_dy = {1, -1, 1, -1, 2, -2, 2, -2};
    std::vector<int> s_dx = {1, 0, 0};
    std::vector<int> s_dy = {0, 1, -1};
    int des_x = 0, des_y = 0;
    int h_x = 0, h_y = 0;
    std::cin >> des_x >> des_y >> h_x >> h_y;
    std::vector<std::vector<long long>> map(des_x + 1, std::vector<long long>(des_y + 1, 0));
    // 这里要 + 1，因为des不是棋盘角落坐标长度
    // 不要在原map中标记,需要额外使用一个布尔地图
    // 因为这是求路径和,否则最后累加会混乱
    std::vector<std::vector<bool>> b_map(des_x + 1, std::vector<bool>(des_y + 1, false));
    map[0][0] = 1;
    for (int i = 0; i < 8; i++)
    {
        int danger_x = h_x + h_dx[i];
        int danger_y = h_y + h_dy[i];
        // vector的二维数组容易搞错，访问容器之间记得做边界判断
        if (inside(danger_x, danger_y, des_x, des_y))
        {
            b_map[danger_x][danger_y] = true;
        }
    }
    b_map[h_x][h_y] = true;
    for (int x = 0; x <= des_x; x++)
    {
        for (int y = 0; y <= des_y; y++)
        {
            for (int i = 0; i < s_dx.size(); i++) // 这里曾经把s_dx错写成了h_dx
            {
                int nx = x, ny = y;
                nx += s_dx[i];
                ny += s_dy[i];
                // if (inside(nx, ny, des_x, des_y) && b_map[nx][ny] == false)
                if (inside(nx, ny, des_x, des_y)) // 因为是取交集,不符合要求就不能访问容器
                {
                    if (b_map[nx][ny] == false)
                    {
                        map[nx][ny] += map[x][y];
                    }
                }
            }
        }
    }
    std::cout << map[des_x][des_y];
}