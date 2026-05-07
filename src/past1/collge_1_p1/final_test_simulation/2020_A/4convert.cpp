#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
class Integer
{
    private:
        int num_ten;
        std::string digits = "0123456789ABCDEF";
    public:
        Integer(int Num_ten) : num_ten(Num_ten){}
        int get_num_ten()
        {
            return num_ten;
        }
        std::string get_digits()
        {
            return digits;
        }
        virtual void print() {}
};

class Eight : public Integer
{
    private:
        std::string num_convert;
    public:
        Eight(int Num_ten) : Integer(Num_ten)
        {
            int num_ten_cp = get_num_ten();
            int digit = 0;
            while(num_ten_cp > 0)
            {
                //num_eight += num_ten_cp % 8 * std::pow(10,digit);
                //num_eight += num_ten_cp % static_cast<int>(std::pow(8,digit + 1));
                //num_ten_cp -= num_ten_cp % static_cast<int>(std::pow(8,digit + 1));
                //digit++;
                int base = 8;
                int index = num_ten_cp % base;
                num_ten_cp /= base;
                //这样插入不对，会反过来,明明最低位最早产生，却被顶到字符串的前面
                //num_convert += get_digits()[index];
                num_convert = get_digits()[index] + num_convert;
            }  
        }
        void print()
        {
            std::cout << num_convert << "\n";
        }
};
class Sixteen : public Integer
{
    private:
        std::string num_convert;
    public:
        Sixteen(int Num_ten) : Integer(Num_ten)
        {
            int num_ten_cp = get_num_ten();
            int digit = 0;
            while(num_ten_cp > 0)
            {
                //num_eight += num_ten_cp % 8 * std::pow(10,digit);
                //num_eight += num_ten_cp % static_cast<int>(std::pow(8,digit + 1));
                //num_ten_cp -= num_ten_cp % static_cast<int>(std::pow(8,digit + 1));
                //digit++;
                int base = 16;
                int index = num_ten_cp % base;
                num_ten_cp /= base;
                //这样插入不对，会反过来,明明最低位最早产生，却被顶到字符串的前面
                //num_convert += get_digits()[index];
                num_convert = get_digits()[index] + num_convert;
            }  
        }
        void print()
        {
            std::cout << num_convert << "\n";
        }
};
class Two : public Integer
{
    private:
        std::string num_convert;
    public:
        Two(int Num_ten) : Integer(Num_ten)
        {
            int num_ten_cp = get_num_ten();
            int digit = 0;
            while(num_ten_cp > 0)
            {
                //num_eight += num_ten_cp % 8 * std::pow(10,digit);
                //num_eight += num_ten_cp % static_cast<int>(std::pow(8,digit + 1));
                //num_ten_cp -= num_ten_cp % static_cast<int>(std::pow(8,digit + 1));
                //digit++;
                int base = 2;
                int index = num_ten_cp % base;
                num_ten_cp /= base;
                //这样插入不对，会反过来,明明最低位最早产生，却被顶到字符串的前面
                //num_convert += get_digits()[index];
                num_convert = get_digits()[index] + num_convert;
            }  
        }
        void print()
        {
            std::cout << num_convert << "\n";
        }
};
int main()
{
    int num;
    std::cin >> num;
    Eight eight(num);
    eight.print();
    Sixteen sixteen(num);
    sixteen.print();
    Two two(num);
    two.print();
}
