#include <iostream>
using namespace std;
int main()
{
    int m,n,k;
    cin >> m;
    int *nums_1 = new int[m];
    for(int i = 0;i < m;i++)
    {
        cin >> nums_1[i];
    }

    cin >> n;
    int *nums_2 = new int[n];
    for(int i = 0;i < n;i++)
    {
        cin >> *(nums_2 + i);
    }

    k = m + n;
    int *nums_3 = new int[k];
    for(int i = 0,m1 = 0,n1 = 0;i < k;i++)
    {
        if(i < m)
        {
            nums_3[i] = nums_1[m1++];
        }
        else if(i >= m && i < k)
        {
            nums_3[i] = nums_2[n1++];
        }
    }
    delete[] nums_1;
    delete[] nums_2;
    for(int i = 0;i < k;i++)
    {
        cout << nums_3[i] <<" ";
    }
    delete[] nums_3;
    return 0;
}