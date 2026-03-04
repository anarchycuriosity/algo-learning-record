#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class Student {
private:
    char id[11];   // 学号
    char* name;    // 姓名（动态分配）
    float math;    // 数学成绩
    float physics; // 物理成绩
    float english; // 英语成绩
    float total;   // 总成绩

public:
    Student() {
        name = nullptr; //  修改：初始化指针，避免析构时 delete 未定义指针
        math = physics = english = total = 0;
    }

    Student(const char* iid, const char* nname, float mmath, float pphysics, float eenglish) {
        strcpy(id, iid); // 修改：直接拷贝学号而不是new 
        name = new char[strlen(nname) + 1]; //  修改：动态分配内存
        strcpy(name, nname);
        math = mmath;
        physics = pphysics;
        english = eenglish;
        total = math + physics + english; //  修改：总分由三科成绩计算，不需要传 ttotal
    }

    ~Student() {
        delete[] name; //  修改：只释放 name，id 是固定数组不需要释放
    }

    void setInfo(const char* _id, const char* _name, float _math, float _physics, float _english) {
        if (name) delete[] name; //  修改：释放旧内存，避免内存泄漏和数据错乱
        strcpy(id, _id);
        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
        math = _math;
        physics = _physics;
        english = _english;
        total = math + physics + english;
    }

    float getTotal() const {
        return total;
    }
    const char* getId() const {
        return id;
    }
    const char* getName() const {
        return name;
    }
    void normPrintInfo() const {
        cout << id << " " << name << ": " << total << endl;
    }
    void printInfo() const {
        cout << "学号：" << id << endl;
        cout << "姓名：" << name << endl;
        cout << "数学成绩：" << math << endl;
        cout << "物理成绩：" << physics << endl;
        cout << "英语成绩：" << english << endl;
        cout << "总成绩：" << total << endl;
    }
};

int main() {
    const int SIZE = 3;
    Student students[SIZE];
    char id[11], name[21];
    float math, physics, english;

    for (int i = 0; i < SIZE; i++) {
        cin >> id >> name >> math >> physics >> english;
        students[i].setInfo(id, name, math, physics, english);
    }

    cin >> id;  // 待查询学号

    // 输出成绩单
    cout << "总分成绩表：" << endl;
    for (int i = 0; i < SIZE; i++) {
        students[i].normPrintInfo();
    }

    // 求出最高总分（遍历而不是 sort，更通用）
    float maxTotal = students[0].getTotal();
    for (int i = 1; i < SIZE; i++) {
        if (students[i].getTotal() > maxTotal) {
            maxTotal = students[i].getTotal();
        }
    }
    cout << "最高总分：" << maxTotal << endl;

    // 输出查询结果
    cout << "查询结果：" << endl;
    for (int i = 0; i < SIZE; i++) {
        if (strcmp(students[i].getId(), id) == 0) { // ✅ 修改：用 strcmp 比较字符串
            students[i].printInfo();
        }
    }

    return 0;
}
/*
默认构造函数没有初始化 name，它指向随机内存。

调用 setInfo 时又 new 一次，但没有释放旧的 name，导致内存泄漏。

最后析构时 delete[] name 释放了未定义的指针，破坏了内存。

所以查学号时输出的 name 变成了乱码。*/