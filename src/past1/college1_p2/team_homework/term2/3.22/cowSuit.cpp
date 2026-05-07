#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
// 函数是一段纯粹的行为，它接受输入，进行处理，然后返回输出。它本身并不具备记忆，放在栈上，执行完就释放了
// 类是一个蓝图或者容器，它不仅包含行为（成员函数）还包括状态（成员变量）。类是把数据和操作数据的方法打包在一起的抽象
struct myCompare // 最大根堆需要一个类，这个类满足有重载（）并且可以比较类型
// 如果最大根堆的前两个参数的类型和容器是int相关
{
    bool operator()(int a, int b)
    {
        return a < b;
    }
};

int main()
{
    int n, a, b; // 衣服数，自然干，炉子干
    std::cin >> n >> a >> b;
    // 每次减掉a，看谁最大就减掉b
    // 问题在于每次减去都要循环一次，这无法避免
    // 但每次找最大值然后减去b这个是可以省略的，我们可以最后再减去n个a
    // 使用大根堆
    std::priority_queue<int, std::vector<int>, myCompare> pq;
    for (int i = 0; i < n; i++)
    {
        int suit;
        std::cin >> suit;
        pq.push(suit);
    }
    int day = 0;
    while (pq.top() - day * a > 0)
    {
        int suit = pq.top() - b;
        pq.pop();
        pq.push(suit);
        day++;
    }
    std::cout << day;
}