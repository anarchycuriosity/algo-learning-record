// 其实很多数组填充类的问题
// 其做法都是先预先给数组扩容到填充后的大小，然后在从后向前进行操作。
// 而不是反复地进行扩容的操作，会浪费很多时间，只扩容一次
#include <vector>
#include <string>
#include <iostream>
int main()
{
    std::string s;
    while (std::cin >> s)
    {
        // 双指针，第一根指针去找数字的个数
        int count = 0;
        int old_ind = s.size() - 1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                count++;
            }
        }
        s.resize(s.size() + 5 * count); // 这里是5而不是6
        // 因为本身那里就站着一个字符了
        int new_ind = s.size() - 1;
        // 从后向前遍历，这样就不需要额外开空间
        while (old_ind >= 0)
        {
            if (s[old_ind] >= '0' && s[old_ind] <= '9')
            {
                s[new_ind--] = 'r';
                s[new_ind--] = 'e';
                s[new_ind--] = 'b';
                s[new_ind--] = 'm';
                s[new_ind--] = 'u';
                s[new_ind--] = 'n';
            }
            else
            {
                s[new_ind--] = s[old_ind];
            }
            old_ind--;
        }
        for (int i = 0; i < s.size(); i++)
        {
            std::cout << s[i];
        }
    }
}