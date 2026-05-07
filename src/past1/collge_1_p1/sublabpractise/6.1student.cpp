#include <iostream>
using namespace std;
struct Student
{
    string name;
    int num;
    int score;
};
void printStudent(const Student &s)
{
    cout << s.name << " ";
    cout << s.num << " ";
    cout << s.score;
}

Student *findTop(Student students[],int n)
{
    int top = students[0].score;
    int idtop = 0;
    for(int i = 1;i < n;i++)
    {
        if(students[i].score > top)
        {
            top = students[i].score;
            idtop = i;
        }
    }
    return &(students[idtop]);
}

int main()
{
    int n;
    cin >> n;
    Student students[n];
    for(int i = 0;i < n;i++)
    {
        string name;
        int num;
        int score;
        cin >> name >> num >> score;
        students[i].name = name;
        students[i].num = num;
        students[i].score = score;
    }
    for(int i = 0;i < n;i++)
    {
        printStudent(students[i]);
    }
    cout << "最高分学生信息: " << "姓名: " << findTop(students,n)->name << " 学号: " << findTop(students,n)->num << " 成绩: " << findTop(students,n)->score;
    return 0;
}