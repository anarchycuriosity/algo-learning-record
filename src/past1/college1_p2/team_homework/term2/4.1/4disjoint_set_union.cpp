// 这是一个图论 + 并查集的问题
// 并查集包括并和查,并就是交代祖先,查找就是问祖先
#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>
std::unordered_map<std::string, std::string> fam;
void set_boss(std::string son, std::string boss)
{
    fam[son] = boss;
}
std::string find_boss(std::string son)
{
    if (fam[son] == "" || fam[son] == son)
    {
        return son;
    }

    // 记住,递归必须要改变参数
    std::string first_boss = find_boss(fam[son]);
    fam[son] = first_boss;
    return first_boss;

    // 这里仅仅涉及路线压缩,并不代表fam[son]就是son的祖宗!
    // 因为这只有在遇到+才会处理,+a之后我们就不管a了
}
int main()
{
    std::string str;
    std::cin >> str;
    std::string boss;
    std::string son;
    if (str != "$")
    {
        boss = str.substr(1, str.size() - 1);
        son = str.substr(1, str.size() - 1);
    }
    else
    {
        return 0;
    }

    // 读入询问前的数据
    //  要先读入一次,否则会漏掉询问
    while (str[0] != '?')
    {
        if (str[0] == '#')
        {
            boss = str.substr(1, str.size() - 1);
            // 一定要重新设置son,有残留
            son = str.substr(1, str.size() - 1);

            // 不能盲目set,如果它已经是某个人的儿子了,就不要动它
            // 否则会断掉
            //  set_boss(son, boss);
            if (find_boss(son) == "")
            {
                set_boss(son, son);
            }
        }
        else if (str[0] == '+')
        {
            son = str.substr(1, str.size() - 1);
            set_boss(son, boss);
            find_boss(son);
        }
        std::cin >> str;
    }
    std::string que;
    std::vector<std::string> ques;
    while (str != "$")
    {
        // std::cin >> str;如果放在这里会多cin一次从而漏掉第一个询问

        que = str.substr(1, str.size() - 1);

        ques.push_back(que);
        std::cin >> str;
    }
    for (int i = 0; i < ques.size(); i++)
    {
        // std::cout << ques[i] << " " << fam[ques[i]] << std::endl;
        std::cout << ques[i] << " " << find_boss(ques[i]) << std::endl; // 必须调用函数
    }

    // for (std::unordered_map<std::string, std::string>::iterator it = fam.begin(); it != fam.end(); it++)
    // {
    //     std::cout << (*it).first << " " << (*it).second << std::endl;
    // }
}
