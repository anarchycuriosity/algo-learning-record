#include <iostream>

//这里有个坑就是不能在str_cpy函数里面写int length = sizeof(*src)
//因为传入的数组会自动退化为指针,然后这个退化的指针不能用sizeof找到长度
void str_cpy(char (*src),char (*tar),int lenth)
{
    while((*src) != '\0')
    {
        (*tar) = (*src);
        ++tar;
        ++src;
    }
    *tar = '\0';
}

int main()
{
    char src[]{"hello"};
    char tar[1];
    int length = sizeof(src);
    str_cpy(src,tar,length);
    for(int i = 0;i < length;i++)
    {
        std::cout << tar[i];
    }
}