/*
virtual �Ҹ��� (���� �Ҹ���)

���� �Լ� ���̺� (virtual function table)

���� ���

���� ���
*/
#include <iostream>
using namespace std;
//virtual �Ҹ���
class Parent {
public:
	Parent() { cout << "Parent ������ ȣ��" << endl; }
	virtual ~Parent() { cout << "Parent �Ҹ��� ȣ��" << endl; }
};
class Child :public Parent {
public:
	Child() { cout << "Child ������ ȣ��" << endl; }
	~Child() { cout << "Child �Ҹ��� ȣ��" << endl; }
};
//���۷��� ���
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
	void speak() override { cout << "�п�" << endl; }
};
class Cat :public Animal {
public:
	Cat() : Animal(){}
	void speak() override { cout << "�߿�" << endl; }
};
//���߻��(multiple inheritance)
class I
{
public:
	int i;
	I() { cout << "I ������ ȣ��" << endl; }
};
class J
{
public:
	int j;
	J() { cout << "J ������ ȣ��" << endl; }
};
class K : public I, public J
{
public:
	int k;
	K() : I(),J() { cout << "K ������ ȣ��" << endl; }
};
//���߻�ӽ� ������ -> ���̾Ƹ�� ���
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
	cout << "����� child �� ���������" << endl;
	{Child c; }
	cout << "Parent �����ͷ� Child�� ���������� (��ĳ����)" << endl;
	{
		Parent* p = new Child();
		delete p;
	}
	
}