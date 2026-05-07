#include <iostream>
using namespace std;

class Complex {
    private:
        double real,unreal;
    public:
        Complex(double rreal,double uunreal) : real(rreal) , unreal(uunreal) {}
        Complex operator+(const Complex & other) const 
        {
            return Complex(real + other.real,unreal + other.unreal);
        }
        Complex operator-(const Complex & other) const 
        {
            return Complex(real - other.real,unreal - other.unreal);
        }
        Complex operator*(const Complex & other) const 
        {
            return Complex(real * other.real - unreal * other.unreal,unreal * other.real + real * other.unreal);
        }
        Complex operator/(const Complex & other) const 
        {
            return Complex((real * other.real + unreal * other.unreal)/(other.real * other.real + other.unreal * other.unreal),(unreal * other.real - real * other.unreal)/(other.real * other.real + other.unreal * other.unreal));
        }
        Complex operator++(int) 
        {
            Complex temp(*this);
            real++;
            unreal++;
            return temp;
        }
        Complex &operator++()
        {
            ++real;
            ++unreal;
            return *this;
        }
        void print()
        {
            if(unreal > 0)
            {
                cout << real << " + " << unreal << "i" << endl;
            }
            else if(unreal == 0)
            {
                cout << real  << endl;
            }
            else if(unreal < 0)
            {
                cout << real << " - " << -unreal << "i" << endl;
            }
            
        }
};

int main() {
	double real1, imag1, real2, imag2;
	cin >> real1 >> imag1 >> real2 >> imag2;

    Complex c1(real1, imag1);
    Complex c2(real2, imag2);

    Complex c3 = c1 + c2;
    cout << "c1 + c2 = "; c3.print();

    c3 = c1 - c2;
    cout << "c1 - c2 = "; c3.print();

    c3 = c1 * c2;
    cout << "c1 * c2 = "; c3.print();

    c3 = c1 / c2;
    cout << "c1 / c2 = "; c3.print();

    c3 = ++c1;
    cout << "++c1 = "; c3.print();

    c3 = c1++;
    cout << "c1++ = "; c3.print();

    return 0;
}
