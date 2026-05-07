#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Point {
    int x, y;
public:
    Point(int x=0, int y=0): x(x), y(y) {}
    Point(const Point &other) { x = other.x; y = other.y; }
    int getX() const { return x; }
    int getY() const { return y; }
};

class Polygon {
    vector<Point> points;
public:
    Polygon(Point *pp, int n) {
        for(int i=0;i<n;i++) points.push_back(pp[i]);
    }
    double getArea() const {
        double area = 0;
        int n = points.size();
        for(int i=0;i<n;i++) {
            int j = (i+1)%n;
            area += points[i].getX()*points[j].getY() - points[j].getX()*points[i].getY();
        }
        return fabs(area)/2.0;
    }
};

int main() {
    int n;
    cin >> n;
    Point *points = new Point[n];
    for(int i=0;i<n;i++) {
        int xx, yy;
        cin >> xx >> yy;
        points[i] = Point(xx, yy);
    }
    Polygon polygon(points,n);
    cout << polygon.getArea();
    delete[] points;
}
