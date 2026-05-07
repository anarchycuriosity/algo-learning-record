class Engine {
public:
    void start() { std::cout << "Engine start\n"; }
};

class Car : private Engine {
public:
    void drive() {
        start();  // ✅ Car 内部可以用 Engine 的功能
        std::cout << "Car driving\n";
    }
};

int main() {
    Car c;
    c.drive();   // ✅ 可以调用 Car 的接口
    // c.start(); // ❌ 错误：外部不能直接调用 Engine 的接口
}
/*

特性	重写 (Override)	重载 (Overload)
发生位置	基类和派生类	同一个类
是否需要虚函数	✅ 必须	❌ 不需要
函数签名	必须完全一致	参数列表不同
绑定方式	运行时动态绑定	编译时静态绑定
目的	改变继承来的行为	提供多种调用方式
*/

//虚函数 动态绑定 函数重写  名字相同参数相同 根据对象实际类型决定
//非虚函数 静态绑定 函数重载 名字相同参数不同 编译器编译时候决定t.print(10)  t.print(3.14)

///const	变量、参数、成员函数	保证不可修改	石头刻下的承诺
//static	变量、成员、函数	属于类/作用域，共享或持久	公共记事本，大家一起用

//1静态变量
//让某个东西属于类/作用域，而不是某个对象
void counter() {
    static int count = 0; 
    count++;
    cout << count << endl;
}
//2类的静态成员变量
class Student {
    static int total; // 所有学生共享一个total
};
//3类的静态成员函数（直接使用类名调用 Student::showTotal()）  
class Student {
    static void showTotal();
};



