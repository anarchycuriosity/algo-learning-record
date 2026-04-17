// 计算从北京时间 2022 - 01 - 01 08 : 00 : 00 起，经过给定的秒数后的具体时间
// 采用c风格的输入会更好吧
// 然后就是月份和日的0，输出的时候处理即可
#include <bits/stdc++.h>
using namespace std;
int y = 2022;
int mon = 1;
int d = 1;
int h = 8;
int mi = 0;
int s = 0;
int divi = 1;
void print()
{
    cout << y << "-";
    if (mon < 10)
    {
        cout << 0 << mon << "-";
    }
    else
    {
        cout << mon << "-";
    }
    if (d < 10)
    {
        cout << 0 << d;
    }
    else
    {
        cout << d;
    }

    cout << " ";
    if (h < 10)
    {
        cout << 0 << h << ":";
    }
    else
    {
        cout << h << ":";
    }

    if (mi < 10)
    {
        cout << 0 << mi << ":";
    }
    else
    {
        cout << mi << ":";
    }

    if (s < 10)
    {
        cout << 0 << s;
    }
    else
    {
        cout << s;
    }
}

int main()
{
    int t;
    std::cin >> t;

    // 秒的上限是60s
    divi *= 60;
    s += (t % divi);
    t -= t % divi;

    divi *= 60;
    mi += (t % divi) / 60;
    t -= (t % divi);

    divi *= 60;
    h += (t % divi / 60);
    t -= t % divi;

    int odivi = divi;

    print();
}