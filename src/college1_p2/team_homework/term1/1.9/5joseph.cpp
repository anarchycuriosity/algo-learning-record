#include <bits/stdc++.h>
//这个大失败了，行不通
//删除之后。迭代器it会失效
struct Human
{
    int id = 0;
    int yell = 0;
};

int main()
{
    int n,m;
    std::cin >> n >> m;
    std::vector<Human> humans;
    for(int i = 0;i < n;i++)
    {
        Human human;
        human.yell = i + 1;
        human.id = i + 1;
        humans.emplace_back(human);
    }
    //这里不建议使用静态的human.size()和i来遍历
    //使用迭代器，因为vector的内部在动态变化
    for(std::vector<Human>::iterator it = humans.begin();it < humans.end();it++)
    {   
        if(humans.size() >= m)
        {
            if((*it).yell == m)
            {
                int back = 1;
                int forw = 1;
                for(auto back_it = it - 1;back_it >= humans.begin();back_it--)
                {
                    (*back_it).yell = humans.size() - back++;
                }
                for(auto for_it = it + 1;for_it <= humans.end();for_it++)
                {
                    (*for_it).yell = forw++;
                }
                std::cout << (*it).id << " ";
                humans.erase(it);
            }
        }
        else
        {
            std::cout << (*it).id << " ";
        }
    }
}