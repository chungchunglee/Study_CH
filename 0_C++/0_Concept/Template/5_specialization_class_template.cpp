#include <iostream>
using namespace std;

template <typename T>
class Data
{
private:
	T data_;
public:
	Data(T dt);
	T get_data();
};

template <> class Data<double>	// double���� ���� ����� Ư��ȭ 
{
private:
	double data_;
public:
	Data(double dt) { data_ = dt; }
	double get_data()
	{
		cout << "double�� �����͸� ����մϴ�." << endl;
		return data_;
	}
};

int main(void)
{
	Data<string> str_data("C++ ����");
	Data<double> double_data(3.14);

	cout << "str_data : " << str_data.get_data() << endl;
	cout << "double_data : " << double_data.get_data() << endl;
	return 0;
}

template <typename T>
Data<T>::Data(T dt)
{
	data_ = dt;
}

template <typename T>
T Data<T>::get_data()
{
	return data_;
}