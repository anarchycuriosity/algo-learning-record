#include <iostream>
#include <string.h>
#include <string>
//->相当于(*).  使用目标是指针
//this往往配合->使用，this是一个隐式指针，我浅显地认为是为了区分参数和当前对象的同名的变量，它默认存在于每个成员函数下面，是一个特殊的指针
/*
继承方式	public 成员	protected 成员	派生类对象能否访问基类成员
public	public	protected	能访问基类 public
protected	→ protected	protected	不能访问
private	→ private	→ private	不能访问

聊聊const 和override和const override
const主要用来防止某个成员函数修改成员变量
const override一方面，如果基类中有const的要求为了保持签名一致可以加；一方面，双重保险。

聊聊参数赋值，遇到值（value）就赋值，遇到指针类就会复制地址，所以这会导致如果*a = *b，修改a会导致根本的b的变化
*/
/*
自定义类最核心的三个特殊成员函数：拷贝构造（也就是深拷贝，必须额外给内存而不是指向同一块内存）
拷贝赋值（用于将一个已有对象的内容赋值给另一个已经存在的同类型对象。它的典型形式是重载 operator=）
析构函数（当对象的生命结束的时候决定要做的事情，如果不写这个的话，编译器会自己补一个什么东西，也许是默认析构函数）

其中拷贝赋值有着核心的四个步骤
1检查自赋值（防止a = a这种情况出现）
2释放资源
3分配新内存并拷贝
4返回值

现在聊聊重载(overload)，重写(override)，和隐藏（hiding）
重载主要发生在同一个作用域，而重写和隐藏发生在继承。
重写要求基类成员为虚，参数相同，隐藏则完全没有这个要求
只要子类定义了一个与父类同名的函数（不管参数是否相同），父类所有同名函数都会被隐藏。
*/
//2. 拷贝赋值运算符 (实现深拷贝)
class MyString
{
    MyString& operator=(const MyString& other) {
        std::cout << "Copy Assignment Operator called" << std::endl;
        
        // 关键步骤1：检查自赋值
        if (this == &other) {
            return *this;
        }

        // 关键步骤2：释放当前对象已有的资源
        delete[] _data;

        // 关键步骤3：分配新资源并拷贝内容
        _len = other._len;
        _data = new char[_len + 1];
        strcpy(_data, other._data);

        // 关键步骤4：返回*this以支持链式赋值 (a = b = c)
        return *this;
    }
};