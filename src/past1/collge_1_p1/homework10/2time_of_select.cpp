#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class Watch
{
    private :
    clock_t start_time;
    clock_t end_time;
    public :
    clock_t get_StartTime() const
    {
        return start_time;
    }
    clock_t get_EndTime() const
    {
        return end_time;
    }

    //初始化
    Watch()
    {
        start_time = clock();
    }
    void start()
    {
        start_time = clock();
    }
    void end()
    {
        end_time = clock();
    }

    double getElapseTime() const
    {
        return double(end_time - start_time) / CLOCKS_PER_SEC * 1000;
    }
};

void selectionsort(int arr[],int n)
{
    
    for(int i = 0;i < n - 1;i ++)//曾经i并没小于n - 1导致j越界
    {
        int min = arr[i];
        int minindex = i;
        for(int j = i + 1;j < n;j ++)
        {
            if(arr[j] < arr[minindex])//这里曾经用了min但min的值并没有变过会导致错误比较
            {
                minindex = j;
            }
        }
        if(minindex != i)
        {
            swap(arr[i],arr[minindex]);
        }
    }
}
int main()
{
    srand(time(0));
    int arr[10000];
    for(int i = 0;i < 10000;i++)
    {
        arr[i] = rand();
    }

    Watch watch;
    watch.start();
    selectionsort(arr,10000);
    watch.end();
    cout << watch.getElapseTime();
    return 0;
}