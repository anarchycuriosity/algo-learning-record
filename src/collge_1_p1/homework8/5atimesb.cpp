#include <iostream>
using namespace std;
const int N = 3;
void multimatrix(const double a[][N],const double b[][N],double c[][N])
{
    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < N;j++)
        {
            c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j] +a[i][2] * b[2][j];
        }
    }
}
int main()
{
    double a[3][3],b[3][3],c[3][3];
    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < N;j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < N;j++)
        {
            cin >> b[i][j];
        }
    }
    multimatrix(a,b,c);
    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < 3;j++)
        {
            cout << " " << a[i][j] << " ";
        }

        if(i == 1)
        {
            cout <<"* ";
        }
        else
        {
            cout << "   ";
        }

        for(int j = 0;j < 3;j++)
        {
            cout << " " << b[i][j] << " ";
        }
        
        if(i == 1)
        {
            cout <<"= ";
        }
        else
        {
            cout << "   ";
        }

        for(int j = 0;j < 3;j++)
        {
            cout << " " << c[i][j] <<" ";
        }
        cout << endl;
    }
    return 0;
}