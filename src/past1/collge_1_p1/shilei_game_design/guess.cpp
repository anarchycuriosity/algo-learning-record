#include <iostream>
//有一些标准库文件间接包含了pair的头文件utility
#include <vector>
#include <algorithm>
#include <random>
#include <set>

//生成随机答案，四位数，1-9互不相同，用从已给数组中洗牌来返回容器
std::vector<int> get_random()
{
    std::vector<int> bases = {1,2,3,4,5,6,7,8,9};
    
    std::random_device rd;
    std:: mt19937 gen(rd());

    std::shuffle(bases.begin(),bases.end(),gen);
    return std::vector<int>(bases.begin(),bases.begin() + 4);
} 

//写一个判断逻辑判断输入是否合法
bool is_valid(std::string &s)
{
    //不是4个
    if(s.size() != 4 )
    {
        return false;
    }
    //禁止：有0或者重复输入一个数字
    else
    {
        std::set<char> used;
        for(int i = 0;i < 4;i++)
        {
            if(s[i] == '0')
            {
                return false;
            }
            if(used.count(s[i]))
            {
                return false;
            }
            used.insert(s[i]);
        }
    }
    return true;
}

//给出提示A和B,由于输入的形式是字符串，但遍历的话肯定是容器更方便
//所以我们考虑guess的参数类型是string，但answer的参数类型是vector
//std::pair<int,int> get_hintpair(std::vector<int> answer,std::string guess){}

struct Hint
{
    int A;
    int B;
};
Hint get_hint(std::vector<int> answer,std::string guess)
{
    int A = 0,B = 0;
    for(int i = 0;i < 4;i++)
    {
        int tar = guess[i] - '0';
        if(answer[i] == tar)
        {
            A++;
        }
        else if(find(answer.begin(),answer.end(),tar) != answer.end())
        {
            B++;
        }
    }
    return Hint(A,B);
}
int main()
{
    std::vector<int> answer = get_random();
    std::cout << "请输入4位数\n";
    int attampt = 0;
    while(attampt < 10)
    {
        int A = 0, B = 0;
        std::string guess;
        std::cin >> guess;
        if(!is_valid(guess))
        {
            std::cout << "输入格式不对\n";
        }
        else
        {
            //有点冗杂,改完之后可以只调用一次函数
            //A = get_hint(answer,guess).A;
            //B = get_hint(answer,guess).B;
            Hint h = get_hint(answer,guess);
            A = h.A;
            B = h.B;
        }
        std::cout << A << "A" << B << "B\n";
        attampt ++;
        std::cout << "你还有" << (10 - attampt)  << "次机会\n";
        if(A == 4)
        {
            std::cout << "你赢了\n";
            return 0;
        }
    }
    std::cout << "你输了\n正确答案是 "; 
    for(int i = 0;i < 4;i++)
    {
        std::cout << answer[i];
    }
    return 0;
}