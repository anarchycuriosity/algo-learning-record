#include <iostream>
int main()
{
    // 取消与 stdio 的同步
    std::ios::sync_with_stdio(false);
    // 解绑 cin 和 cout，避免每次 cin 都要强行刷新 cout 的缓冲区
    std::cin.tie(nullptr);
    int a;
    double b;
    scanf("%d %lf", &a, &b); // scanf不能指定精度
    // scanf必须使用lf，输出无所谓
    printf("%06d %8.2f", a, b);
}
