#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        for (int i = 0; i < s.size() / 2; i++)
        {
            std::swap(s[i], s[s.size() - 1 - i]);
        }
        for (int i = 0; i < s.size(); i++)
        {
            std::cout << s[i];
        }
    }
};