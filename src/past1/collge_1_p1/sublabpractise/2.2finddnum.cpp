#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    vector<int> digitnums;
    int num;
    cin >> num;
    while(true)
    {
        digitnums.push_back(num % 10);
        num /= 10;
        if(num < 10)
        {
            digitnums.push_back(num);
            break;
        }
    }
    int digits = digitnums.size();
    for(int i = 0;i <= digits - 1;i++)
    {
        cout << digitnums[i] << ", ";
    }
    return 0;
}