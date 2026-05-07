// 由于上一版开了太多了vector，所以MLE了
// 这题其实可以尝试用c语言的scanf扫描
// 这似乎区别于cin的流式扫描，处理字符串非常方便
#include <cstdio>
int var[3];
char s1, s2;
int main()
{
    while (scanf("%c:=%c;", &s1, &s2) == 2) // scanf返回成功匹配并且赋值的参数个数
    {
        var[s1 - 'a'] = s2 >= '0' && s2 <= '9' ? s2 - '0' : var[s2 - 'a'];
    }
    printf("%d %d %d", var[0], var[1], var[2]);
}