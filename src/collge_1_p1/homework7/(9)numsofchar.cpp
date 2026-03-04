#include <iostream>
using namespace std;
int main()
{
    char str[79];
    cin.getline(str,79);
    int count = 0;
    for(int i = 0;str[i] != '\0';i++)
    {
        if((str[i] <= 'z' && str[i] >= 'a') || (str[i] <= 'Z' && str[i] >= 'A'))
        {
            count++;
        }
    }
    cout << count;
}