using namespace std;
// cpp中有两种常见的静态函数

// 第一种，类中的静态成员函数
//  用static修饰的函数属于类本身而不是某个对象
//  特点是不依赖对象实例，可以直接用类名来调用
//  不能访问非静态成员变量
class MathUtils
{
public:
    static int add(int a, int b) { return a + b; } // 静态函数
};

int result = MathUtils::add(3, 4); // 不需要对象

// 第二种，文件作用域的静态函数
//  static限制作用域只在当前源文件内
//  隐藏实现细节，避免命名冲突
static void helper()
{
    // 只能在当前.cpp文件里用
}

// 现在聊聊仿函数，这是重载了operator()的类对象，让对象可以像函数一样被调用
// 特点，本质是一个类，但行为像函数
struct Multiply
{
    int factor;
    Multiply(int f) : factor(f) {}
    int operator()(int x) { return x * factor; } // 仿函数
};

Multiply times2(2);
int result = times2(5); // 调用对象，结果是10

// 鉴于此时有点遗忘函数重载overload和重写override，复习一下

// 函数重载发生在同一个类
// 返回值类型可以不同但不能仅仅靠返回值来区别
// 编译器在编译期根据参数来决定调用哪一个函数，也就是你按下f5的时候
class Printer
{
public:
    void print(int x) { /* 打印整数 */ }
    void print(double y) { /* 打印浮点数 */ }
    void print(std::string s) { /* 打印字符串 */ }
};
Printer p;
p.print(42);      // 调用 print(int)
p.print(3.14);    // 调用 print(double)
p.print("hello"); // 调用 print(string)

// 函数重写发生在类的继承中，与重载不同，这涉及到多类
// 如果不使用重写和虚函数会丢失多态性，始终调用基类函数
// 关键字是virtual/override
class Base
{
public:
    virtual void show() { std::cout << "Base show\n"; }
};

class Derived : public Base
{
public:
    void show() override { std::cout << "Derived show\n"; }
};

Base *b = new Derived();
b->show(); // 调用 Derived::show (运行期决定)，也就是按下f5之后发生的事情

// 现在聊聊函数隐藏（hiding）
// 子类定义了一个与父类同名的函数，但参数列表不同，或者父类函数不是虚函数
// 于是父类的同名函数在子类作用域中被隐藏，即使参数不同也不会自动重载
// 如果需要调用父类版本，需要显示指定作用域
class Base
{
public:
    void show(int x) { std::cout << "Base show " << x << "\n"; }
};

class Derived : public Base
{
public:
    void show() { std::cout << "Derived show\n"; } // 隐藏了 Base::show(int)
};

Derived d;
d.show(); // 调用 Derived::show
// d.show(10); // 错误：Base::show(int) 被隐藏
d.Base::show(10); // 显式调用父类版本
