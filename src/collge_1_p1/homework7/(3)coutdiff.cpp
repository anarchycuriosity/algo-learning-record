#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> nums;
    for(int i = 0;i < 10;i ++)
    {
        int num;
        cin >> num;
        if(find(nums.begin(),nums.end(),num) == nums.end())
        {
            nums.push_back(num);
        }
    }
    for(int i = 0;i < nums.size(); i ++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}