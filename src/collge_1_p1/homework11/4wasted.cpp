#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class Student {
private:
    char id[11];   // 学号
    char* name;    // 姓名
    float math;    // 数学成绩
    float physics; // 物理成绩
    float english; // 英语成绩
    float total;   // 总成绩

public:
    Student() {//哪怕初始化依然会乱码
        name = nullptr;
        math = physics = english = total = 0;
    }
    Student(char* iid,char * nname,float mmath,float pphysics,float eenglish,float ttotal)
    {
        name = new char[strlen(nname) + 1];
        strcpy(id,iid);
        strcpy(name,nname);
        math = mmath;
        physics = pphysics;
        english = eenglish;
        total = math + physics + english;
    }

     ~Student() {
    //delete[] id;
        delete[] name;
    }

    void setInfo(const char* _id, const char* _name, float _math, float _physics, float _english) {
        strcpy(id, _id);
        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
        math = _math;
        physics = _physics;
        english = _english;
        total = math + physics + english;
    }

    float getTotal() {
        return total;
    }
    const char* getId() {
        return id;
    }
    const char* getName() {
    	return name;
    }
    void normPrintInfo()
    {
        cout << id << " " << name << ": " << total << endl;
    }
    void printInfo() {
        cout << "学号：" << id << endl;
        cout << "姓名：" << name << endl;
        cout << "数学成绩：" << math << endl;
        cout << "物理成绩：" << physics << endl;
        cout << "英语成绩：" << english << endl;
        cout << "总成绩：" << total << endl;
    }
    Student(const Student& other) {
    strcpy(id, other.id);
    if (other.name) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    } else {
        name = nullptr;
    }
    math = other.math;
    physics = other.physics;
    english = other.english;
    total = other.total;
}

    Student& operator=(const Student& other) {
    if (this != &other) {
        strcpy(id, other.id);
        if (name) delete[] name;
        if (other.name) {
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
        } else {
            name = nullptr;
        }
        math = other.math;
        physics = other.physics;
        english = other.english;
        total = other.total;
    }
    return *this;
}

   
};

int main() {
	const int SIZE = 3; 
    Student students[SIZE];
    char id[11], name[21];
    float math, physics, english;
    for(int i = 0; i < SIZE; i++)
    {
    	cin >> id;
    	cin >> name;
    	cin >> math >> physics >> english;
    	students[i].setInfo(id, name, math, physics, english);
	}
    //cout << "请输入查询学号：" << endl;
    cin >> id;

    // 输出成绩单
    cout << "总分成绩表：" << endl;
    for(int i = 0;i < SIZE;i++)
    {
        students[i].normPrintInfo();
    }

    // 求出最高总分
    float maxTotal = students[0].getTotal();
    sort(begin(students),end(students),[](Student & a,Student & b){return a.getTotal() < b.getTotal();});
    maxTotal = students[2].getTotal();
    cout << "最高总分：" << maxTotal << endl;

    // 输出查询结果 
    cout << "查询结果：" << endl;
    for(int i = 0;i < SIZE;i++)
    {
        //if(students[i].getId() == id)
        if(strcmp(students[i].getId(),id) == 0)
        {
            students[i].printInfo();
        }
    }

    return 0;
}
