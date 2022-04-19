/*
���μ��� - �ü������ ����Ǵ� ���α׷��� �ּ� ����
	������ġ? -> CPU�� �ھ�
	�ھ��� ������ŭ ���� ����
	���ؽ�Ʈ ����Ī�� ���� �̱��ھ���� ��Ƽ ���μ��� ����
	-> �ü���� �����ٷ��� ����

������
	CPU�� �ھ�� ���ư��� ���α׷��� ����
	�Ѱ��� �ھ�� �Ѱ��� ������ ��� ó��
	�Ѱ��� ���μ����� �ּ� �Ѱ� ������� ����, �� ���� ���� ������� ���� ����. �������� ������� ������ ���α׷��� ��Ƽ ������ ���α׷�

������ - ���μ��� ������
	���μ������� ���� �޸� ���� X. but, �� ���μ��� ���� ���� �ٸ� �����峢���� ���� ���� �޸𸮸� ����. -> ���� ������ ���� ���� ����
*/
#define __3rd__
#ifdef __1st2nd__
#include <iostream>
#include <thread>
using std::thread;

void func1()
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << "������ 1 �۵��� \n";
	}
}
void func2()
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << "������ 2 �۵���\n";
	}
}
void func3()
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << "������ 3 �۵���\n";
	}
}
#define __2ND__
int main()
{
#ifdef __1ST__
	//������ ���� - ���ý�Ʈ ����ġ�� �ü���� �˾Ƽ�!
	thread t1(func1);
	thread t2(func2);
	thread t3(func3);
	//��������� ������ �����ϸ� �����ϴ� �Լ�
	//join�� ���� ���� ��� ��������� ä ���صǱ� ���� �Լ��� ����Ǿ���� ������ ��ü�� �Ҹ��ڰ� ȣ��� -> C++ ǥ�ؿ����� join�ǰų� detach���� ���� �������� �Ҹ��ڰ� ȣ��Ǹ� ���ܹ߻�
		// what is "detach" -> �ش� �����带 ���� ��Ų �� "�ؾ������ ��", ��� ������� �˾Ƽ� ��׶��忡�� ���ư�
	t1.join();
	t2.join();
	t3.join();
	std::cout << "���� �Լ� ����\n";
#endif // __1ST__

#ifdef __2ND__
	thread t1(func1);
	thread t2(func2);
	thread t3(func3);

	t1.detach();
	t2.detach();
	t3.detach();

	std::cout << "���� �Լ� ����\n";
#endif // __2ND__

	return 0;
}
#endif // __1st2nd__

#ifdef __3rd__
#include <cstdio>
#include <iostream>
#include <thread>
#include <vector>
using std::vector;
using std::thread;

void worker(vector<int>::iterator start, vector<int>::iterator end, int* result)
{
	int sum = 0;
	for (auto itr = start; itr < end; ++itr)
	{
		sum += *itr;
	}
	*result = sum;
	thread::id this_id = std::this_thread::get_id();
	printf("������ %x���� %d���� %d���� ����� ��� : %d \n", this_id, *start, *(end - 1), sum);
}
int main()
{
	vector<int> data(10000);
	for (int i = 0; i < 10000; i++)
		data[i] = i;

	//�� �����忡�� ���� �κ� �յ��� �����ϴ� ����
	vector<int> partial_sums(4);

	vector<thread> workers;
	for (int i = 0; i < 4; i++)
		workers.push_back(thread(worker, data.begin() + i * 2500, data.begin() + (i + 1) * 2500, &partial_sums[i]));
	for (int i = 0; i < 4; i++)
		workers[i].join();

	int total = 0;
	for (int i = 0; i < 4; i++)
		total += partial_sums[i];

	std::cout << "��ü �� : " << total << std::endl;
}
#endif // __3rd__


