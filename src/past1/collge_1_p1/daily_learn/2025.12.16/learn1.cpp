#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int array[5]{1,2,3,4,5};
    int (*p)[5]{&array};
    for(int i = 0;i < 5;i++)
    {
        cout << (*p)[i] << endl;
    }

    int n;
    cout << "输入n和n个数\n";
    cin >> n;
    int *array2 = new int[n];
    for(int i = 0;i < n;i ++)
    {
        cin >> *(array2 + i);
    }
    for(int i = 0;i < n;i++)
    {
        cout << array2[i] << endl;
    }
    int num[10];
    vector<int> vec1;

    //static_cast<>()与函数调用的()有所不同,前者是关键字\显式类型转换运算符 (cast operator)
    
    //数组本质并不是指针,而是一个存放着多个元素的内存.数组退化为指针指的是它退化为指向它第一个元素的指针而不是退化为指向这块内存的指针
}