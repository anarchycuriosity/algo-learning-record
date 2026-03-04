#include <iostream>
using namespace std;

class Base {
public:
    void fn1(){cout << "Base::fn1()" << endl;}
    void fn2(){cout << "Base::fn2()" << endl;}
};

class Derived : public Base {
public:
    void fn1(){cout << "Derived::fn1()" << endl;}
    void fn2(){cout << "Derived::fn2()" << endl;}
};

int main() {
    Derived d;
    Base* bp = &d;
    Derived* dp = &d;

    cout << "使用Derived对象调用:" << endl;
    d.fn1();
    d.fn2();

    cout << "使用Base指针调用:" << endl;
    bp->fn1();
    bp->fn2();

    cout << "使用Derived指针调用:" << endl;
    dp->fn1();
    dp->fn2();

    return 0;
}
