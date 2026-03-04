#include <iostream>
#include <vector>
using namespace std;
const int SIZE = 4;
double sumColumn(vector<vector<int>> m,int columnSize,int columnIndex)
{
    double sum = 0;
    for(int i = 0;i < columnSize ;i++)
    {
        sum += m[i][columnIndex];
    }
    return sum;
}
int main()
{
    int rows = 3,cols = 4;
    vector<vector<int>> matrix(rows,vector<int>(cols));
    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < 4;j++)
        {
            cin >> matrix[i][j];
        }
    }
    for(int i =0;i < 4;i++)
    {
        cout << i << ":" <<sumColumn(matrix,3,i) << endl;
    }

    return 0;
}