#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
int n;
using namespace std;
bool dfs(int ind, vector<int> &vec)
{
    if (ind == n - 1)
    {
        for (int i = 1; i < n; i++)
        {
            if (vec[i] < vec[i - 1])
            {
                return false;
            }
        }
        return true;
    }

    vector<int> vec1 = vec;
    dfs(ind + 1, vec1);
    if ((vec[ind] + vec[ind + 1]) % 2 != 0)
    {
        int tmp = vec[ind];
        vec[ind] = vec[ind + 1];
        vec[ind + 1] = tmp;
        dfs(ind + 1, vec);
    }
}
int main()
{

    cin >> n;
    vector<int> vec(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    if (dfs(0, vec))
    {
        cout << "Longting";
    }
    else
    {
        cout << "tuanzi";
    }
}
