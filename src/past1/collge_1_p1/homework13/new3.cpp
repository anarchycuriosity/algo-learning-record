#include <iostream>
#include <iomanip>  // 用于控制小数位
using namespace std;

#define PI 3.14159 

// 抽象基类
class Shape {
public:
    virtual void dispInfo() = 0;      // 显示信息
    virtual double compVol() = 0;     // 计算体积
    virtual ~Shape() {}               // 虚析构函数
};

// 长方体类
class Cuboid : public Shape {
private:
    double length, width, height;
public:
    Cuboid(double l, double w, double h) : length(l), width(w), height(h) {}

    void dispInfo() override {
        cout << "长方体长=" << length 
             << "，宽=" << width 
             << "，高=" << height << endl;
    }

    double compVol() override {
        return length * width * height;
    }
};

// 圆柱体类
class Cylinder : public Shape {
private:
    double radius, height;
public:
    Cylinder(double r, double h) : radius(r), height(h) {}

    void dispInfo() override {
        cout << "圆柱体半径=" << radius 
             << "，高=" << height << endl;
    }

    double compVol() override {
        return PI * radius * radius * height;
    }
};

int main() {
    double length, width, height, radius;
    
    cin >> length >> width >> height; 
    Shape* shape1 = new Cuboid(length, width, height);
    
    cin >> radius >> height;
    Shape* shape2 = new Cylinder(radius, height);

    shape1->dispInfo();
    cout << "体积："  << shape1->compVol() << endl;

    shape2->dispInfo();
    cout << "体积："  << shape2->compVol() << endl;

    delete shape1;
    delete shape2;

    return 0;
}

//p->x 等价于 (*p).x