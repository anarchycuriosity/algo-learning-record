#include <vector>
#include <string>
using namespace std;

// 以前应该写过找两个字符串的公共字符，但是没有频率要求，也就是说比如字母l只能出现一次
// 还有点印象是使用两层for循环，一个遍历a字符串一个遍历b，找到一样就丢进不重复的map
// 但是这题有了频率要求，而且不只是两个字符串，而是很多个字符串。
// 因为元素的种类是一定的，是26个字符，这是哈希表的特性，就是我需要根据数据规模(datasize)来确定哈希表的大小(tablesize)
// 可以去尝试想象一个表，横着是26个字母，纵向是各个string，每个格子代表对应字符的次数，求重其实就是求最小值

// 额外聊聊memset,其函数原型是*void memset(void*ptr,int value,size_t num)，功能是快速粉刷覆盖比如数组
// 第一个参数是内存指针，比如数组名，第二个是想要粉刷的变量，第三个是数组的大小，一般用sizeof(arr)来取得
// 需要注意的是，这在粉刷为0的时候很好用，但是不能粉刷为比如1的值
// 因为粉刷的最小单位是字节，如果写1进去，因为int有4个字节，他会刷00000001 00000001 00000001 00000001
// 这其实是一个非常巨大的整数
// 当我们只需要用一个数组去遍历tab的时候，每次遍历我们都需要重新粉刷为0，就可以这样快速粉刷
// 这样既不会从头遍历清0浪费时间，也不需要再开一个数组

// 介绍完了memset之后，其实这题该写法之外的优化思路也就有了
// 我们先初始化一个hash数组来装26个字母，然后和其他的比较更新最小值。
// 既然是要比较，那我们肯定需要两个数组，一个保存上一次比较后更新的状态，一个hashOthherStr经常清空预备下一次比较
// 最后把hash的数据打包丢给std::vector<string> res，二者格式不太一样
class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        std::vector<std::vector<int>> tab; // 其实并不需要这个东西
        // 因为我们会一直对这个表（tab）取最小值，一直在更新，完全不需要保留这个表后面再遍历一次
        for (int i = 0; i < words.size(); i++)
        {
            std::vector<int> chars(26, 0);
            std::string str = words[i];
            for (int j = 0; j < str.size(); j++)
            {
                chars[str[j] - 'a']++;
            }
            tab.push_back(chars);
        }
        std::vector<std::string> res;
        for (int j = 0; j < 26; j++)
        {
            int count = 1e9 + 7;
            for (int i = 0; i < tab.size(); i++)
            {
                count = (count > tab[i][j]) ? tab[i][j] : count;
            }
            if (count != 0)
            {
                while (count--)
                {
                    // to_string是把数字原封不动变成字符串的
                    // res.push_back(to_string('a' + j));
                    res.push_back(std::string(1, static_cast<char>('a' + j)));
                    // 显式转化，其实写string(1,'a'+j)直接写数字也可以
                    // 反正在计算机眼里char和int都是一串数字罢了，这样是为了保险，告诉编译器
                }
            }
        }
        return res;
    }
};