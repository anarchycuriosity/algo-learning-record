#include <bits/stdc++.h>
//其实约瑟夫的循环圈就是%
struct Human {
    int id;
};

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<Human> humans;
    for (int i = 0; i < n; i++) {
        humans.push_back({i + 1});
    }

    int idx = 0; // 当前报数位置
    while (!humans.empty()) {
        idx = (idx + m - 1) % humans.size(); // 报数到第 m 个
        std::cout << humans[idx].id << " ";
        humans.erase(humans.begin() + idx); // 删除该人
    }
    return 0;
}
