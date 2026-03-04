#include <iostream>
using namespace std;
int main()
{
    const int SIZE = 4;
    int matrix[4][4];
    for(int i = 0;i < 4;i++)
    {
        for(int j = 0;j < 4;j ++)
        {
            cin >> matrix[i][j];
        }
    }
    //水平
    for(int i = 0;i < 4;i++)
    {
        int count = 0;
        if(matrix[i][0] == 1 && matrix[i][1] == 1 && matrix[i][2] == 1 && matrix[i][3] == 1 )
        {
            cout << "All 1's on row " << i << endl;
            count ++;
        }
        else if(matrix[i][0] == 0 && matrix[i][1] == 0 && matrix[i][2] == 0 && matrix[i][3] == 0 )
        {
            cout << "All 0's on row " << i << endl;;
            count ++;
        }
        if(i == 3  && count == 0)
        {
            cout << "No same numbers on the same row" << endl;
        }
    }

    //column
    for(int j = 0;j < 4;j++)
    {
        int count = 0;
        if(matrix[0][j] == 1 && matrix[1][j] == 1 && matrix[2][j] == 1 && matrix[3][j] == 1)
        {
            cout << "All 1's on column " << j << endl;
            count ++;
        }
        else if(matrix[0][j] == 0 && matrix[1][j] == 0 && matrix[2][j] == 0 && matrix[3][j] == 0)
        {
            cout << "All 0's on column " << j << endl;
            count ++;
        }
        if(j == 3 && count == 0)
        {
            cout << "No same numbers on the same column" << endl;
        }
    }
    
    

    if(matrix[0][0] == 1 && matrix[1][1] == 1 && matrix[2][2] == 1 && matrix[3][3] == 1)
    {
        cout << "All 1's on major diagonal" << endl;
    }
    else if(matrix[0][0] == 0 && matrix[1][1] == 0 && matrix[2][2] == 0 && matrix[3][3] == 0)
    {
        cout << "All 0's on major diagonal" << endl;
    }
    else
    {
        cout << "No same numbers on major diagonal" << endl;
    }

    //sub_diagonal
    if(matrix[1][0] == 1 && matrix[2][1] == 1 && matrix[3][2] == 1)
    {
        cout << "All 1's on subdiagonal" << endl;
    }
    else if(matrix[1][0] == 0 && matrix[2][1] == 0 && matrix[3][2] == 0)
    {
        cout << "All 0's on subdiagonal" << endl;
    }
    else
    {
        cout << "No same numbers on sub-diagonal" << endl;
    }
    return 0;
}
