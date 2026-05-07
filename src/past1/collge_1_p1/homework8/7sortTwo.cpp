/*
#include <iostream>
#include <algorithm>
using namespace std;
void to_sort(int m[][2],int number_of_rows)
{
    //sort(m,m + number_of_rows,[](const int* a,const int *b) //()接受的类型应该是指针
    //这里的()可以用auto &a auto &b
    //或者 int &(a)[2],int &(b)[2]
    //这里的2是必须的因为int[2]和int[n]完全是两种类型
    //const int (&a)[2]  // 正确:对长度为2的int数组的引用
    //const int &a[2]    // 错:这是包含2个int引用的数组(语法错误)
    //sort(m,m + number_of_rows,[](const int (&a)[2],const int (&b)[2])
    sort(m,m + number_of_rows,[](auto& a,auto& b)
{
    return (a[0] == b[0]) ? a[1] < b[1]:a[0] < b[0];
});
}
int main()
{
    int m[10][2];
    for(int i = 0;i < 10;i++)
    {
        for(int j =0;j < 2;j++)
        {
            cin >> m[i][j];
        }
    }
    int number_of_rows = 10;
    to_sort(m,number_of_rows);
    for(int i = 0;i < 10;i++)
    {
        for(int j =0;j < 2;j++)
        {
            cout << m[i][j] <<" ";
        }
        cout <<endl;
    }
    return 0;
}
*/
//上面存在mingw的bug
#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

void to_sort(array<array<int, 2>, 6>& m) {
    //array 支持字典序比较，直接 sort 即可
    sort(m.begin(), m.end());
}

int main() {
    array<array<int, 2>, 6> m;

    // 输入 6 行，每行两个整数
    for (auto& row : m) {
        cin >> row[0] >> row[1];
    }

    to_sort(m);

    // 输出排序后的结果
    for (const auto& row : m) {
        cout << "(" <<row[0] << "," << " " << row[1]  << ")" << endl;
    }

    return 0;
}
//如果每行不只是2个,由于sort已经可以闪烁找块,所以在里面加一个for循环确认返回值即可
/*
sort(m.begin(), m.end(), [](const vector<int>& a, const vector<int>& b) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) return a[i] < b[i];
    }
    return false;
});
*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void to_sort(vector<vector<int>>& m) {
    sort(m.begin(), m.end(), [](const vector<int>& a, const vector<int>& b) {
        return (a[0] == b[0]) ? a[1] < b[1] : a[0] < b[0];
    });
}

int main() {
    vector<vector<int>> m(10, vector<int>(2));  // 10 行，每行 2 列

    // 输入
    for (int i = 0; i < 10; ++i) {
        cin >> m[i][0] >> m[i][1];
    }

    to_sort(m);

    // 输出
    for (const auto& row : m) {
        cout << row[0] << " " << row[1] << endl;
    }

    return 0;
}
*/
