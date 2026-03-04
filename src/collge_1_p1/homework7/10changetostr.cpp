#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void ftoa(double f, char a[]) {
    long long fp = static_cast<long long>(round(f * 1e6));
    long long intpart = fp / 1000000;
    long long fracpart = fp % 1000000;

    string intstr = to_string(intpart);
    string fracstr = to_string(fracpart);
    while (fracstr.size() < 6) {
        fracstr = "0" + fracstr;
    }
    //这里不应该用int做计时器,而是size_t,因为.size()返回的是size_t,这与int不同它没有负数
    int idx = 0;
    for (size_t i = 0; i < intstr.size(); i++) 
    {
        a[idx++] = intstr[i];
    }

    a[idx++] = '.';

    for (size_t i = 0; i < fracstr.size(); i++) 
    {
        a[idx++] = fracstr[i];
    }

    a[idx] = '\0'; 
}

int main() {
    double f;
    cin >> f;
    char a[100];
    ftoa(f, a);
    for(int i = 0;a[i] != 0;i++)
    {
        cout << a[i];
        if(a[i + 1] !='\0')
        {
            cout << ' ';
        }
    }
    return 0;
}
