#include <iostream>

void up_copy(char *upstr,char *oldstr)
{
    
}
int main()
{
    char old_str[]{"HelloWorld123"};
    char new_str[50];
    up_copy(new_str,old_str);
    std::cout << new_str;
}