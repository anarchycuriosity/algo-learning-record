#include <bits/stdc++.h>
using namespace std;
void print(tm &end)
{
    printf("%d-%02d-%02d %02d:%02d:%02d", end.tm_year + 1900, end.tm_mon + 1, end.tm_mday, end.tm_hour, end.tm_min, end.tm_sec);
}
// 不要重复造轮子了
// 顺便聊聊对tm*和tm的成员操作的区别
// 前者是对象指针，一个内存地址，需要使用->操作符
// 后者是对象实体，直接拥有这个结构体，我们使用.操作符
int main()
{
    tm st;
    st.tm_year = 2022 - 1900;
    st.tm_mon = 0; // 0才是1月
    st.tm_mday = 1;
    st.tm_hour = 8;
    st.tm_min = 0;
    st.tm_sec = 0;
    time_t t_st = mktime(&st);
    time_t pass;
    cin >> pass;
    t_st += pass;

    tm *end; // localtime必须对指针操作
    end = localtime(&t_st);
    print(*end);
}