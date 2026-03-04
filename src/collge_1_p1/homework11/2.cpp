#include <iostream>
using namespace std;

class Complex {
    private:
        double real;
        double fake;
    public:
        Complex()
        {

        }
        Complex(double a,double b) : real(a),fake(b){}
        Complex(double c) : real(c),fake(0){}
        void add(Complex & other)
        {
            real += other.real;
            fake += other.fake;
        }
        void show()
        {
            cout << real << " + " << fake << "i";
        }

};

int main() {
	double a, b, c;
	cin >> a >> b >> c;

    Complex c1(a, b);
    Complex c2(c);
    c1.add(c2);
    c1.show();
    
    return 0;
}