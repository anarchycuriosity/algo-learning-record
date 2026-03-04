#include <iostream>
#include <cmath>
#include <string>
#include <string.h>

bool is_muti_plus(int num)
{
    int sum_each_digit_num = 0;
    int space_each_digit_num = 1;
    std::string num_str = std::to_string(num);
    //注意size和sizeof的区别
    int digits = num_str.size();
    //写循环的时候验算一下次数对不对
    for(int i = 0;i < digits;i++)
    {
        int each_digit_num = num % 10;
        sum_each_digit_num += each_digit_num;
        space_each_digit_num *= each_digit_num;
        //这里不要忘记除以10
        num = (num - num % 10)/10;
    }
    if(sum_each_digit_num < space_each_digit_num)
    {
        return true;
    }
    return false;
}

int main()
{
    for(int i = 10;i <= 100;i ++)
    {
        if(is_muti_plus(i))
        {
            std::cout << i << " ";
        }
    }
}