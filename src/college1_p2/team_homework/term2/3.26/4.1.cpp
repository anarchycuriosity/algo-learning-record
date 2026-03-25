#include <iostream>
int map[5001];
// 找老大的这个函数我是第一次见
// return+赋值来布置返回时候的任务
// 这个非常精简
/*
int get(int x){
    if(x==fa[x]) return x;
    return fa[x]=get(fa[x]);
}*/

int find_boss(int x) // 找到x的老大
{
    // 确认自己是不是最高老大
    if (map[x] == x)
    {
        return x;
    }

    int leader = find_boss(map[x]); // 层层去找老大

    // 此时leader已经找到了，在递归的最底层
    map[x] = leader;
    return leader;
}
void merge(int x, int y)
{
    map[find_boss(x)] = map[find_boss(y)];
}
int main()
{
    // 通过不断维护，让i索引的数据始终是它的老大
    int n, m, p;
    std::cin >> n >> m >> p;
    for (int i = 1; i <= n; i++)
    {
        map[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        std::cin >> x >> y;
        merge(x, y);
    }
    for (int i = 0; i < p; i++)
    {
        int x, y;
        std::cin >> x >> y;
        if (find_boss(x) == find_boss(y))
        {
            std::cout << "Yes" << std::endl;
        }
        else
        {
            std::cout << "No" << std::endl;
        }
    }
}