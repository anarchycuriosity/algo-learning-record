#include <iostream>
#include <cmath>
using namespace std;
class Point
{
    private:
        double x,y;
    public:

    //double dist = sqrt((x * x + y * y));要在初始化之后再写x,y
    //double alpha0 = acos(x / dist);
    Point(double xx = 0,double yy = 0)
    {
        x = xx;
        y = yy;
    }
    double alpha0() 
    {
        double alpha0 = acos(x / dist());
        return alpha0;
    }
    
    double dist()
    {
        double dist = sqrt((x * x + y * y));
        return dist;
    }

    void pan(double delta_x,double delta_y)
    {
        x = x + delta_x;
        y = y + delta_y;
    }

    void rotate(double alpha)
    {
        x = dist() * cos(alpha0() + alpha);
        y = dist() * sin(alpha0() + alpha);
    }

    double getX()
    {
        return x;
    }
    double getY()
    {
        return y;
    }
    void display()
    {
        cout << x << ":" << y << endl;
    }
};
int main()
{
    int x,y;
    cin >> x >> y;
    Point p1(x,y);
    Point p2(x,y);
    Point p3(x,y);
    cout << "点到原点: " << p1.dist() <<endl;

    cout << "输入两个坐标实现点的平移" << endl;
    int delta_x,delta_y;
    cin >> delta_x >> delta_y;
    p1.pan(delta_x,delta_y);
    p1.display();

    cout << "输入alpha来实现旋转" << endl;
    int alpha;
    cin >> alpha;
    p2.rotate(alpha);
    p2.display();
    
    cout << "get函数单独得到xy" << endl;
    cout << p3.getX() << " " << p3.getY();
}