#include <iostream>
#include <vector>
int main()
{
    int n;
    std::cin >> n;
    int pre_num = 0;
    std::cin >> pre_num;
    n--;
    int num = 0;
    int count = 1;
    int max = 1;
    while (n--)
    {
        std::cin >> num;
        if (num == pre_num + 1)
        {
            count++;
            max = (count > max) ? count : max;
        }
        else
        {
            count = 1;
        }
        pre_num = num;
    }
    std::cout << max;
}