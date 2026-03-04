#include <bits/stdc++.h>
//引入一个方向数组的概念
//同时写一个通用的边界判断
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {1,0,-1,1,-1,1,0,-1};
bool inside(int x,int y,int n,int m)
{
    return x < n && x >=0 && y < m && y >=0;
}
//对单个格子进行检验
char mine(std::vector<std::vector<char>> area,int x,int y,int n,int m)
{
    char mine = '0';
    for(int i = 0;i < 8;i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(inside(nx,ny,n,m) && area[nx][ny] == '*')
        {
            mine++;
        }
    }
    return mine;
}
int main()
{
    int n,m;
    std::cin >> n >> m;
    std::vector<std::vector<char>> area(n,std::vector<char>(m,0));//第二个参数是匿名临时对象
    //临时变量属于右值，特点是没有名字，生命周期只在这条语句
    //构造函数允许传入变量，临时变量，字面量，表达式结果
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            std::cin >> area[i][j];
        }
    }
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            if(area[i][j] != '*')
            {
                area[i][j] = mine(area,i,j,n,m);
            }
        }
    }
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            std::cout << area[i][j];
        }
        std::cout << "\n";
    }
}