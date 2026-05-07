#include <iostream>

int main()
{
    int n;
    int up_num = 0,low_num = 0,num_num = 0;
    std::cin >> n;
    char * str;
    str = new char[n + 1];
    /*
    for(char &ch : std::string(str))
    {
        std::cin >> ch;
    }
    */
   for(int i = 0;i < n;i++)
   {
        //std::cin >> (*str);
        //糖了
        std::cin >> str[i];
   }
   *(str + n + 1) = '\0';

    //使用这种方式遍历，如果不手动加上休止符它不会自己停下来
    for(char &ch : std::string(str))
    {
        if(ch >= 'a' && ch <='z')
        {
            low_num++;
        }
        else if(ch >= 'A' && ch <= 'Z')
        {
            up_num++;
        }
        else if(ch >='0' && ch <= '9')
        {
            num_num++;
        }
    }
    std::cout << up_num << std::endl;
    std::cout << low_num << std::endl;
    std::cout << num_num << std::endl;
    delete[] str;
    return 0;
}