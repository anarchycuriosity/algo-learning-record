#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
const int SIZE = 4;
struct line
{
    int id;
    int times = 0;
};
int main()
{
    //生成随机矩阵
    /*
    srand(time(0));
    int matrix[SIZE][SIZE];
    for(int i = 0;i < SIZE ;i++)
    {
        for(int j = 0;j < SIZE;j++)
        {
            matrix[i][j] = rand() % 2;
        }
    }
    */
   int matrix[SIZE][SIZE];
    for(int i = 0;i < SIZE ;i++)
    {
        for(int j = 0;j < SIZE;j++)
        {
            cin >> matrix[i][j];
        }
    }
    line rows[4],cols[4];
    //把id塞进去
    for(int i = 0;i < 4;i++)
    {
        rows[i].id = i;
    }
    for(int i = 0;i < 4;i++)
    {
        cols[i].id = i;
    }
    //跳行和列的计数器
    for(int i = 0;i < 4;i++)
    {
        for(int j = 0;j < 4;j ++)
        {
            if(matrix[i][j] == 1)
            {
                rows[i].times++;
            }
        }
    }
    for(int j = 0;j < 4;j++)
    {
        for(int i = 0;i < 4;i ++)
        {
            if(matrix[i][j] == 1)
            {
                cols[j].times++;
            }
        }
    }
    //把最大的计数器的行和列排最前面
    sort(begin(rows),end(rows),[](const line &a, const line & b)
    {
        if(a.times != b.times)
        {
            return a.times > b.times;
        }
        else
        {
            return a.id < b.id;
        }
    });
    sort(begin(cols),end(cols),[](const line &a, const line & b)
    {
        if(a.times != b.times)
        {
            return a.times > b.times;
        }
        else
        {
            return a.id < b.id;
        }
    });
    //输出随机矩阵
    /*
    for(int i = 0;i < 4;i++)
    {
        for(int j = 0;j < 4; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    */
    //输出第一位的id
    cout << "数字1最多的行" << rows[0].id << endl;
    cout << "数字1最多的列" << cols[0].id;
    return 0;
}