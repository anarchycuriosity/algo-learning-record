#include <bits/stdc++.h>
struct Student
{
    std::string name;
    int age;
    int score;
};
void train(Student & student)
{
    std::cout << student.name << " ";
    std::cout << student.age + 1 << " ";
    if(student.score <=500)
    {
        std::cout << student.score * 1.2 << std::endl;

    }
    else
    {
        std::cout << 600 << std::endl;        
    }
}
int main()
{
    int n;
    std::cin >> n;
    std::vector<Student> students;
    for(int i = 0;i < n;i++)
    {
        Student student;
        std::cin >> student.name;
        std::cin >> student.age;
        std::cin >> student.score;
        students.emplace_back(student);
    }
    for(int i = 0;i < n;i++)
    {
        train(students[i]);
    }
}