#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;

bool dfs(int ind, vector<int> &vec)
{
    if (ind == n - 1)
    {
        for (int i = 1; i < n; i++)
        {
            if (vec[i] < vec[i - 1])
                return false;
        }
        return true;
    }

    // 尝试不交换
    if (dfs(ind + 1, vec))
        return true;

    // 尝试交换
    if ((vec[ind] + vec[ind + 1]) % 2 != 0)
    {
        swap(vec[ind], vec[ind + 1]);
        if (dfs(ind + 1, vec))
            return true;

        swap(vec[ind], vec[ind + 1]);
    }
    return false;
}

int main()
{
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    if (dfs(0, vec))
        cout << "Longting";
    else
        cout << "tuanzi";

    return 0;
}