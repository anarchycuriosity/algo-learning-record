#include <iostream>
#include <array>
#include <algorithm>
#include <map>
using namespace std;
const int COLSIZE = 6,ROWSIZE = 7;
bool isconsecutivefour(array<array<int,ROWSIZE>,COLSIZE> &m)
{
    //这仅仅只能判断数字次数,并不能符合连续的要求
    /*
    for(int i = 0;i < COLSIZE;i++)
    {
        //每行开始的时候初始化map,分别统计每行的键值对
        map<int,int> freq_in_rows;
        for(int j =0;j < ROWSIZE;j++)
        {
            freq_in_rows[m[i][j]]++;
        }
        for(const auto& [key,val] : freq_in_rows)
        {
            if(val == 4)
            return true;
            break;
        }
        if(isconsecutivefour) break;
    }
    //列的时候同上
    for(int j = 0;j < ROWSIZE;j++)
    {
        map<int,int> freq_in_cols;
        for(int i =0;j < COLSIZE;i++)
        {
            freq_in_cols[m[i][j]]++;
        }
        for(const auto& [key,val] : freq_in_cols)
        {
            if(val == 4)
            return true;
            break;
        }
        if(isconsecutivefour) break;
    }
    */


    //水平
    for(int i =0;i < COLSIZE -3;i++)
    {
        for(int j =0;j < ROWSIZE - 3 ;j++)
        {
            if(m[i][j] == m[i][j+1] && m[i][j] == m[i][j + 2] && m[i][j] == m[i][j+3])
            {
                return true;
            }
        }
    }

    for(int j =0;j < ROWSIZE - 3 ;j++)
    {
        for(int i =0;i < COLSIZE -3;i++)
        {
            if(m[i][j] == m[i + 1][j] && m[i][j] == m[i + 2][j ] && m[i][j] == m[i + 3][j])
            {
                return true;
            }
        }
    }
    for(int i =0;i < COLSIZE -3;i++)
    {
        for(int j =0;j < ROWSIZE - 3 ;j++)
        {
            if(m[i][j] == m[i + 1][j+1] && m[i][j] == m[i + 2][j + 2] && m[i][j] == m[i + 3][j+3])
            {
                return true;
            }
        }
    }
    for(int i =COLSIZE;i >= 3;i--)//这里曾写成自加死循环
    {
        for(int j =0;j < ROWSIZE - 3 ;j++)
        {
            if(m[i][j] == m[i - 1][j+1] && m[i][j] == m[i - 2][j + 2] && m[i][j] == m[i - 3][j+3])
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    array<array<int,ROWSIZE>,COLSIZE> m;
    for(int i = 0;i < COLSIZE;i ++)
    {
        for(int j = 0;j < ROWSIZE;j++)
        {
            cin >> m[i][j];
        }
    }
    if(isconsecutivefour(m))
    {
        cout << "true";
    }
    else 
    {
        cout << "false";
    }
    return 0;
}
