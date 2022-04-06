/*
is - a �� has - a ����

�������̵�(overriding)

virtual Ű����� �����Լ�(virtual function)

������(polymorphism)
*/

/*
���:: ���Ŭ������ ������  �Ϲ�ȭ(generalize) <-> ��üȭ(specialize) �Ļ�Ŭ������ ������
*/
#include <iostream>
#include <string>
using namespace std;


class Employee {
protected:
	string name;
	int age;
	string position;
	int rank;

public:
	Employee(string name, int age, string position, int rank)
		:name(name), age(age), position(position), rank(rank) {}

	//���� ������
	Employee(const Employee& employee) {
		name = employee.name;
		age = employee.age;
		position = employee.position;
		rank = employee.rank;
	}

	//����Ʈ ������
	Employee() {}

	virtual void print_info() {
		cout << name << " (" << position << " , " << age << ") ==>" << calculate_pay() << "����" << endl;
	}
	virtual int calculate_pay() { return 200 + rank * 50; }
};
class Manager : public Employee {
	int year_of_service;

public:
	Manager(string name, int age, string position, int rank, int year_of_service)
		:year_of_service(year_of_service), Employee(name, age, position, rank) {}
	Manager(const Manager& manager)
		:Employee(manager.name, manager.age, manager.position, manager.rank) {
		year_of_service = manager.year_of_service;
	}
	Manager() :Employee() {}
	int calculate_pay() override { return 200 + rank * 50 + 5 * year_of_service; }
	void print_info() override {
		cout << name << " (" << position << " , " << age << "," << year_of_service << " ����) ==>" << calculate_pay() << "����" << endl;
	}
};
class EmployeeList {
	int alloc_employee;					//�Ҵ���  �� ������ ��
	int current_employee;			//���� ������ ��
	Employee** employee_list;	//���� ������
	//Manager** manager_list;	//�Ŵ��� ������

public:
	EmployeeList(int alloc_employee) : alloc_employee(alloc_employee) {
		employee_list = new Employee * [alloc_employee];
		current_employee = 0;
	}
	void add_employee(Employee* employee) {
		employee_list[current_employee] = employee;
		current_employee++;
	}
	int current_employee_num() { return current_employee; }

	void print_employee_info() {
		int total_pay = 0;
		for (int i = 0; i < current_employee; i++)
		{
			employee_list[i]->print_info();
			total_pay += employee_list[i]->calculate_pay();
		}
		cout << "�� ��� : " << total_pay << "����" << endl;
	}
	~EmployeeList() {
		for (int i = 0; i < current_employee; i++)
			delete employee_list[i];
		delete[] employee_list;
	}
};

class Base {
protected:
	string parent_string;
public:
	//���Ŭ������ �����ڸ� ��������� ȣ������ ���� ��� ���Ŭ������ default �����ڰ� ȣ��ǰԵȴ�.
	Base() :parent_string("���") { cout << "��� Ŭ����" << endl; }
	virtual void what() { cout << parent_string << endl; }
};
class Derived :public Base {
	string child_string;
public:
	Derived() :Base(), child_string("�Ļ�") {
		cout << "�Ļ�Ŭ����" << endl;
		parent_string = "�ٲٱ�";
	}
	//���Ŭ���� Base�� what �ż��带 �Ļ� Ŭ���� Derived�� what �ż��尡 �������̵�(override)
	void what() override { cout << child_string << endl; }
};


int main() {
	
	EmployeeList emp_list(10);
	emp_list.add_employee(new Employee("��ȫö", 34, "����", 1));
	emp_list.add_employee(new Employee("����", 34, "����", 1));

	emp_list.add_employee(new Manager("���缮", 41, "����", 7, 12));
	emp_list.add_employee(new Manager("������", 43, "����", 4, 12));
	emp_list.add_employee(new Manager(" �ڸ��", 43, "����", 5, 15));
	emp_list.add_employee(new Manager("������", 36, "�븮", 2, 10));
	emp_list.add_employee(new Employee("��", 36, "����", -2));
	emp_list.print_employee_info();
	
	/*
	cout << "��� Ŭ���� ����" << endl;
	Base p;
	cout << "�Ļ� Ŭ���� ����" << endl;
	Derived c;
	*/
	Base p;
	Derived c;
	cout << "������ ����" << endl;
	//�� ĳ���� - ���Ŭ������ ����Ű�� �����Ͱ� �Ļ�Ŭ������ ����Ŵ -> �Ļ�Ŭ�������� ���Ŭ������ ĳ�����ϴ� ��

	Base* p_p = &c;
	//�ٿ�ĳ����
	Derived* p_c = static_cast<Derived*>(p_p);
	//static_cast �� ���� ���������� dynamic_cast
	p_c->what();
	return 0;
}