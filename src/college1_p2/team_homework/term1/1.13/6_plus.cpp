#include <bits/stdc++.h>
int main()
{
    int N;
    std::cin >> N;
    std::vector<int> l(N + 2), r(N + 2); // 左右指针
    r[0] = 1;                            // 哨兵，0 的右边是 1
    l[1] = 0;                            // 1 的左边是 0
    int aim, choice;
    for (int i = 2; i <= N; i++)
    {
        std::cin >> aim >> choice;
        if (choice == 0) // 插到 aim 左边
        {
            l[i] = l[aim];
            r[i] = aim;
            r[l[aim]] = i;
            l[aim] = i;
        }
        else // 插到 aim 右边
        {
            r[i] = r[aim];
            l[i] = aim;
            l[r[aim]] = i;
            r[aim] = i;
        }
    }
    int exe_time;
    std::cin >> exe_time;
    while (exe_time--)
    {
        int x;
        std::cin >> x;
        if (l[x] == -1 && r[x] == -1)
            continue; // 已经被删过，忽略
        r[l[x]] = r[x];
        l[r[x]] = l[x];
        l[x] = r[x] = -1; // 标记删除
    }
    for (int i = r[0]; i != 0; i = r[i])
    {
        std::cout << i << " ";
    }
}
