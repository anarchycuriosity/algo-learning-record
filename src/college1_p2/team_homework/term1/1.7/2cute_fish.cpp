#include <bits/stdc++.h>
struct Fish
{
    int cute;
    int cuter = 0; 
};
int main()
{
    int n;
    std::cin >> n;
    std::vector<Fish> fishes(n);
    for(int i = 0;i < n;i++)
    {
        int cute;
        std::cin >> cute;
        fishes[i].cute = cute;
    }
    for(int i = 1;i < n;i++)
    {
        for(int j = 0;j < i;j++)
        {
            if(fishes[i].cute > fishes[j].cute)
            {
                fishes[i].cuter++;
            }
        }
    }
    for(int i = 0;i < n;i++)
    {
        std::cout << fishes[i].cuter << " ";
    }
    return 0;
}