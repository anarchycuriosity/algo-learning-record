#include <iostream>
#include <vector>
//如果要让函数对main函数中的数据产生应该，应该用&传参
void ins_sort(std::vector<int> &vec1,std::vector<int> &vec2)
{
    for(int i = 0;i < vec2.size();i++)
    {
        int ins_index = 0;
        
            //这里写的有问题，应该在找到插入位置的时候就停下来，不要再对index做多余的操作
            /*
            if(vec2[i] <= vec1[j])
            {
                ins_index++;
            }
            else
            {
                vec1.push_back(0);
                for(int k = vec1.size();k > ins_index;k--)
                {
                    vec1[k] = vec1[k - 1];
                }
                vec1[ins_index] = vec2[i];
            }
            */
        //下面为了找插入位置，应该使用while循环，因为我们不需要完整地找完，在while之后直接就应该退出
        //这里还要注意，可能存在哪怕到了最后都没有比vec2[0]大的数，这会导致无法停下，应该考虑边界,while进行的条件应该多加一个 < vec1.size()
        while(ins_index < vec1.size() && vec2[i] >= vec1[ins_index])//这里决定是小到大还是大到小
        {
            ins_index++;
        }
        vec1.emplace_back(0);
        for(int j = vec1.size() - 1;j > ins_index;j--)
        {
            vec1[j] = vec1[j - 1];
        }
        vec1[ins_index] = vec2[i];
    }
}
void print(std::vector<int> vec)
{
    for(int i = 0;i < vec.size();i++)
    {
        std::cout << vec[i] << " ";
    }
}
int main()
{
    std::vector<int> vec1,vec2;
    std::cout << "两个vec各自输入5个" << std::endl;
    for(int i = 0;i < 5;i++)
    {
        int num;
        std::cin >> num;
        vec1.emplace_back(num);
    }
    for(int i = 0;i < 5;i++)
    {
        int num;
        std::cin >> num;
        vec2.emplace_back(num);
    }
    ins_sort(vec1,vec2);
    print(vec1);
}