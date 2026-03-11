#include <iomanip>
#include <iostream>
int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int num = n * i + j;
            if (num <= 9)
            {
                std::cout << 0 << num;
            }
            else
            {
                std::cout << num;
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    int num = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j <= n - i)
            {
                std::cout << std::left << std::setw(2) << " "; // 这里如果不输出点什么会乱码
            }
            else
            {
                if (num <= 9)
                {
                    std::cout << 0 << num++;
                }
                else
                {
                    std::cout << num++;
                }
            }
        }
        std::cout << std::endl;
    }
}