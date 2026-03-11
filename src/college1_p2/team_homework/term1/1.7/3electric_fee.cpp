#include <bits/stdc++.h>
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int amo;
    std::cin >> amo;
    double fee = 0;
    if(amo <=150)
    {
        fee = 0.4463 * amo;
    }
    else if(amo >=151 && amo <= 400)
    {
        fee = 0.4463 * 150 + (amo - 150) * 0.4663;
    }
    else if(amo >= 401)
    {
        fee = 0.4463 * 150 + 249 * 0.4663 + (amo - 400) * 0.5663;
    }
    std::cout << std::fixed << std::setprecision(1) << fee;
    //采用下面的方法来避免浮点数误差
    /*
#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int amo;
    std::cin >> amo;

    // 单价 × 10000 变整数
    const int p1 = 4463;
    const int p2 = 4663;
    const int p3 = 5663;

    long long fee = 0;

    if (amo <= 150) {
        fee = amo * p1;
    } else if (amo <= 400) {
        fee = 150 * p1 + (amo - 150) * p2;
    } else {
        fee = 150 * p1 + 250 * p2 + (amo - 400) * p3;
    }

    // fee 是 ×10000 的值，转回元
    std::cout << std::fixed << std::setprecision(1) << fee / 10000.0;
}

    */
    
}