#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

class Point
{
    private:
        double x, y;
    public:
        Point(double x = 0, double y = 0) : x(x), y(y) {}

        void setX(double xx)
        {
            x = xx;
        }

        void setY(double yy)
        {
            y = yy;
        }

        double getX()
        {
            return x;
        }

        double getY()
        {
            return y;
        }

        void show()
        {
            cout << x << ":" << y << endl;
        } // 输出点坐标

        Point(const Point & other)
        {
            x = other.x;
            y = other.y;
        }
        //让unique去重可以使用
        bool operator==(const Point & other) const
        {
            return x == other.x && y == other.y;
        }
};

class Line
{
    private:
        Point p1, p2;
    public:
        Line(double x1, double y1, double x2, double y2) //通过点的每个值来初始化
        {
            p1.setX(x1);
            p1.setY(y1);
            p2.setX(x2);
            p2.setY(y2);
        }

        Line(Point p1, Point p2) //通过点来初始化
        {
            this->p1 = p1;
            this->p2 = p2;
        }

        Line()
        {
            p1.setX(0);
            p1.setY(0);
            p2.setX(0);
            p2.setY(0);
        }

        Line(const Line & other)
        {
            p1 = other.p1;
            p2 = other.p2;
        }

        double length()
        {
            return sqrt(pow(p1.getX() - p2.getX(), 2) + pow(p1.getY() - p2.getY(), 2));
        }

        Point getP1()
        {
            return p1;
        }

        Point getP2()
        {
            return p2;
        }

        void setP1(double xx, double yy)
        {
            p1.setX(xx);
            p1.setY(yy);
        }

        void setP2(double xx, double yy)
        {
            p2.setX(xx);
            p2.setY(yy);
        }

        void show()
        {
            p1.show();
            p2.show();
        } // 输出直线两个端点坐标
};

class Polygon
{
    private:
        Line *l;
        Point *p;
        int edges; // 多边形边数
        vector<Point> getSortedPoints() const
        {
            vector<Point> points;
            if (p != nullptr)
            {
                vector<Point> points;
                for (int i = 0; i < edges; i++)
                {
                    points.push_back(p[i]);
                }
                Point base = *min_element(points.begin(), points.end(), [](Point &a, Point &b)
                {
                    if (a.getY() == b.getY())
                    {
                        return a.getX() < b.getX();
                    }
                    return a.getY() < b.getY();
                });

                sort(points.begin(), points.end(), [&](Point &a, Point &b)
                {
                    double alphaA = atan2(a.getY() - base.getY(), a.getX() - base.getX());
                    double alphaB = atan2(b.getY() - base.getY(), b.getX() - base.getX());
                    return alphaA < alphaB;
                });    
                return points;
            }
            else
            {
                vector<Point> points;
                for (int i = 0; i < edges; i++)
                {
                    points.push_back(l[i].getP1());
                    points.push_back(l[i].getP2());
                }
                Point base = *min_element(points.begin(), points.end(), [](Point &a, Point &b)
                {
                    if (a.getY() == b.getY())
                    {
                        return a.getX() < b.getX();
                    }
                    return a.getY() < b.getY();
                });

                sort(points.begin(), points.end(), [&](Point &a, Point &b)
                {
                    double alphaA = atan2(a.getY() - base.getY(), a.getX() - base.getX());
                    double alphaB = atan2(b.getY() - base.getY(), b.getX() - base.getX());
                    return alphaA < alphaB;
                });

                auto last = unique(points.begin(), points.end());
                points.erase(last, points.end());
                return points;
            }
        }
    public:
        Polygon(Line *ll, int edge_num)
        {
            l = new Line[edge_num];
            p = nullptr;
            for (int i = 0; i < edge_num; i++)
            {
                l[i] = ll[i];
            }
            edges = edge_num;
        } // 由一组边来构造多边形，一组边有Line对象数组给出

        Polygon(Point *pp, int point_num)
        {
            l = nullptr;
            p = new Point[point_num];
            for (int i = 0; i < point_num; i++)
            {
                p[i] = pp[i];
            }
            edges = point_num;
        } // 由一组顶点来构造多边形，一组顶点有Point对象数组给出

        Polygon(const Polygon & other)
        {
            edges = other.edges;
            if (other.l != nullptr) //这里原先写成l!=nullptr
            {
                l = new Line[edges];
                l = other.l;
                p = nullptr;
            }
            else if (other.p != nullptr)
            {
                p = new Point[edges];
                l = nullptr;
                p = other.p;
            }
        } // 拷贝构造函数

        double getArea()
        {
            vector<Point> outPoints = getSortedPoints();
            double area = 0;

            for (int i = 0; i < edges - 2; i++)
            {
                area += fabs(0.5 * (outPoints[i].getX() * outPoints[i + 1].getY() +
                                    outPoints[i + 1].getX() * outPoints[i + 2].getY() +
                                    outPoints[i + 2].getX() * outPoints[i].getY() -
                                    outPoints[i].getY() * outPoints[i + 1].getX() -
                                    outPoints[i + 1].getY() * outPoints[i + 2].getX() -
                                    outPoints[i + 2].getY() * outPoints[i].getX()));
            }
            return area;
        }
        // 计算多边形面积
        double getPerimeter()
        {
            vector<Point> outPoints = getSortedPoints();
            double perimeter = 0;
            for (int i = 0; i < edges - 2; i++)
            {
                Line l(outPoints[i],outPoints[i+1]);
                perimeter += l.length();
            }
            return perimeter;
        }
        void show()
        {
            cout << "序列点" << endl;
            for(int i = 0;i < edges;i++)
            {
                getSortedPoints()[i].show();
            }
            cout << "area = " << getArea() << endl;
            cout << "perimeter" << getPerimeter() << endl;
        }
        
        ~Polygon()
        {
            delete[] l;
            delete[] p;
        } // 析构函数
};

int main()
{
    cout << "选择初始化mod: Lines/Points";
    string mode;
    cin >> mode;
    if(mode == "Points")
    {
        int n;
        cin >> n;
        Point *points;
        points = new Point[n];
        for (int i = 0; i < n; i++)
        {
            double xx, yy;
            cin >> xx >> yy;
            points[i].setX(xx);
            points[i].setY(yy);
        }   
        Polygon polygon(points, n);
        cout << "area = " << fixed << setprecision(6) << polygon.getArea() << endl;
        cout << "perimeter = " << polygon.getPerimeter() << endl;
        polygon.show();
        Polygon polygonClon = polygon;
        cout << "拷贝构造后" << endl;
        polygonClon.show();
        // 缺少 delete[] points;
        delete[] points;
    }
    else if(mode == "Lines")
    {
        int n;
        cin >> n;
        Line * lines;
        lines = new Line[n];
        for(int i = 0;i < n;i++)
        {
            double x1,y1,x2,y2;
            cin >> x1 >> y1 >> x2 >> y2;
            lines[i].setP1(x1,y1);
            lines[i].setP2(x2,y2);
        }
        Polygon polygon(lines,n);
        cout << "area = " << fixed << setprecision(6) << polygon.getArea() << endl;
        cout << "perimeter = " << polygon.getPerimeter() << endl;
        polygon.show();
        Polygon polygonClon = polygon;
        cout << "拷贝构造后" << endl;
        polygonClon.show();
        // 缺少 delete[] lines;
        delete[] lines;
    }
    return 0;
    
}
