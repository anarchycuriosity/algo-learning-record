#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binary_idx(vector<int> &vec,int left,int right,int target)
{
    //left = 0,right = vec.size();
    if(left > right)//这个一定要写在前面,并且是单独的if,否则让mid先执行就会导致无限递归
    {
        return -1;
    }
    int mid = (left + right) >> 1;
    if(vec[mid] == target)
    {
        return mid;
    }
    else if(vec[mid] > target)
    {
        return binary_idx(vec,left,mid - 1,target);
    }
    else if(vec[mid] < target)
    {
        return binary_idx(vec,mid + 1,right,target);
    }
    

    return -1;
}

int main()
{
    vector<int> vec;
    for(int i = 0;i < 10;i++)
    {
        int num;
        cin >> num;
        vec.push_back(num);
    }

    sort(vec.begin(),vec.end());
    
    int left = 0,right = vec.size() - 1;
    int target;
    cin >> target;
    int bin = binary_idx(vec,left,right,target);
    if(bin >= 0)
    {
        cout << target << "exists";
    }
    else 
    {
        cout << target << "doesn't exist";
    }
    return 0;
}