/*
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

void ftoa(double f,char s[])
{
    vector<int> nums;
    double f1 = f * pow(10,6);
    int digits = to_string(f1).size();
    for(int i = digits - 1;i >= 0; i--)
    {
        int num;
        num = (static_cast<int>(f1) % static_cast<int>(pow(10,i+1)) - static_cast<int>(f1) % static_cast<int>(pow(10,i)))/pow(10,i);
        if(num != 0)
        {
            nums.push_back(num);
        }
    }
    int point = 0;
    while(true)
    {
        f *= 10;
        if(f - static_cast<int>(f) == 0)
        {
            break;
        }
        point ++;
    }
    for(int i = 0;i < nums.size() - point - 1;i++)
    {
        cout << nums[i] << " ";
    }
    cout << ". ";
    for(int i = nums.size() - point - 1;i < nums.size();i++)
    {
        cout << nums[i] << " ";
    }
}
int main()
{
    double f;
    cin >> f;
    char s[100];
    ftoa(f,s);
}
*/

#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

void ftoa(double f, char s[]) {
    // 四舍五入到6位小数
    long long scaled = static_cast<long long>(round(f * 1e6));
    long long int_part = scaled / 1000000;
    long long frac_part = scaled % 1000000;

    // 构造整数部分
    string result = to_string(int_part) + ".";

    // 构造小数部分，补足6位
    char frac_buf[10];
    sprintf(frac_buf, "%06lld", frac_part);

    // 去掉末尾0
    int len = 6;
    while (len > 0 && frac_buf[len - 1] == '0') {
        len--;
    }
    result += string(frac_buf, len);

    // 拷贝到输出数组
    strcpy(s, result.c_str());
}

int main() {
    double num;
    char str[50];

    cin >> num;
    ftoa(num, str);

    for (int i = 0; str[i]; ++i) {
        cout << str[i];
        if (str[i + 1]) cout << " ";
    }
    cout << endl;
    return 0;
}
