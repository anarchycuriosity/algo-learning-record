#include <iostream>
#include <vector>
using namespace std;
void bublesort(vector<int> & vec)
{
    int n = vec.size();
    for(int i = 0;i < n - 1;i++)
    {
        for(int j = 0;j < n - 1 - i;j ++)
        {
            if(vec[j] > vec[j + 1])
            {
                swap(vec[j],vec[j + 1]);
            }
        }
    }
}
//下面的错误是,交换了值但是没有交换索引,如果最小值在末尾,这个最小值会一直被复制到i位
/*
void chosensort(vector<int> &vec)
{
    int n = vec.size();
    for(int i = 0;i < n - 1;i++)
    {
        int mini = vec[i];
        for(int j = i;j < n - 1;j++)
        {
            if(mini > vec[j])
            {
                mini = vec[j];
            }
        }
        vec[i] = mini;
    }
}
*/
void chosensort(vector<int> &vec)
{
    int n = vec.size();
    for(int i = 0;i < n - 1;i++)
    {
        int minindex = i;
        for(int j = i;j < n ;j++)//这里应该是n而非n - 1
        {
            if(vec[minindex] > vec[j])
            {
                minindex = j;
            }
        }
        swap(vec[minindex],vec[i]);
    }
}

//计算合并的时候最好传入参数mid,而在拆分递归的时候也许不太需要
void merge(vector<int> &vec,int left,int mid,int right)
{
    vector<int> temp;
    //int i = left,j = mid ;
    int i = left,j = mid + 1;
    while(i <= mid && j <= right)
    {
        if(vec[i] < vec[j])
        {
            temp.push_back(vec[i++]);
        }
        else
        {
            temp.push_back(vec[j++]);
        }
    }
    while(i <= mid)
    {
        temp.push_back(vec[i++]);
    }
    while(j <= right)
    {
        temp.push_back(vec[j++]);
    }
    /*//尺度不对,这会覆盖过多
    for(int k = 0;k < vec.size();k++)
    {
        vec[k] = temp[k];
    }
    */
   for(int k = 0;k < temp.size();k++)
    {
        vec[left + k] = temp[k];
    }
}
void mergesort(vector<int> &vec,int left,int right)
{
    if(left >= right) return;//return表示倒车结束,递归直到return才开始从最小单元向前合并
    int mid = left + (right - left)/2;//最安全的写法,不会溢出,防止数太大
    mergesort(vec,left,mid);
    mergesort(vec,mid + 1,right);
    merge(vec,left,mid,right);
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums1,nums2,nums3;
    for(int i = 0;i < n;i ++)
    {
        int num;
        cin >> num;
        nums1.push_back(num);
        nums2.push_back(num);
        nums3.push_back(num);
    }

    cout << "冒泡排序结果" << endl;
    bublesort(nums1);
    for(int i = 0;i < n;i++)
    {
        cout << nums1[i] << " ";
    }
    cout << endl;

    cout << "选择排序结果" << endl;
    chosensort(nums2);
    for(int i = 0;i < n;i++)
    {
        cout << nums2[i] << " ";
    }
    cout << endl;

    cout << "归并排序结果" << endl;
    mergesort(nums3,0,nums3.size() - 1);
    for(int i = 0;i < n;i++)
    {
        cout << nums3[i] << " ";
    }
    cout << endl;

}


