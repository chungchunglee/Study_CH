/*
virtual 소멸자 (가상 소멸자)

가상 함수 테이블 (virtual function table)

다중 상속

가상 상속
*/
#include <iostream>
using namespace std;
//virtual 소멸자
class Parent {
public:
	Parent() { cout << "Parent 생성자 호출" << endl; }
	virtual ~Parent() { cout << "Parent 소멸자 호출" << endl; }
};
class Child :public Parent {
public:
	Child() { cout << "Child 생성자 호출" << endl; }
	~Child() { cout << "Child 소멸자 호출" << endl; }
};
//레퍼런스 사용
class A {
public:
	virtual void show() { cout << "Parent!" << endl; }
};
class B:public A
{
public:
	void show() override { cout << "Child!" << endl; }
};
void test(A& a) { a.show(); }
//pure virtual function
class Animal {
public:
	Animal(){}
	virtual ~Animal() {}
	virtual void speak() = 0;
};
class Dog :public Animal {
public:
	Dog() : Animal() {}
	void speak() override { cout << "왈왈" << endl; }
};
class Cat :public Animal {
public:
	Cat() : Animal(){}
	void speak() override { cout << "야옹" << endl; }
};
//다중상속(multiple inheritance)
class I
{
public:
	int i;
	I() { cout << "I 생성자 호출" << endl; }
};
class J
{
public:
	int j;
	J() { cout << "J 생성자 호출" << endl; }
};
class K : public I, public J
{
public:
	int k;
	K() : I(),J() { cout << "K 생성자 호출" << endl; }
};
//다중상속시 주의점 -> 다이아몬드 상속
int main() {
	K k;

	Animal* dog = new Dog();
	Animal* cat = new Cat();
	dog->speak();
	cat->speak();

	A a;
	B b;
	test(a);
	test(b);
	cout << "----------" << endl;
	cout << "평범한 child 를 만들었을때" << endl;
	{Child c; }
	cout << "Parent 포인터로 Child를 가르켰을때 (업캐스팅)" << endl;
	{
		Parent* p = new Child();
		delete p;
	}
	
}