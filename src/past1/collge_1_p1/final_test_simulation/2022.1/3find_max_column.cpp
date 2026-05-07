#include <iostream>
#include <map>
//void find_max(int Arr[4][5]) 需要注意数组传入的时候会退化为初位的指针
//void find_max(int *Arr) 这也不对，因为这只有一维数组
void find_max(int Arr[4][5])
{
    std::map<int,int> sum_each_col;
    for(int key = 0;key < 5;key++)
    {
        sum_each_col[key] = 0;
    }
    //这是比较标准的插入方式（大概）。键是不需要初始化的，插入即可。
    //sum_each_col.insert({5,1});
    for(int j = 0;j < 5;j++)
    {
        for(int i = 0;i < 4;i++)
        {
            sum_each_col[j] += Arr[i][j];
        }
    }
    int max_sum = sum_each_col[0];
    int max_index = 0;
    for(std::map<int,int>::iterator it = sum_each_col.begin();it != sum_each_col.end();it++)
    {
        if(max_sum < it->second)
        {
            max_index = it->first;
            max_sum = it->second;
        }
    }
    std::cout << max_sum << std::endl;
    for(int i = 0;i < 4;i++)
    {
        std::cout << Arr[i][max_index] << " ";
    }
}

int main()
{
    int arr[4][5];
    for(int i = 0;i < 4;i++)
    {
        for(int j = 0;j < 5;j++)
        {
            std::cin >> arr[i][j];
        }
    }
    find_max(arr);
    return 0;
}