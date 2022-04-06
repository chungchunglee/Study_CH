/*
C++ 표준 문자열 (std::string)

상속 (inheritance)

오버라이딩(overriding)

protected 키워드
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
		:name(name),age(age),position(position),rank(rank){}

	//복사 생성자
	Employee(const Employee& employee) {
		name = employee.name;
		age = employee.age;
		position = employee.position;
		rank = employee.rank;
	}

	//디폴트 생성자
	Employee() {}

	void print_info() {
		cout << name << " (" << position << " , " << age << ") ==>" << calculate_pay() << "만원" << endl;
	}
	int calculate_pay()	{ return 200 + rank * 50;	}
};
class Manager : public Employee {
	int year_of_service;

public:
	Manager(string name, int age, string position, int rank, int year_of_service)
		:year_of_service(year_of_service),Employee(name,age,position,rank){}
	Manager(const Manager& manager)
		:Employee(manager.name, manager.age, manager.position, manager.rank) {	year_of_service = manager.year_of_service;	}
	Manager():Employee(){}
	int calculate_pay() { return 200 + rank * 50 + 5 * year_of_service; }
	void print_info() {
		cout << name << " (" << position << " , " << age <<"," <<year_of_service<< " 연차) ==>" << calculate_pay() << "만원" << endl;
	}
};

class EmployeeList {
	int alloc_employee;					//할당한  총 직원의 수
	int current_employee;			//현재 직원의 수
	int current_manager;				//현재 매니저의 수
	Employee** employee_list;	//직원 데이터
	Manager** manager_list;	//매니저 데이터

public:
	EmployeeList(int alloc_employee) : alloc_employee(alloc_employee) {
		employee_list = new Employee * [alloc_employee];
		manager_list = new Manager * [alloc_employee];
		current_employee = 0;
		current_manager = 0;
	}
	void add_employee(Employee* employee) {
		employee_list[current_employee] = employee;
		current_employee++;
	}
	void add_manager(Manager* manager) {
		manager_list[current_manager] = manager;
		current_manager++;
	}
	int current_employee_num() { return current_employee + current_manager; }

	void print_employee_info() {
		int total_pay = 0;
		for (int i = 0; i < current_employee; i++)
		{
			employee_list[i]->print_info();
			total_pay += employee_list[i]->calculate_pay();
		}
		for (int i = 0; i < current_manager; i++)
		{
			manager_list[i]->print_info();
			total_pay += manager_list[i]->calculate_pay();
		}
		cout << "총 비용 : " << total_pay << "만원" << endl;
	}
	~EmployeeList() {
		for (int i = 0; i < current_employee; i++)
			delete employee_list[i];
		for (int i = 0; i < current_manager; i++)
			delete manager_list[i];
		delete[] employee_list;
		delete[] manager_list;
	}
};


class Base {
protected:
	string parent_string;
public:
	//기반클래스의 생성자를 명시적으로 호출하지 않은 경우 기반클래스의 default 생성자가 호출되게된다.
	Base() :parent_string("기반") { cout << "기반 클래스" << endl; }
	void what() { cout << parent_string << endl; }
};
class Derived :public Base {
	string child_string;
public:
	Derived() :Base(), child_string("파생") {
		cout << "파생클래스" << endl;
		parent_string = "바꾸기";
	}
	//기반클래스 Base의 what 매서드를 파생 클래스 Derived의 what 매서드가 오버라이드(override)
	void what() { cout << child_string << endl; }
};


int main() {
	EmployeeList emp_list(10);
	emp_list.add_employee(new Employee("노홍철", 34, "평사원", 1));
	emp_list.add_employee(new Employee("하하", 34, "평사원", 1));

	emp_list.add_manager(new Manager("유재석", 41, "부장", 7,12));
	emp_list.add_manager(new Manager("정준하", 43, "과장", 4,12));
	emp_list.add_manager(new Manager("박명수", 43, "차장", 5,15));
	emp_list.add_manager(new Manager("정형돈", 36, "대리", 2,10));
	emp_list.add_employee(new Employee("길", 36, "인턴", -2));
	emp_list.print_employee_info();

	cout << "기반 클래스 생성" << endl;
	Base p;
	cout << "파생 클래스 생성" << endl;
	Derived c;
	return 0;
}