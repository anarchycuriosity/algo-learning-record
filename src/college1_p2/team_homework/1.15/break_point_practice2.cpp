#include <iostream>

int calculate_factorial(int n)
{
    // 提示：观察调用堆栈 (Call Stack)
    if (n == 0)
    {
        return 1;
    }
    return n * calculate_factorial(n - 1);
}

int main()
{
    int target_num = -1;

    // 假设这个值是从用户输入拿到的，没做校验
    int result = calculate_factorial(target_num);

    std::cout << "Result: " << result << std::endl;

    return 0;
}