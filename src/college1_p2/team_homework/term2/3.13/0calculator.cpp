#include <bits/stdc++.h>

// constexpr要求保证变量在编译阶段就能算出结果，而const可以是在运行时读取
constexpr int LEN = 1004;
int a[LEN], b[LEN], c[LEN];
void clear(int c[])
{
    for (int i = 0; i < LEN; i++)
    {
        c[i] = 0;
    }
}
// 逆序读入，顺序输出
void read(int a[])
{
    static char s[LEN + 1];
    scanf("%s", s); // scanf只能识别char，不认识int数组
    clear(a);
    int len = strlen(s); // strlen并不计算终止符
    for (int i = 0; i < len; i++)
    {
        a[len - i - 1] = s[i] - '0';
    }
}
void print(int a[])
{
    int i; // 这里并不涉及读入，所以其实可以只用一个i
    for (int i = LEN - 1; i >= 1; i--)
    {
    }
}

void add(int a[], int b[], int c[])
{
}