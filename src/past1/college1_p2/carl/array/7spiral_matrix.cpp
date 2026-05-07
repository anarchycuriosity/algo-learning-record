#include <vector>
#include <iostream>

// 状态机与螺旋矩阵
// >状态机是一种根据当前状态和输入,决定下一个状体和动作的数学模型
// * 比如这题来说,状态就是当前的前进方向mod
// * 转移条件就是越界或者踩到已经填过从格子
// * 动作就是变向并填充数字
class Solution
{
public:
    std::vector<std::vector<int>> generateMatrix(int n)
    {
        std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
        std::vector<int> dx = {0, 1, 0, -1};
        std::vector<int> dy = {1, 0, -1, 0};
        int x = 0, y = 0;
        int mod = 0;
        for (int i = 1; i <= n * n; i++)
        {
            matrix[x][y] = i;
            int nx = x + dx[mod];
            int ny = y + dy[mod];
            if (nx >= n || ny >= n || nx < 0 || ny < 0 || matrix[nx][ny] != 0)
            {
                mod++;
                mod = mod % 4;
                nx = x + dx[mod];
                ny = y + dy[mod];
            }
            x = nx;
            y = ny;
        }
        return matrix;
    }
};