#include <iostream>
using namespace std;
void min_max_element(int *arr,int n,int *minpos,int *maxpos)
{
    int min = arr[0],max = arr[0];
    //这里忘记加*
    *minpos = 0,*maxpos = 0;
    for(int i = 0;i < n;i++)
    {
        if(arr[i] > max || (arr[i] == max && i < *maxpos))
        {
            max = arr[i];
            *maxpos = i;
        }
        if(arr[i] < min || (arr[i] == min && i < *minpos))
        {
            min = arr[i];
            *minpos = i;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0;i < n;i ++)
    {
        cin >> arr[i];
    }
    int minpos,maxpos;
    min_max_element(arr,n,&minpos,&maxpos);
    cout << "min:" << minpos << endl;
    cout << "max:" << maxpos; 
    return 0;
}