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
	~Person() { cout << "소멸자 호출" << endl; }
	void ShowPersonInfo();
};
int main()
{
	unique_ptr<Person> hong = make_unique<Person>("길동", 30);
	hong->ShowPersonInfo();

	return 0;
}
Person::Person(const string name, int age)
{
	name_ = name;
	age_ = age;
	cout << "생성자 호출" << endl;
}
void Person::ShowPersonInfo()
{
	cout << name_ << "의 나이는 " << age_ << "살 입니다." << endl;
}