#include <iostream>

class ADD
{
    public:
        virtual double add()
        {

        }
        
};
class COMP
{
    private:
        double real,unreal;
    public:
        COMP(double REAL,double UNREAL) : real(REAL),unreal(UNREAL){}
        COMP(COMP & other) 
        {
            real = other.real;
            unreal = other.unreal;
        }
//这里的COMP&是只读
        COMP& operator=(const COMP &other)
        {
            //1检查自赋值
            if(this == &other)
            {
                return *this;
            }
            //2删去原本的数据，如果数据有指针
            //delete[] _data;

            //3给值
            //_len = other._len;
            //_data = new char[_len + 1];
            //strcpy(_data,other._data)

            //链式赋值
            return *this;
        }
        //这里不太推荐用引用作为返回的值
        
        COMP operator+(const COMP& other)
        {
            //过于愚蠢了，应该返回相同的类型
            /*
            COMP::real = COMP::real + other.real;
            COMP::unreal = COMP::unreal + other.unreal;
            */
           /*
           COMP final_comp(this->real + other.real,this->unreal + other.unreal);
           return final_comp;
           临时对象去世，悬空引用
           //return COMP(real + other.real,unreal + other.unreal);当类型是引用的时候不能这么写
            */

            return COMP(this->real + other.real,this->unreal + other.unreal);
        }
};
class ARRAY
{
    private:
        int arr[5];
    public:
        ARRAY()
        {
            for(int i = 0;i < 5;i++)
            {
                arr[i] = 0;
            }
        }
        //有点困扰了，如果传入数组的话他会退化
        ARRAY(int ARR[5])
        {
            for(int i = 0;i < 5;i++)
            {
                arr[i] = ARR[i];
            }
        }

        ARRAY operator+(ARRAY &other)
        {
            //必须引用一个新的对象不然会破坏
            ARRAY result;
            for(int i = 0;i < 5;i++)
            {
                result.arr[i] = arr[i] + other.arr[i];
            }
            return result;
        }
        //ARRAY operator=(ARRAY A1,ARRAY A2)参数太多，实际上，比如c = a + b，a + b这个实际上是一个对象，所以拷贝构造写一个就够了
        ARRAY& operator=(const ARRAY& other)
        {
            //如果没有指针，可以跳过第二第三步也就是分配空间和拷贝
            if(this != &other)
            {
                for(int i = 0;i < 5;i++)
                {

                    this->arr[i] = other.arr[i];
                }
            }
            return *this;
        }

        void print()
        {
            for(int i = 0;i < 5;i++)
            {
                std::cout << arr[i] << " ";
            }
        }
};

int main()
{
    int arr_a1[5],arr_a2[5];
    for(int i = 0;i < 5;i++)
    {
        std::cin>>arr_a1[i];
        std::cin>>arr_a2[i];
    }
    ARRAY a1(arr_a1),a2(arr_a2);
    ARRAY a3;
    a3 = a1 + a2;
    a3.print();
}