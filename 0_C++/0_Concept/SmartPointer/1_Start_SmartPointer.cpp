#include <iostream>
#include <memory>
using namespace std;

class Person
{
private:
	string name_;
	int age_;
public:
	Person(const string name, int age);
	~Person() { cout << "�Ҹ��� ȣ��" << endl; }
	void ShowPersonInfo();
};
int main()
{
	unique_ptr<Person> hong = make_unique<Person>("�浿", 30);
	hong->ShowPersonInfo();

	return 0;
}
Person::Person(const string name, int age)
{
	name_ = name;
	age_ = age;
	cout << "������ ȣ��" << endl;
}
void Person::ShowPersonInfo()
{
	cout << name_ << "�� ���̴� " << age_ << "�� �Դϴ�." << endl;
}