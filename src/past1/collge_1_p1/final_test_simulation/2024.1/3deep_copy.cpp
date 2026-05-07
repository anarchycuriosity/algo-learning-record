#include <iostream>
#include <string.h>
using namespace std;

class Person
{
    protected:

        char *Name;
        int Age;
    
    public:
        Person(){Name = NULL;}

        Person(char * na,int age)
        {
            //Name一开始忘记分配内存了
            //对于指针，我们使用strlen而不是sizeof
            Name = new char[strlen(na) + 1];
            strcpy(Name,na);
            Age = age;
        }

        Person(const Person & p)
        {
            Name = new char[strlen(p.Name) + 1];
            strcpy(Name,p.Name);
            Age = p.Age;
        }

        virtual ~Person()
        {
            //因为Name是字符数组所以应该用[]
            delete[] Name;
            cout << "Destrper" << endl;
        }

        virtual void print_inf()
        {
            cout << (*Name) << endl;
            cout << Age << endl;
        }
};

class Student : public Person
{
    string majority;
    public:

        Student(char* name,int age,string major) : Person(name,age)
        {
            majority = major;
        }
        //子类不需要写析构函数，这会导致重复释放double free
        /*
        ~Student()
        {
            delete Name;
            cout << "Destrper" << endl;
        }
        */
        void print_inf() override
        {
            cout << (*Name) << endl;
            cout << Age << endl;
            cout << majority << endl;
        }
};

int main()
{
    Person* p,p1("zhang san",35);
    Person p2(p1);
    char major[] = "information-science";
    Student s("hu tu",18,major);
    p = &p2;
    p->print_inf();
    return 0;
}