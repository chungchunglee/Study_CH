#include <iostream>
#include <cctype>
#include <cstdlib>

class Complex
{
private:
	double real, img;

public:
	Complex(double real, double img) :real(real), img(img) {}
	Complex(const Complex& c) { real = c.real, img = c.img; }
	Complex(const char* str);

	Complex operator+(const Complex& c) const;
	Complex operator-(const Complex& c) const;
	Complex operator*(const Complex& c) const;
	Complex operator/(const Complex& c) const;
	Complex& operator=(const Complex& c);

	Complex& operator+=(const Complex& c);
	Complex& operator-=(const Complex& c);
	Complex& operator*=(const Complex& c);
	Complex& operator/=(const Complex& c);

	Complex operator+(const char* str);
	Complex operator-(const char* str);
	Complex operator*(const char* str);
	Complex operator/(const char* str);

	double get_number(const char* str, const int begin, const int end);

	void display();
};