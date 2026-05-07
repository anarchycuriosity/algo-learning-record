#include <iostream>
using namespace std;
//传引用
void swap(int& p, int& q)
{
int temp = p;
p = q;
q = temp;
}
int main()
{
int x = 2, y = 3;
cout << "before: x=" << x << ", y=" << y << endl;
swap(x, y);
cout << "after: x=" << x << ", y=" << y << endl;
return 0;
}

//传地址(传指针)
void swap(int *p, int *q)
{
int temp = *p;
*p = *q;
*q = temp;
}
int main()
{
int x = 2, y = 3;
cout << "before: x=" << x << ", y=" << y << endl;
swap(&x, &y);
cout << "after: x=" << x << ", y=" << y << endl;
return 0;
} 
