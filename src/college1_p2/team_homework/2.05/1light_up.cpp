#include <vector>
#include <iostream>

struct op
{
    double a;
    int t;
};
int main()
{
    int n;
    std::cin >> n;
    std::vector<op> ops;
    for (int i = 0; i < n; i++)
    {
        double a;
        int t;
        std::cin >> a >> t;
        ops.push_back({a, t});
    }
    std::vector<int> lights(5000000, 0);
    for (op sth : ops)
    {
        for (int i = 1; i <= sth.t; i++)
        {
            int mark = i * sth.a - 1;
            lights[mark] = (++lights[mark]) % 2;
        }
    }
    int mark = 0;
    for (int i = 0; i < lights.size(); i++)
    {
        if (lights[i] == 1)
        {
            mark = i;
            break;
        }
    }
    mark++;
    std::cout << mark;
}