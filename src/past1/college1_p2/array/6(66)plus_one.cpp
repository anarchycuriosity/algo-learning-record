#include <iostream>
#include <vector>
#include <cmath>
class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) 
    {

        int right = digits.size() - 1;
        digits[right]++;
        //if(digits[right]++ == 10)这会导致额外的自增，在判断的时候
        if(digits[right] == 10)
        {
            for(int i = right;i > 0;i --)
            {
                if(digits[i] == 10)
                {
                    digits[i] = 0;
                    digits[i - 1]++;
                }
            }
        }
        if(digits[0] == 10)
        {
            digits.emplace_back(0);
            for(int i = right + 1;i > 1;i--)
            {
                digits[i] = digits[i - 1];
            }
            digits[1] = 0;
            digits[0] = 1;
        }
        return digits;
        //这样移动元素有些麻烦了，不妨考虑insert
        //digits.insert(digits.begin(),1);
        /*
        int max_digit  = digits.size() - 1;
        int real_num = 0;
        for(int i = 0;i < digits.size();i++)
        {
            int complete = max_digit - i;
            //oh,std::pow返回的是double
            //使用cmath的时候要注意了
            //啊，但是大小溢出了，这题本质是要模拟数组加法
            real_num += digits[i] * static_cast<int>(std::pow(10,complete));
        }
        real_num++;
        std::vector<int> new_digits;
        while(real_num > 0)
        {
            int digit;
            digit = real_num % 10;
            real_num = (real_num - digit) / 10;
            new_digits.push_back(digit);
        }
        for(int i = 0;i < new_digits.size() / 2;i++)
        {
            //应该是交换啊啊你个蠢蛋
            //new_digits[i] = new_digits[new_digits.size() - 1 - i];
            std::swap(new_digits[i],new_digits[new_digits.size() - 1 - i]);
        }
        return new_digits;
        */
    }
    
};