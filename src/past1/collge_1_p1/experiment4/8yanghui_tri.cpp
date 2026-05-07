#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int main()
{
    //用0填满输出的矩阵
    int n;
    cin >> n;
    vector<vector<int>> matrix(n,vector<int>(2*n-1,0));
    //填充1到指定位置
    for(int i = 0;i < n;i++)
    {
        matrix[i][n - 1 - i] = 1;
        matrix[i][n - 1 + i] = 1;
    }
    //计算
    for(int i = 0;i < n - 1;i++)//记得是 - 1,下面的j也要-2
    {
        for(int j = 0;j < 2 * n - 1 - 2;j++)
        {
            matrix[i + 1][j + 1] = matrix[i][j] + matrix[i][j + 2];
        }
    }
    //把0改成好看的东西
    //打印
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < 2 * n - 1;j++)
        {
            if(matrix[i][j] == 0)
            {
                cout << setw(4) << " ";
            }
            else
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}