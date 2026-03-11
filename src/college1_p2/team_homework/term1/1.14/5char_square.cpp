#include <bits/stdc++.h>
// 初始化有很多问题
bool inside(int x, int y, int len)
{
    if (x >= 0 && x < len && y >= 0 && y < len)
    {
        return true;
    }
    return false;
}
// 不要瞎用列表初始化
// std::vector<char> yizhong{yizhong};
std::vector<char> yizhong{'y', 'i', 'z', 'h', 'o', 'n', 'g'};
std::vector<int> row_step{0, 1, 2, 3, 4, 5, 6};
std::vector<int> anti_row{0, -1, -2, -3, -4, -5, -6};
std::vector<int> col_step{0, 1, 2, 3, 4, 5, 6};
std::vector<int> anti_col{0, -1, -2, -3, -4, -5, -6};
int judge(std::vector<std::vector<char>> map, int x, int y, int len)
{
    if (map[x][y] != 'y')
    {
        return 0;
    }
    int count = 0;

    // 左右1右左5
    for (int i = 0; i < 7; i++)
    {
        int nx = x + row_step[i];
        if (!inside(nx, y, len))
        {
            break;
        }
        if (map[nx][y] == yizhong[i])
        {
            count++;
        }
    }
    if (count == 7)
    {
        return 1; // 从左到右
    }
    count = 0;
    for (int i = 0; i < 7; i++)
    {
        int nx = x + anti_row[i];
        if (!inside(nx, y, len))
        {
            break;
        }
        if (map[nx][y] == yizhong[i])
        {
            count++;
        }
    }
    if (count == 7)
    {
        return 5; // 从右到左
    }
    count = 0;

    // 上2下6
    for (int i = 0; i < 7; i++)
    {
        int ny = y + col_step[i];
        if (!inside(x, ny, len))
        {
            break;
        }
        if (map[x][ny] == yizhong[i])
        {
            count++;
        }
    }
    if (count == 7)
    {
        return 2;
    }
    count = 0;
    for (int i = 0; i < 7; i++)
    {
        int ny = y + anti_col[i];
        if (!inside(x, ny, len))
        {
            break;
        }
        if (map[x][ny] == yizhong[i])
        {
            count++;
        }
    }
    if (count == 7)
    {
        return 6;
    }
    count = 0;

    // 正斜上3正斜下4反斜上7反斜下8
    for (int i = 0; i < 7; i++)
    {
        int nx = x + row_step[i];
        int ny = y + col_step[i];
        if (!inside(nx, ny, len))
        {
            break;
        }
        if (map[nx][ny] == yizhong[i])
        {
            count++;
        }
    }
    if (count == 7)
    {
        return 3;
    }
    count = 0;

    for (int i = 0; i < 7; i++)
    {
        int nx = x + row_step[i];
        int ny = y - col_step[i];
        if (!inside(nx, ny, len))
        {
            break;
        }
        if (map[nx][ny] == yizhong[i])
        {
            count++;
        }
    }
    if (count == 7)
    {
        return 4;
    }
    count = 0;
    for (int i = 0; i < 7; i++)
    {
        int nx = x + anti_row[i];
        int ny = y + anti_col[i];
        if (!inside(nx, ny, len))
        {
            break;
        }
        if (map[nx][ny] == yizhong[i])
        {
            count++;
        }
    }
    if (count == 7)
    {
        return 7;
    }
    count = 0;

    for (int i = 0; i < 7; i++)
    {
        int nx = x + anti_row[i];
        int ny = y - anti_col[i];
        if (!inside(nx, ny, len))
        {
            break;
        }
        if (map[nx][ny] == yizhong[i])
        {
            count++;
        }
    }
    if (count == 7)
    {
        return 8;
    }
    count = 0;
    return 0;
}
int main()
{
    int n;
    std::cin >> n;
    // std::vector<std::vector<bool>> matched{n, std::vector<bool>(n, false)}; // 列表初始化是错误的
    // 这会被解析成一个大小为2的vector
    std::vector<std::vector<bool>> matched(n, std::vector<bool>(n, false)); // 调用构造函数圆括号初始化
    std::vector<std::vector<char>> map(n, std::vector<char>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> map[i][j];
        }
    }
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            if (judge(map, x, y, n) == 1)
            {
                for (int i = 0; i < 7; i++)
                {
                    int nx = x + row_step[i];
                    matched[nx][y] = true;
                }
            }
            else if (judge(map, x, y, n) == 5)
            {
                for (int i = 0; i < 7; i++)
                {
                    int nx = x + anti_row[i];
                    matched[nx][y] = true;
                }
            }
            else if (judge(map, x, y, n) == 2)
            {
                for (int i = 0; i < 7; i++)
                {
                    int ny = y + col_step[i];
                    matched[x][ny] = true;
                }
            }
            else if (judge(map, x, y, n) == 6)
            {
                for (int i = 0; i < 7; i++)
                {
                    int ny = y + anti_col[i];
                    matched[x][ny] = true;
                }
            }
            else if (judge(map, x, y, n) == 3)
            {
                for (int i = 0; i < 7; i++)
                {
                    int nx = x + row_step[i];
                    int ny = y + col_step[i];
                    matched[nx][ny] = true;
                }
            }
            else if (judge(map, x, y, n) == 4)
            {
                for (int i = 0; i < 7; i++)
                {
                    int nx = x + row_step[i];
                    int ny = y - col_step[i];
                    matched[nx][ny] = true;
                }
            }
            else if (judge(map, x, y, n) == 7)
            {
                for (int i = 0; i < 7; i++)
                {
                    int nx = x + anti_row[i];
                    int ny = y + anti_col[i];
                    matched[nx][ny] = true;
                }
            }
            else if (judge(map, x, y, n) == 8)
            {
                for (int i = 0; i < 7; i++)
                {
                    int nx = x + anti_row[i];
                    int ny = y - anti_col[i];
                    matched[nx][ny] = true;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matched[i][j])
            {
                std::cout << map[i][j];
            }
            else
            {
                std::cout << "*";
            }
        }
        std::cout << std::endl;
    }
}