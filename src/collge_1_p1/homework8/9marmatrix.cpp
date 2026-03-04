#include <iostream>
#include <algorithm>
using namespace std;
const int SIZE = 3;
bool is_marmatrix(const double m[][SIZE])
{
    for(int j = 0;j < SIZE;j++)
    {
        double sum = 0;
        for(int i = 0;i < SIZE;i++)
        {
            if(m[i][j] == 0)
            {
                return false;
            }
            sum += m[i][j];
        }
        /* //并非一列和为1就返回正确,而是全部
        if(sum == 1)
        {
            return true;
        }
        */
        if(sum != 1)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    double m[SIZE][SIZE];
    for(int i = 0;i < SIZE;i++)
    {
        for(int j = 0;j < SIZE;j++)
        {
            cin >> m[i][j];
        }
    }
    if(is_marmatrix(m))
    {
        cout << "It is a Markov matrix.";
    }
    else 
    {
        cout << "It is not a Markov matrix.";
    }
    return 0;
}