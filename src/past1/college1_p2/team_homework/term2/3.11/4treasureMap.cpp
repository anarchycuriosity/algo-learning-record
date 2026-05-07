#include <bits/stdc++.h>

int main()
{
    int N; // 表示小岛总数
    int M; // 表示序列的元素总数
    std::cin >> N >> M;
    std::vector<int> q;
    while (M--)
    {
        int island;
        std::cin >> island;
        q.push_back(island);
    }
    // 开大一点免除麻烦-1
    std::vector<std::vector<int>> map(N + 1, std::vector<int>(N + 1, 0));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            std::cin >> map[i][j];
        }
    }
    // 邻接矩阵，每移动到一个新的岛就看新的行
    // 弗洛伊德算法：把原矩阵中直达 的危险值更新为两点间最低的危险值
    // map[i][j]的i是出发点，j是终点，因为对角线
    // 第一层是中转点，三层循环有点像是向量加法
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (map[i][j] > map[i][k] + map[k][j])
                {
                    map[i][j] = map[i][k] + map[k][j];
                }
            }
        }
    }
    int count = 0;
    int now = 1;
    for (int i = 0; i < q.size(); i++)
    {
        count += map[now][q[i]];
        now = q[i];
    }
    std::cout << count;
}