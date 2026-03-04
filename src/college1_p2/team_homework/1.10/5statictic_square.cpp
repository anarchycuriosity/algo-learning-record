#include <bits/stdc++.h>
//不要误解棋盘和矩阵
int main()
{
    int n,m;
    std::cin >> n >> m;
    int square = 0;
    int rec = 0;
    for(int start_row = 1;start_row <= n;start_row++)
    {
        for(int end_row = start_row;end_row <= n;end_row++)
        {
            int height = end_row - start_row + 1;
            for(int left_col = 1;left_col <= m;left_col++)
            {
                for(int right_col = left_col;right_col <= m;right_col++)
                {
                    int width = right_col - left_col + 1;
                    if(height == width)
                    {
                        square++;
                    }
                    else
                    {
                        rec++;
                    }
                }
            }
        }
    }
    std::cout << square << " " << rec;
}