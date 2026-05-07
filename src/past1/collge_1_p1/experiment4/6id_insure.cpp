#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// 前 17 位的加权因子
static const int WEIGHTS[17] = {
    7, 9, 10, 5, 8, 4, 2,
    1, 6, 3, 7, 9, 10, 5, 8, 4, 2
};

// 校验码映射表：sum % 11 的结果对应
static const char CHECK_MAP[11] = {
    '1','0','X','9','8','7','6','5','4','3','2'
};


bool insure_code(string & idcodestr)
{
    int sum = 0;
    int idcode[17];
    char csurecode = idcodestr[17];
    for(int i = 0;i < 17;i++)
    {
        idcode[i] = idcodestr[i] - '0';
    }
    
    for(int i = 0;i < 17;i++)
    {
        sum += idcode[i] * WEIGHTS[i];
    }

    char rsurecode = CHECK_MAP[sum % 11];
    if(csurecode == rsurecode)
    {
        return true;
    }
    return false;
}

int main()
{
    string idcodestr;
    cin >> idcodestr;
    if(insure_code(idcodestr))
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
    return 0;
}