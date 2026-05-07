#include <iostream>
using namespace std;

#define PI 3.14159

class Point {
    private:
        int x;
        int y;
    public:
    Point(int xx,int yy)
    {
        x = xx;
        y = yy;
    }
    Point() : x(0),y(0){};
    void setPosition(int xx,int yy)
    {
        x = xx;
        y = yy;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    Point(Point &other)
    {
        x = other.x;
        y = other.y;
    }
};

class Circle {
    private:
    double r;
    Point p;
    static int count;
    public:
    Circle(){count++;};
    Circle(double r,Point pp)
    {
        this->r = r;
        p = pp;
        count++;
    }
    void displayRadiusAndPosition()
    {
        cout << "Radius: " << r << ", Position: (" << p.getX() << ", " << p.getY() << ")" << endl;
    }
    double calculateArea()
    {
        double area = PI * r * r;
        return area;
    }
    static void displayCount()
    {
        cout << "Circle count: " << count;
    }
};
int Circle::count = 0;



int main() {
	int x, y;
	double r;
	cin >> x >> y >> r;

    Point p1;
    p1.setPosition(x, y);
    Circle c1(r, p1);
    c1.displayRadiusAndPosition();
    cout << "Area: " << c1.calculateArea() << endl;
    Circle a[3];
    Circle::displayCount();

    return 0;
}
