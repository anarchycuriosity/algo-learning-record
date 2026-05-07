#include <iostream>

void foo() {
    std::cout << "global foo\n";
}

class Person {
public:
    static void foo() {
        std::cout << "Person::foo\n";
    }
};

int main() {
    ::foo();          // 调用全局作用域里的 foo
    Person::foo();    // 调用类作用域里的 foo
    Person p;
    p.foo();          // 用对象调用成员函数（这里也行，因为是静态函数）
}
/*
前置 ::：往外跳，找全局。

后置 ::：往里走，进入类或命名空间。

其实没那么玄乎,就是类似路径分割符号

为什么不能用 :: 代替 .
. 和 -> 是 对象访问运算符，它们的语义是“通过某个具体对象来调用成员”。

:: 是 作用域解析运算符，它的语义是“在某个作用域里找到名字”。它不依赖对象，而是依赖类名或命名空间。
*/