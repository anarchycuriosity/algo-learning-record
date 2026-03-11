#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
class Area
{
    public:
        int start;
        int end;
        int ban_mark = 0;
        Area(int Start,int End) : start(Start),end(End){}
        Area merge(Area other)
        {
            int new_start,new_end;
            /*
            if((start < other.end || start > other.start) || (end < other.end || end > other.start))
            {
                new_start = std::min(start,other.start);
                new_end = std::max(end,other.end);
            }
            */
            new_start = std::min(start,other.start);
            new_end = std::max(end,other.end);
            Area area(new_start,new_end);
            return area;
        }
        int length()
        {
            return (end - start + 1);
        }
        
};
bool is_cross(Area one,Area two)
{
    //忘记考虑包含的关系，蠢爆了，不习惯写!导致的
    //排除掉不需要合并的关系，剩下的一定是对的
    //if((one.start < two.end && one.start > two.start) || (one.end < two.end && one.end > two.start))
    if(!(one.end < two.start || one.start > two.end))
    {
        return true;
    }
    else 
    {
        return false;
    }

}
int main()
{
    int all_tree;
    int amo_area;
    std::cin >> all_tree >> amo_area;
    std::vector<Area> ori_areas;
    for(int i = 0;i < amo_area;i++)
    {
        int Start,End;
        std::cin >> Start >> End;
        Area area(Start,End);
        ori_areas.emplace_back(area);
    }
    std::sort(ori_areas.begin(),ori_areas.end(),[](Area one,Area two){return one.start < two.start;});
    for(int i = 0; i < amo_area - 1;i++)
    {
        if(is_cross(ori_areas[i],ori_areas[i + 1]))
        {
            ori_areas[i].ban_mark = 1;
            ori_areas[i+1] = ori_areas[i+1].merge(ori_areas[i]);
        }
    }
    int cut = 0;
    for(int i = 0; i < amo_area;i++)
    {
        if(ori_areas[i].ban_mark == 0)
        {
            cut += ori_areas[i].length();
        }
    }
    std::cout << all_tree - cut + 1;

}