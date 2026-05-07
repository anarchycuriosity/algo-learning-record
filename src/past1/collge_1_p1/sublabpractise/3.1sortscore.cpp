#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int times;
    cin >> times;
    vector<int> scores;
    for(int time = 0; time < times;time ++)
    {
        int score;
        cin >> score;
        scores.push_back(score);
    }
    sort(scores.begin(),scores.end(),[](int a,int b)
        {return (a > b);}
        );
    
    for(int i = 0;i < times ;i++)
    {
        cout << scores[i] << " ";
    }
    return 0;
}
