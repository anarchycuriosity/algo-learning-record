#include <iostream>
#include <cstring> 
using namespace std;

class Person {
private:
    char* name;
    char sex;
    int age;
public:
    Person(char * nname,char ssex,int aage) 
    {
        name = new char[strlen(nname) + 1];
        strcpy(name,nname);
        sex = ssex;
        age = aage;
    }
    //unknown
    virtual ~Person()
    {
        delete[] name;
    }
    void printInfo()
    {
        cout << "姓名：" << name << endl;
        cout << "性别：" << sex << endl;
        cout << "年龄：" << age << endl;
    }
};

class Student : public Person {
private:
    char* major;
    int grade;
    static int count;
    int id;
public:
    //在对象构造阶段，先初始化基类部分，再初始化派生类部分。
    Student(char * nname,char ssex,int aage,char* mmajor,int ggrade)
    :   Person(nname,ssex,aage)
    {
        major = new char[strlen(mmajor) + 1];
        strcpy(major,mmajor);
        grade = ggrade;
        id = ++count;
    }
    ~Student()
    {
        delete[] major;
    }
    void printInfo()
    {
        cout << "专业：" << major << endl;
        cout << "年级：" << grade << endl;
        cout << "学号：" << id << endl;
    }
};
int Student::count = 0;


int main() {
	char name[20], sex, major[50];
	int age, grade;
	
	cin >> name >> sex >> age;
    Person p(name, sex, age);

	cin >> name >> sex >> age >> major >> grade;
    Student s1(name, sex, age, major, grade);
    
	cin >> name >> sex >> age >> major >> grade;
	Student s2(name, sex, age, major, grade);
	
	p.printInfo();
    cout << endl;
    
    s1.printInfo();
    cout << endl;
    
    s2.Person::printInfo();
    s2.printInfo();

    return 0;
}
