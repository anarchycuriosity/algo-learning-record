#include <iostream>
#include <vector>
int main()
{
    int n;
    std::cin >> n;
    std::vector<int> prize(7, 0);
    for (int i = 0; i < 7; i++)
    {
        std::cin >> prize[i];
    }
    std::vector<int> counts(8, 0);
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < 7; j++)
        {
            int num;
            std::cin >> num;
            for (int k = 0; k < 7; k++)
            {
                if (num == prize[k])
                {
                    count++;
                }
            }
        }
        counts[count]++;
    }
    for (int k = 7; k >= 1; k--)
    {
        std::cout << counts[k] << " ";
    }
}