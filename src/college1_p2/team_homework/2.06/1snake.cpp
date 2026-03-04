#include <vector>
#include <iostream>
#include <iomanip>
int main()
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
    int x = 0, y = 0;
    int dy[] = {1, 0, -1, 0};
    int dx[] = {0, 1, 0, -1};
    int j = 0;
    for (int i = 1; i <= n * n; i++)
    {
        matrix[x][y] = i;
        j = j % 4;

        int ifx = x + dx[j];
        int ify = y + dy[j];
        // 逻辑或是从左到右检查的，一定是先检查下标范围，再访问数组元素
        // if (ifx >= n || ify >= n || matrix[ifx][ify] != 0 || ifx < 0 || ify < 0)
        // 必须先拦住负数和越界的下标，最后才能访问 matrix[ifx][ify]
        if (ifx < 0 || ifx >= n || ify < 0 || ify >= n || matrix[ifx][ify] != 0)
        {
            j++;       // 这样写的问题是，很多时候不只是需要一次转向
            j = j % 4; // 忘记写
            ifx = x + dx[j];
            ify = y + dy[j];
        }
        x = ifx;
        y = ify;
    }
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            std::cout << std::setw(3) << matrix[i][k];
        }
        std::cout << std::endl;
    }
}