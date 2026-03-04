#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    char (*str){new char[n + 1]};//这里要多给一个位置来存'\0'
    for(int i = 0;i < n;i ++)
    {
        char strP;
        cin >> strP;
        str[i] = strP;
    }
    //越界访问了
    //str[n + 1] = '\0';
    str[n] = '\0';

    int num_up = 0,num_low = 0,num_num = 0,num_other = 0;
    //一开始缺失了把指针存入原始指针这一步直接操作了
    char (*original_str){str};
    while(*str != '\0')
    {
        if( *str <= 'Z' && *str >= 'A')
        {
            num_up ++;
        }
        else if( *str <= 'z' && *str >= 'a')
        {
            num_low ++;
        }
        else if( *str >= '0' && *str <= '9')
        {
            num_num ++;
        }
        else
        {
            num_other ++;
        }
        str ++;
    }
    cout << num_up << endl;
    cout << num_low << endl;
    cout << num_num << endl;
    cout << num_other << endl;
    delete[] original_str;

}
