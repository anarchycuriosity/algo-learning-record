#include <algorithm>
#include <iostream>
#include <vector>
int main()
{
    std::vector<int> nums = {1,2,3,4,5,6,7,8,9};
    bool found = false;
    int a,b,c;
    std::cin >> a >> b >> c;
    do
    {
        int x,y,z;
        x = nums[0] * 100 + nums[1] * 10 + nums[2];
        y = nums[3] * 100 + nums[4] * 10 + nums[5];
        z = nums[6] * 100 + nums[7] * 10 + nums[8];
        if(x * b == y * a && x * c == z * a)
        {
            found = true;
            std::cout << x << " " << y << " " << z << "\n";
        }
    }
    while(std::next_permutation(nums.begin(),nums.end()));

    if(found == false)
    {
        std::cout << "No!!!\n";
    }
    return 0;
}