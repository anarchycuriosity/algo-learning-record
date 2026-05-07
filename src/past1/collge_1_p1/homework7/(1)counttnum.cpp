#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    map<int,int> times;
    int n = 0;
    while(true)
    {
        int num;
        cin >> num;
        vector<int> nums;
        nums.push_back(num);
        if((find(nums.begin(),nums.end(),0) != nums.end()) || nums.size() >=100)
        {
            break;
        }
        n = nums.size();
        for(int i = 0;i < n;i++)
        {
            times[nums[i]]++;
        }
    }
    for(int i = 0;i < 100; i++)
    {
        if(times[i] == 0)
        {
            continue;
        }
        else if(times[i] == 1)
        cout << i << " occurs " << times[i] << " time." << endl;
        else 
        cout << i << " occurs " << times[i] << " times." << endl;
    }
    return 0;
}