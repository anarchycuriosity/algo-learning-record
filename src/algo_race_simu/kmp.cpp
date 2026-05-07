#include <iostream>
using namespace std;
const int maxn = 1001;
char str[maxn];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> str[i];
    }
    char hfut[] = "hfut";
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (str[i] == hfut[0])
        {
            int cnt = 1;
            for (int j = 1; j <= 3; j++)
            {
                if (str[i + j] == hfut[j])
                {
                    cnt++;
                }
                else
                {
                    break;
                }
            }
            if (cnt == 4)
            {
                count++;
            }
        }
    }
    cout << count;
}