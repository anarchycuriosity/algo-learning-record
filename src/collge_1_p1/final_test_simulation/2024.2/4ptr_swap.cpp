#include <iostream>

int main()
{
    int *arr{new int [10]};
    for(int i = 0;i < 10;i++)
    {
        std::cin >> arr[i];
    }

    int small{arr[0]};
    int s_index = 0;
    int big{arr[9]};
    int b_index = 9;
    //for(int arr_num : arr)
    //动态分配的数组不能这样遍历，但是静态数组可以
    for(int i = 0;i < 10;i++)
    {
        if(small > arr[i])
        {
            small = arr[i];
            s_index = i;
        }

        //这样换可能会导致由于交换缺失遍历
        /*
        if(big < arr[i])
        {
            std::swap(arr[9],arr[i]);
        }
        */
       //而且，如果是最大在第一个最小在最后一个的话，就更容易混乱
       //先修改big/small，再swap

       if(big < arr[i])
        {
            big = arr[i];
            b_index = i;
        }
    }

    //最愚蠢的一步，也是0大9小的情况，swap两次会相当于根本没有更换，输出从9到0
    /*
    std::swap(arr[s_index],arr[0]);
    std::swap(arr[b_index],arr[9]);
    */
    //由于这里需要用到两次swap，所以两次swap的中间步骤需要有一些调整，时空发生了变化，不是最初那个索引了
   
        std::swap(arr[s_index],arr[0]);
        if(b_index == 0)
        {
            b_index = s_index;
        }
        std::swap(arr[b_index],arr[9]);


    for(int i = 0;i < 10;i++)
    {
        std::cout << *(arr + i) << " ";
    }

    delete[] arr;
}