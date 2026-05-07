#include <vector>
#include <queue>
#include <iostream>
using namespace std;
bool isHorseDanger(int x,int y,int hx,int hy)
{
    int dx[] = {1,2,1,2,-1,-2,-1,-2};
    int dy[] = {2,1,-2,-1,2,1,-2,-1};
    for(int k = 0;k < 8;k++)
    {
        if(x == hx + dx[k] && y ==hx + dy[k])
        {
            return true;
        }
        else if(x == hx && y == hy)
        {
            return true;
        }
        return false;
    }
}

int main()
{
    int tx,ty,hx,hy;
    cin >> tx >> ty >> hx >> hy;
    vector<vector<long long>> dp(tx + 1,vector<long long>(ty + 1,0));
    dp[0][0] = 1;
    for(int i = 0;i <= tx;i++)
    {
        for(int j = 0;j <= ty;j++)
        {
            if(isHorseDanger(i,j,hx,hy))
            {
                dp[i][j] = 0;
                continue;//这里不能漏
            }
            if(i > 0)
            {
                dp[i][j] += dp[i - 1][j];
            }
            if(j > 0)
            {
                dp[i][j] += dp[i][j - 1];
            }
        }
    }
    cout << dp[tx][ty];
}
