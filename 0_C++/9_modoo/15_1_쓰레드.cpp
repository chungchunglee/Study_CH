/*
프로세스 - 운영체제에서 실행되는 프로그램의 최소 단위
	실행위치? -> CPU의 코어
	코어의 개수만큼 연산 가능
	컨텍스트 스위칭을 통해 싱글코어에서도 멀티 프로세스 가능
	-> 운영체제의 스케줄러가 결정

쓰레드
	CPU의 코어에서 돌아가는 프로그램의 단위
	한개의 코어에서 한개의 쓰레드 명령 처리
	한개의 프로세스는 최소 한개 쓰레드로 구성, 즉 여러 개의 쓰레드로 구성 가능. 여러개의 쓰레드로 구성된 프로그램을 멀티 쓰레드 프로그램

쓰레드 - 프로세스 차이점
	프로세스들은 서로 메모리 공유 X. but, 한 프로세스 내의 서로 다른 쓰레드끼리는 서로 같은 메모리를 공유. -> 같은 변수에 값에 접근 가능
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
		std::cout << "쓰레드 1 작동중 \n";
	}
}
void func2()
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << "쓰레드 2 작동중\n";
	}
}
void func3()
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << "쓰레드 3 작동중\n";
	}
}
#define __2ND__
int main()
{
#ifdef __1ST__
	//쓰레드 생성 - 컨택스트 스위치는 운영체제가 알아서!
	thread t1(func1);
	thread t2(func2);
	thread t3(func3);
	//쓰레드들이 실행을 종료하면 리턴하는 함수
	//join을 하지 않을 경우 쓰레드들이 채 실해되기 전에 함수가 종료되어버려 쓰레드 객체의 소멸자가 호출됨 -> C++ 표준에서는 join되거나 detach되지 않은 쓰레드의 소멸자가 호출되면 예외발생
		// what is "detach" -> 해당 쓰레드를 실행 시킨 후 "잊어버리는 것", 대신 쓰레드는 알아서 백그라운드에서 돌아감
	t1.join();
	t2.join();
	t3.join();
	std::cout << "메인 함수 종료\n";
#endif // __1ST__

#ifdef __2ND__
	thread t1(func1);
	thread t2(func2);
	thread t3(func3);

	t1.detach();
	t2.detach();
	t3.detach();

	std::cout << "메인 함수 종료\n";
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
	printf("쓰레드 %x에서 %d부터 %d까지 계산한 결과 : %d \n", this_id, *start, *(end - 1), sum);
}
int main()
{
	vector<int> data(10000);
	for (int i = 0; i < 10000; i++)
		data[i] = i;

	//각 쓰레드에서 계산된 부분 합들을 저장하는 벡터
	vector<int> partial_sums(4);

	vector<thread> workers;
	for (int i = 0; i < 4; i++)
		workers.push_back(thread(worker, data.begin() + i * 2500, data.begin() + (i + 1) * 2500, &partial_sums[i]));
	for (int i = 0; i < 4; i++)
		workers[i].join();

	int total = 0;
	for (int i = 0; i < 4; i++)
		total += partial_sums[i];

	std::cout << "전체 합 : " << total << std::endl;
}
#endif // __3rd__


