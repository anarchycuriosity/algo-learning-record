#include <bits/stdc++.h>
struct Student
{
    std::string name;
    int C, M, E, T;
};
struct Pair
{
    Student A;
    Student B;
};
// 比较函数参数最好加const
bool is_even(const Student &a, const Student &b)
{
    if (std::abs(a.C - b.C) <= 5 && std::abs(a.M - b.M) <= 5 && std::abs(a.E - b.E) <= 5 && std::abs(a.T - b.T) <= 10)
    {
        return true;
    }
    return false;
}
int main()
{
    int N;
    std::cin >> N;
    std::vector<Student> students;
    for (int i = 0; i < N; i++)
    {
        Student student;
        std::cin >> student.name >> student.C >> student.M >> student.E;
        student.T = student.C + student.M + student.E;
        students.emplace_back(student);
    }
    std::vector<Pair> evens;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (is_even(students[i], students[j]))
            {
                Pair pair;
                if (students[i].name < students[j].name)
                {
                    pair.A = students[i];
                    pair.B = students[j];
                }
                else
                {
                    pair.A = students[j];
                    pair.B = students[i];
                }
                evens.emplace_back(pair);
            }
        }
    } // 下面的比较一定要写这个if,否则会导致排序逻辑错误
    std::sort(evens.begin(), evens.end(), [](Pair &a, Pair &b)
              { if(a.A.name == b.A.name)
            {
                return a.B.name < b.B.name;
            }
        return a.A.name < b.A.name; });
    for (int i = 0; i < evens.size(); i++)
    {
        std::cout << evens[i].A.name << " " << evens[i].B.name << std::endl;
    }
}
