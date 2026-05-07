#include <vector>
#include <iostream>
#include <string>
namespace curio
{
    void reverse(std::string &s, int begin, int end) // end不是迭代器
    {

        while (begin < end)
        {
            std::swap(s[begin++], s[end--]);
        }
    }

}
int main()
{
    int k;
    std::string s;
    std::cin >> k >> s;
    curio::reverse(s, 0, s.size() - 1);
    curio::reverse(s, 0, k - 1);
    curio::reverse(s, k, s.size() - 1);
    for (int i = 0; i < s.size(); i++)
    {
        std::cout << s[i];
    }
}