#include <iostream>
#include <cstring>
using namespace std;
class MyString {
private:
    char *p;
public:
/*
    MyString(const MyString &other) {
        len = other.len;
        p = new char[len + 1];
        strcpy(p, other.p);
    }*/
    MyString(const char *s) {
        p = new char[strlen(s) + 1];
        strcpy(p, s);
    }

    // 默认拷贝构造函数（浅拷贝）
    // 只是简单地复制 p 的地址
};

MyString a("Hello");
MyString b = a; // b.p 和 a.p 指向同一块内存

class MyString {
private:
    char *p;
    int len;
public:
    MyString(const char *s) {
        len = strlen(s);
        p = new char[len + 1];
        strcpy(p, s);
    }

    // 深拷贝构造函数
    MyString(const MyString &other) {
        len = other.len;
        p = new char[len + 1];
        strcpy(p, other.p);
    }

    ~MyString() {
        delete[] p;
    }
};

MyString a("Hello");
MyString b = a; // b.p 指向新的内存，内容是 "Hello"
