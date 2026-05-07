#include <iostream>
using namespace std;
bool isprime(int num)
{
    for(int fac = 2;fac < num; fac++)
    {
        if(num % fac == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int num = 1;
    while(num <= 100)
    {
        if(isprime(num))
        {
            cout << num << endl;
        }
        num++;
    }
    return 0;
    
}