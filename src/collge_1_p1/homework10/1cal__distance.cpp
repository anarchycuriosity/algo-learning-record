#include <iostream>
#include <cmath>
using namespace std;
class MyPoint
{
    private:
        double x;
        double y;
    
    public:
        MyPoint() : x(0),y(0) {}
        MyPoint(double xVal,double yVal) : x(xVal),y(yVal){}

        double getX() const {return x;}
        double getY() const {return y;}
        
        void setX(double newX) {x = newX;}
        void setY(double newY) {y = newY;}
        void setPoint(double newX,double newY)
        {
            x = newX;
            y = newY;
        }

        double distance(const MyPoint & other) const 
        {
            double dx = x - other.x;
            double dy = y - other.y;
            return sqrt(dx * dx + dy * dy);
        }
};
int main()
{
    double x1,y1,x2,y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    MyPoint p1(x1,y1);
    MyPoint p2(x2,y2);
    cout << p1.distance(p2);
}