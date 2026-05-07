#include <iostream>
using namespace std;
const int SIZE = 4;
double sumMD(const double m[][SIZE])
{
    int sum =0;
    for(int i =0;i < 4;i++)
    {
        sum += m[i][i];
    }
    return sum;
}
int main()
{
    double m[4][SIZE];
    for(int i=0;i < 4;i++)
    {
        for(int j = 0;j < 4;j++)
        {
            cin >> m[i][j];
        }
    }
    cout << "sum:" << sumMD(m);
}