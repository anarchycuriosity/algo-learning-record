/*
聊聊&符号不同意义的区分
在表达式中，它代表取地址。而在声明类型，包括返回类型和参数列表的时候，它代表只读，return *this代表返回这个类型而不是地址

 COMP& operator+(const COMP& other)
        {
            //过于愚蠢了，应该返回相同的类型
            
            COMP::real = COMP::real + other.real;
            COMP::unreal = COMP::unreal + other.unreal;
            
           COMP final_comp(this->real + other.real,this->unreal + other.unreal);
           return final_comp;
           //这里返回了局部引用，有点危险，这个a + b必须及时地赋值给一个c，否则这行结束的时候a + b创造的临时对象就结束了
           //return COMP(real + other.real,unreal + other.unreal);当类型是引用的时候不能这么写
        }
其实在重载+的时候，建议使用返回对象而不是引用。
而在重载+=这类的时候，返回引用，而且是返回*this，返回局部引用需要谨慎

*/