//https://modoocode.com/202
#include "operator_overloading.h"




Complex::Complex(const char* str)
{
	real = 0.0f, img = 0.0f;
	int begin = 0, end = strlen(str);
	int pos_i = -1;
	for (int i = 0; i != end; i++)
	{
		if (str[i] == 'i')
		{
			pos_i = i;
			break;
		}
	}

	if (pos_i == -1) // 정수부만 존재할경우
	{
		real = get_number(str, begin, end - 1);
		return;
	}
	else
	{
		real = get_number(str, begin, pos_i - 1);

		bool img_minus = false;
		if (pos_i >= 1 && str[pos_i - 1] == '-') //허수부만 존재할경우 예외처리!
			img_minus = true;

		img = get_number(str, pos_i + 1, end - 1);
		if (img_minus) img *= (-1.0f);
	}
}

Complex Complex::operator+(const Complex& c) const
{
	Complex temp(this->real + c.real, this->img + c.img);
	return temp;
}

Complex Complex::operator-(const Complex& c) const
{
	Complex temp(this->real - c.real, this->img - c.img);
	return temp;
}

Complex Complex::operator*(const Complex& c) const
{
	Complex temp(
		real * c.real - img * c.img,
		real * c.img + img * c.real);
	return temp;
}

Complex Complex::operator/(const Complex& c) const
{
	Complex temp(
		(real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
		(img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
	return temp;
}

Complex& Complex::operator=(const Complex& c)
{
	real = c.real;
	img = c.img;
	return *this;
}

Complex& Complex::operator+=(const Complex& c)
{
	(*this) = (*this) + c;
	return (*this);
}

Complex& Complex::operator-=(const Complex& c)
{
	(*this) = (*this) - c;
	return (*this);
}

Complex& Complex::operator*=(const Complex& c)
{
	(*this) = (*this) * c;
	return (*this);
}

Complex& Complex::operator/=(const Complex& c)
{
	(*this) = (*this) / c;
	return (*this);
}

Complex Complex::operator+(const char* str)
{
	Complex temp(str);
	return *this + temp;
}

Complex Complex::operator-(const char* str)
{
	Complex temp(str);
	return *this - temp;
}

Complex Complex::operator*(const char* str)
{
	Complex temp(str);
	return *this * temp;
}

Complex Complex::operator/(const char* str)
{
	Complex temp(str);
	return *this / temp;
}

double Complex::get_number(const char* str, const int begin, const int end)
{
	char* s = new char[end - begin+1]();
	
	for (int i = begin; i <= end; i++)
		s[i - begin] = str[i];

	 double num = atof(s);
	 delete[] s;

	 return num;
#ifdef __FIRST__ //기 구현 - stdlib 쓰지않고 문자열 파싱
	bool minus = false;
	int from = begin, to = end;

	//잘못된 입력인 경우
	if (from > to)
		return 0;
	//부호 판별 및 인덱스 조절
	if (str[from] == '-')
		minus = true;
	if (str[from] == '-' || str[from] == '+')
		from++;
	
	float num = 0.0f;
	float decimal = 1.0f;

	bool integer_part = true;

	for (int i = from; i <= to; i++)
	{
		if (isdigit(str[i]) && integer_part)
		{
			num *= 10;
			num += (str[i] - '0');
		}
		else if (str[i] == '.')
			integer_part = false;
		else if (isdigit(str[i]) && !integer_part)
		{
			decimal /= 10.0f;
			num += ((str[i] - '0') * decimal);
		}
		else
			break;
	}
	if (minus) num *= -1.0f;
	return num;
#endif 

}


void Complex::display()
{
	std::cout << "값은 " << real << " + " << img << "i 입니다." << std::endl;
}

int main()
{
	while (1)
	{
		char s1[1000] = {};
		char c;
		char s2[1000] = {};
		
		std::cout << "inputdata ?  : ";
		std::cin >> s1;
		std::cout << "calc ?  : ";
		std::cin >> c;
		std::cout << "inputdata2 ?  : ";
		std::cin >> s2;

		std::cout << std::endl << " *Result*" << std::endl;
		if (c == '+')
			(Complex(s1) + s2).display();
		else if (c == '-')
			(Complex(s1) - s2).display();
		else if (c == '*')
			(Complex(s1) * s2).display();
		else if (c == '/')
			(Complex(s1) / s2).display();
		else
			std::cout << "Input Wrong Data" << std::endl;

		std::cout << std::endl << std::endl;
	}
	return 0;
}
