#include <iostream>

//sizeof包括'\0'但strlen不包括
void up_copy(char *upstr,char *oldstr)
{
    while(*oldstr != '\0')
    {
        if(*oldstr <= 'Z' && *oldstr >='A')
        {
            (*upstr) = (*oldstr);
            upstr++;
            oldstr++;
        }
        oldstr++;
    }
    (*upstr) = '\0';
}
int main()
{
    char old_str[]{"HelloWorld123"};
    char new_str[50];
    up_copy(new_str,old_str);
    std::cout << new_str;
}