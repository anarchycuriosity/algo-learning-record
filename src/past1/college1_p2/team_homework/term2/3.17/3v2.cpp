#include <iostream>
#include <map> //使用map会导致空间超标，不应该存起来而是及时使用
// 使用位运算
// 异或运算满足交换律和结合律,理解为不进位的二进制运算
// a异或a是0，a异或0是a
int main()
{
    int n;
    scanf("%d", &n);
    int target = 0;
    int tmpChop;
    for (int i = 0; i < n; i++)
    {
        // scanf("%d", chops[i]);数组退化为首指针，只在前面加个&也可
        scanf("%d", &tmpChop);
        target ^= tmpChop; // 如果出现了相同的tmpchop会抵消
        // 3 ^ 5 ^ 3 == 3 ^ 3 ^ 5
    }
    printf("%d", target);
}