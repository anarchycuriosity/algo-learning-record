#include <iostream>
#include <vector>
#include <iomanip>
struct Person // 本题由于需要提取序列，而数组难以提取
{
    int ind; // 正常数数
    double T;
};
// 归并排序的两个函数都需要一个额外的数组
// 或负责中转再印回去，或者负责记录结果
// 我们需要把小的并且序号小的放前面
void merge(Person *queue, int left, int right)
{
    std::vector<Person> tmp;
    int mid = (left + right) / 2;
    // 双指针
    // 相信被分开的数组已经排序了
    int i = left;
    int j = mid + 1;
    while (i <= mid && j <= right)
    {
        if (queue[i].T <= queue[j].T)
        {
            tmp.push_back(queue[i]);
            i++;
        }
        else
        {
            tmp.push_back(queue[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        tmp.push_back(queue[i]);
        i++;
    }
    while (j <= right)
    {
        tmp.push_back(queue[j]);
        j++;
    }
    int k = 0;
    for (left; left <= right; left++)
    {
        queue[left] = tmp[k];
        k++;
    }
}
void mergeSort(Person *queue, int left, int right)
{
    int mid = (left + right) / 2;
    // 如果是左闭右开，就是left + 1 >= right返回
    if (left >= right)
    {
        return;
    }
    mergeSort(queue, left, mid);
    mergeSort(queue, mid + 1, right);
    merge(queue, left, right);
}
int main()
{
    int n;
    std::cin >> n;
    Person *queue = new Person[n + 1];
    for (int i = 1; i <= n; i++)
    {
        double T;
        std::cin >> T;
        queue[i].ind = i;
        queue[i].T = T;
    }
    mergeSort(queue, 1, n);
    double wait = queue[1].T;
    for (int i = 1; i <= n; i++)
    {
        std::cout << queue[i].ind << " ";
        double rest = 0;
        if (i != 1)
        {
            rest = queue[i].T - wait;
        }
        wait += rest;
    }
    std::cout << std::endl;
    /*
        for (int i = 1; i <= n; i++)
    {
        std::cout << std::fixed << std::setprecision(2) << queue[i].T << " ";
    }
    delete queue;
    */
    std::cout << std::fixed << std::setprecision(2) << wait / n;
}