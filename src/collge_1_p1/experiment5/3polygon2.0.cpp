#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Point
{
private:
       int x, y;
public:
      Point(int x=0, int y=0) : x(x),y(y){}
      void setX(int xx)
      {
        x = xx;
      }
      void setY(int yy)
      {
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
      void show()
      {
        cout << x << ":" << y;
      } // 输出点坐标

      // 修改: 拷贝构造函数写反了，应该拷贝 other 的值到当前对象
      Point(const Point & other)
      {
        x = other.x;
        y = other.y;
      }
};

class Line
{
private:
      Point p1, p2;
public:
      Line(int x1, int y1, int x2, int y2)//通过点的每个值来初始化
      {
        p1.setX(x1);
        p1.setY(y1);
        p2.setX(x2);
        p2.setY(y2);
      }
      Line(Point p1, Point p2)//通过点来初始化
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
      Line(const Line & other) // 修改: 拷贝构造函数加 const 引用
      {
        p1 = other.p1;
        p2 = other.p2;
      }
      double length()
      {
        return sqrt(pow(p1.getX() - p2.getX(),2) + pow(p1.getY() - p2.getY(),2));
      }  
      Point getP1()
      {
        return p1;
      }
      Point getP2()
      {
        return p2;
      }

      // 修改: 返回类型应为 void，而不是 Point
      void setP1(int xx,int yy)
      {
        p1.setX(xx);
        p1.setY(yy);
      }
      void setP2(int xx,int yy)
      {
        p2.setX(xx);
        p2.setY(yy);
      }
      void show()
      {
        p1.show();
        cout << " - "; // 修改: 增加分隔符更清晰
        p2.show();
      } // 输出直线两个端点坐标
};

class Polygon
{
private:
     vector<Point> points; // 修改: 用 vector 管理顶点，避免手动 new/delete
public:
     Polygon(Point * pp, int point_num)
     {
        for(int i = 0;i < point_num;i++)
        {
          points.push_back(pp[i]);
        }
     } // 由一组顶点来构造多边形，一组顶点有Point对象数组给出

     Polygon(const Polygon & other)
     {
        points = other.points; // 修改: 深拷贝 vector
     } // 拷贝构造函数

     double getArea()
     {
        // 修改: 使用鞋带公式，简洁可靠
        double area = 0;
        int n = points.size();
        for(int i=0;i<n;i++)
        {
            int j = (i+1)%n;
            area += points[i].getX()*points[j].getY() - points[j].getX()*points[i].getY();
        }
        return fabs(area)/2.0;
     } // 计算多边形面积

     double getPerimeter()
     {
        // 修改: 增加周长计算
        double peri = 0;
        int n = points.size();
        for(int i=0;i<n;i++)
        {
            int j = (i+1)%n;
            peri += sqrt(pow(points[i].getX()-points[j].getX(),2) + pow(points[i].getY()-points[j].getY(),2));
        }
        return peri;
     } // 计算多边形周长

     void show()
     {
        cout << "Polygon vertices: ";
        for(auto &pt: points)
        {
            pt.show();
            cout << " ";
        }
        cout << "\nPerimeter: " << getPerimeter();
        cout << "\nArea: " << getArea() << endl;
     } // 输出多边形顶点序列、周长及面积
};

int main()
{
    int n;
    cin >> n;
    Point *points;
    points = new Point[n]; 
    for(int i = 0;i < n;i++)
    {
        int xx,yy;
        cin >> xx >> yy;
        points[i].setX(xx);
        points[i].setY(yy);
    }
    Polygon polygon(points,n);
    polygon.show(); // 修改: 输出更完整信息
    delete[] points; // 修改: 释放动态数组
}
