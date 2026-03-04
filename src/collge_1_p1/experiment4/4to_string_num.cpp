#include <iostream>
using namespace std;
int main()
{
    int num;
    cin >> num;
    string numstr = to_string(num);
    for(int i = 0;i < numstr.size();i++)
    {
        cout << numstr[i] << " ";
    }
    return 0;
}