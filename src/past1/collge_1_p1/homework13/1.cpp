#include <iostream>
using namespace std;

#define PI 3.14159

class Shape {
    public:
        virtual double getArea() const = 0;
        virtual double getPerim() const = 0;
        virtual ~Shape() {}
};

class Rectangle : public Shape {
    protected:
        double width;
        double height;
    public:
        Rectangle(double w,double h) :width(w),height(h) {}
        double getArea() const override
        {
            return width * height;
        }
        double getPerim() const override
        {
            return 2 * (width + height);
        }
};

class Circle : public Shape {
    private:
        double radius;
    public:
        Circle(double r) : radius(r){}
        double getArea() const override
        {
            return PI * radius * radius;
        }
        double getPerim() const override
        {
            return 2 * PI * radius;
        }
};

class Square : public Rectangle {
    public:
    Square(double side) : Rectangle(side,side) {}
};

int main() {
	double width, height, radius, side;
	cin >> width >> height >> radius >> side;

    Rectangle rect(width, height);
    Circle cir(radius);
    Square sq(side);

    cout << "矩形的面积：" << rect.getArea() << endl;
    cout << "矩形的周长：" << rect.getPerim() << endl;

    cout << "圆的面积：" << cir.getArea() << endl;
    cout << "圆的周长：" << cir.getPerim() << endl;

    cout << "正方形的面积：" << sq.getArea() << endl;
    cout << "正方形的周长：" << sq.getPerim() << endl;

    return 0;
}
