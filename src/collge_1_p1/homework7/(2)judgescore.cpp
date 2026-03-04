#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    int below = 0,equal = 0,over = 0,sum =0;
    int n = 0;
    vector<int> nums;
    while(true)
    {
        int num;
        cin >> num;
         if(num == -1)
        {
            break;
        }
        nums.push_back(num);
       
        sum +=num;
    }
    n = nums.size(); 
    double ave = static_cast<double>(sum) / n;
    for(int i = 0;i < n; i++)
    {
        if(nums[i] < ave)
        {
            below +=1;
        }
        else if(nums[i] > ave)
        {
            over +=1;
        }
        
        if(nums[i] == ave)
        {
            equal += 1;
        }
    }
    cout << "平均分" << static_cast<int>(ave + 0.5) << endl;
    cout << "高于平均分" << over << endl;
    cout << "等于平均分" << equal << endl;
    cout << "低于平均分" << below;

    return 0;
}