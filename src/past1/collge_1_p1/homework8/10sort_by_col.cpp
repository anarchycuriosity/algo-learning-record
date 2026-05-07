#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
const int SIZE = 3;
void sortColumns(const double m[ ][SIZE], double result[ ][SIZE])
{
    for(int j =0;j < SIZE;j++)
    {   //先用一维数组对接2维中 的一维
        double col[SIZE];
        /*
        sort(m,m+SIZE * SIZE,[j](auto &a,auto &b)
        {
            for(int i = 0;i < SIZE;i ++)
            {
                return a[i][j] < a[i][j];
            }
        })
        */
       //sort中的lambda并不支持二维数组的使用,主要是对一维的容器
       for(int i =0;i < SIZE;i++)
       {
            col[i] = m[i][j];
       }
       sort(col,col + SIZE);
       for(int i = 0;i < SIZE;i++)
       {
            result[i][j] = col[i];
       }
    }
}
int main()
{
    double m[SIZE][SIZE],result[SIZE][SIZE];
    for(int i =0;i < SIZE;i++)
    {
        for(int j = 0;j < SIZE;j++)
        {
            cin >> m[i][j];
        }
    }
    sortColumns(m,result);
    for(int i = 0;i < SIZE;i++)
    {
        for(int j = 0;j < SIZE;j++)
        {
            cout << result[i][j] << "  ";
        }
        cout << endl;
    }
    return 0;
}