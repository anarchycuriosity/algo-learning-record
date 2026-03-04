#include <iostream>
using namespace std;

#define PI 3.14159 

class Shape {
【完善程序代码】
};

class Cuboid : public Shape {
【完善程序代码】
};


class Cylinder : public Shape {
【完善程序代码】
};


int main() {
	double length, width, height, radius;
	
	cin >> length >> width >> height; 
    Shape* shape1 = new Cuboid(length, width, height);
    
    cin >> radius >> height;
    Shape* shape2 = new Cylinder(radius, height);

    shape1->dispInfo();
    cout << "体积：" << shape1->compVol() << endl;

    shape2->dispInfo();
    cout << "体积：" << shape2->compVol() << endl;

    delete shape1;
    delete shape2;

    return 0;
}
