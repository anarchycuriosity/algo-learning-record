#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    vector<int> odds;
    vector<int> es;
    queue<int> ids;
    for (int i = 0; i < n - 1; i++)
    {
        if (vec[i] % 2 != 0)
        {
            odds.push_back(vec[i]);
            ids.push(i);
        }
    }
    sort(odds.begin(), odds.end());
    // odds.reserve(odds.size());
    int last = 0;
    int ind = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (!ids.empty() && i == ids.front())
        {
            ids.pop();
            vec[i] = odds[ind++];
            last = vec[i];
        }
        if (i != 0)
        {
            if (vec[i] <= vec[i - 1]) // 失败了，没能非递减，要赢需要递增
            {
                cout << "tuanzi";
                return 0;
            }
        }
    }
    cout << "Longting";
}