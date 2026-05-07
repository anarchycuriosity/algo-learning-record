#include <iostream>
using namespace std;
void doubleval(int &num)
{
    num *= 2;
}
int main()
{
    int n;
    cin >> n;
    int *arr =new int[n]; 
    for(int i =0;i < n ;i++)
    {
        int num;
        cin >> num;
        *(arr + i) = num;
    }
    int max = *(arr + 0);
    int location = 0;
    for(int i = 1;i < n ;i++)
    {
        if(max < *(arr + i))
        {
            max = *(arr + i);
            location = i;
        }
        else
        {
            location = i - 1;
            break;
        }
    }
    doubleval(*(arr + location));
    for(int i = 0;i < n;i ++)
    {
        cout << *(arr + i) << " ";
    }
    delete[] arr;
    return 0;
}