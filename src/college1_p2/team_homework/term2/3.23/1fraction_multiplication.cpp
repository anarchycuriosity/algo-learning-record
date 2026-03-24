#include <iostream>
int gcd(int a, int b)
{
    while (b != 0)
    {
        int remain = a % b;
        a = b;
        b = remain;
    }
    return a;
}
int main()
{
    int up1, up2;
    int down1, down2;
    scanf("%d/%d", &up1, &down1);
    scanf("%d/%d", &up2, &down2);
    int up = up1 * up2;
    int down = down1 * down2;
    int num = gcd(up, down);
    up /= num;
    down /= num;
    std::cout << down << " " << up;
}