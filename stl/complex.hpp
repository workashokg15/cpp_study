#pragma once
#include <iostream>
using namespace std;

namespace AshokProgramming
{
class Complex
{
    double real;
    double imaginary;

public:
    Complex():real(0.0), imaginary(0.0) {}
    explicit Complex(double real, double imaginary): real(real), imaginary(imaginary) {}
    Complex(const Complex& other)
    {
        *this = other;
    }
    const Complex& operator=(const Complex& other)
    {
        real = other.real;
        imaginary = other.imaginary;
        return *this;
    }
    double get_real() const
    {
        return real;
    }
    double get_imaginary() const
    {
        return imaginary;
    }
    friend Complex operator+(const Complex &c1, const Complex &c2);    
    friend Complex operator+(const Complex &c1, double d);    
    friend Complex operator+(double d, const Complex &c2);    
    friend ostream& operator<<(ostream &out, const Complex& c);
    Complex operator*() const 
    {
        return Complex(real, -imaginary);
    }
};

Complex operator+(const Complex &c1, const Complex &c2)
{
    return Complex(c1.get_real()+c2.get_real(), c1.get_imaginary()+c2.get_imaginary());
}

Complex operator+(const Complex &c1, double d)
{
    return Complex(d+c1.get_real(), c1.get_imaginary());
}    
Complex operator+(double d, const Complex &c1)
{
    return Complex(d+c1.get_real(), c1.get_imaginary());
}    

ostream& operator<<(ostream &out, const Complex& c)
{
    out << "(" << c.get_real() << "," << c.get_imaginary() <<")";
    return out;
}

}//namespace AshokProgramming

using namespace AshokProgramming;
void test_complex_operator_overloading()
{
    Complex c1(3,5);
    cout << c1 + Complex(3.4, 5.6) + 5 + 6 + 7 + Complex(6.5, 5.4) << endl;; 
    cout << *c1 + Complex(3.4, 5.6) + 5 + 6 + 7 + *Complex(6.5, 5.4) << endl;; 
}