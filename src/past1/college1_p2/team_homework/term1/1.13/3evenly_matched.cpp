#include <bits/stdc++.h>
struct Student
{
    int C, M, E, T;
};
bool is_even(Student &a, Student &b)
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
        std::cin >> student.C >> student.M >> student.E;
        student.T = student.C + student.M + student.E;
        students.emplace_back(student);
    }
    int count = 0;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (is_even(students[i], students[j]))
            {
                count++;
            }
        }
    }
    std::cout << count;
}
