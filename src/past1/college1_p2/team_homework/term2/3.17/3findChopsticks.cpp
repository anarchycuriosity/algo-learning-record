#include <iostream>
#include <map>
#include <unordered_map> //并不默认根据键来升序
int main()
{
    int n;
    scanf("%d", &n);
    int *chops = new int[n];
    int target = 1;
    std::map<int, int> chopCount;
    for (int i = 0; i < n; i++)
    {
        // scanf("%d", chops[i]);数组退化为首指针，只在前面加个&也可
        scanf("%d", chops + i);
        chopCount[chops[i]]++;
    }
    for (std::pair<int, int> one : chopCount) // pair必须告诉模板是什么
    {
        if (one.second % 2 != 0)
        {
            target = one.first;
        }
    }
    delete[] chops;
    printf("%d", target);
}