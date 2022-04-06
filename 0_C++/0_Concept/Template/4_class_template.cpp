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
	void set_data(T dt);
};
int main()
{
	Data<string> str_data("C++ Test");
	Data<int> int_data(5);

	cout << str_data.get_data() << endl;
	cout << int_data.get_data() << endl;

	return 0;
}

template<typename T>
Data<T>::Data(T dt)
{
	data_ = dt;
}

template<typename T>
T Data<T>::get_data()
{
	return data_;
}

template<typename T>
void Data<T>::set_data(T dt)
{
	data_ = dt;
}

