#include "1_nonmutating_sequence_algorithm.h"
//변경 불가 시퀀스 알고리즘

//utility
void PrintElement(int n)
{
	cout << n << "  ";
}
bool Greater5(int n)
{
	return n > 5;
}
bool is_odd(int num)
{
	return num % 2 == 1;
}


//for_each
void _for_each()
{
	vector<int> v(8);

	for (int i = 0; i < v.size(); i++)
		v[i] = i + 1;
	cout << "일반 for문을 이용한 접근" << endl;
	for (auto k : v)
		PrintElement(k);
	cout << endl;
	cout << "for_each를 이용한 요소 접근" << endl;
	for_each(v.begin(), v.end(), PrintElement);
	cout << endl;
	for_each(v.rbegin(), v.rend(), PrintElement);
	cout << endl;
	auto iter = v.begin();
	auto riter = v.rbegin();
	for_each(iter, 1 + iter, PrintElement);
	cout << endl;
	for_each(riter, 2 + riter, PrintElement);
	cout << endl;
}
//find / find_if
void _find()
{
	//find는 주어진 구간내에서 주어진 값과 동일한 값을 찾아서 첫번째 위치의 반복자를 리턴
	vector<int> vs(8);

	int i = 1;
	for (auto& k : vs)
		k = i++;

	vector<int>::iterator iter;

	iter = find(vs.begin(), vs.end(), 4);
	if (iter != vs.end())
		cout << *iter << "를 찾았습니다. 위치는 " << iter - vs.begin() + 1 << "번째 멤버 입니다." << endl;
	else
		cout << "찾는 값이 없습니다." << endl;

	auto k = find(vs.begin(), vs.end(), 20);
	if (k != vs.end())
		cout << *k << "를 찾았습니다." << endl;
	else
		cout << "찾는 값이 없습니다." << endl;
}
void _find_if()
{
	//find_if는 마지막 매개변수로 조건자 함수를 넘겨주고 구간내에서 함수의 조건을 만족하는 요소를 찾고, 그 위치를 반복자 형태로 반환한다.
	vector<int> v(8);

	for (int i = 0; i < v.size(); i++)
		v[i] = i + 1;

	auto iter = find_if(v.begin(), v.end(), Greater5);
	if (iter != v.end())
		cout << *iter << " 값을 찾았습니다. 위치는 " << iter - v.begin() + 1 << " 번째입니다." << endl;
	else
		cout << "값을 못찾았습니다." << endl;
}
//count, count_if
void _count()
{
	vector<int> v;
	v.push_back(3);
	v.push_back(2);
	v.push_back(7);
	v.push_back(9);
	v.push_back(4);
	v.push_back(1);
	v.push_back(3);

	auto n = count(v.begin(), v.end(), 3);
	cout <<"3인 멤버 개수는 " << n << endl;
}
void _count_if()
{
	vector<int> v;
	v.push_back(3);
	v.push_back(2);
	v.push_back(7);
	v.push_back(9);
	v.push_back(4);
	v.push_back(1);
	v.push_back(3);

	auto n = count_if(v.begin(), v.end(), is_odd);
	cout << "홀수인 멤버 개수는 " << n << endl;
}
//equal
void _equal()
{
	vector<int> v1 = { 3,2,7,9,4,1,3 }, v2 = {1,3,7,9,4,2};

	cout << "전체 구간" << endl;
	for_each(v1.begin(), v1.end(), PrintElement);	cout << endl;
	for_each(v2.begin(), v2.end(), PrintElement);	cout << endl;
	cout << endl;

	cout << "요소들이 일치하는지 조사할 구간" << endl;
	for_each(v1.begin()+2, v1.begin()+5, PrintElement);	cout << endl;
	for_each(v2.begin()+2, v2.begin()+5, PrintElement);	cout << endl;
	cout << endl;
	
	if (equal(v1.begin() + 2, v1.begin() + 5, v2.begin() + 2) == true)
		cout << "일부 구간이 일치함" << endl;
	else
		cout << "일치하지 않음" << endl;
}
//search
void _search()
{
	vector<int> v1 = { 1,2,3,4,5 }, v2 = { 3,4 };

	auto iter = search(v1.begin(), v1.end(), v2.begin(), v2.end());

	if (iter != v1.end())
	{
		cout << "v2는 v1의 서브집합이며 순서가 같습니다." << endl;
		cout << "첫번째 서브집합 시작 위치의 index는 " << iter - v1.begin() << " 입니다." << endl;
	}
}

