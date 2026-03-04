#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;
struct friendfile
{
    string name;
    string code;
    int age;
};
int main()
{
    int n;
    cin >> n;
    vector<friendfile> friendfiles;
    for(int i = 0;i < n;i++)
    {
        string name;
        string code;
        int age;
        cin >> name >> code >> age;
        /*
        friendfiles[i].name = name;
        friendfiles[i].code = code;
        friendfiles[i].age = age;
        */
        //不能这么写,因为定义完结构体数组数组内部为空,不能直接修改
        friendfiles.push_back({name,code,age});
        }
    sort(friendfiles.begin(),friendfiles.end(),[](const friendfile &a,const friendfile &b)
    {
        if(a.age == b.age)
        {
            return a.name < b.name;
        }
        else
        {
            return a.age > b.age;
        }
    });
    for(int i = 0;i < n;i++)
    {
        cout << friendfiles[i].name << ", " << friendfiles[i].code << ", " << friendfiles[i].age << endl;
    }
    return 0;
}
