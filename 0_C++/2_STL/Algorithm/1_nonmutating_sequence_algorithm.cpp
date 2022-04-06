#include "1_nonmutating_sequence_algorithm.h"
//���� �Ұ� ������ �˰���

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
	cout << "�Ϲ� for���� �̿��� ����" << endl;
	for (auto k : v)
		PrintElement(k);
	cout << endl;
	cout << "for_each�� �̿��� ��� ����" << endl;
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
	//find�� �־��� ���������� �־��� ���� ������ ���� ã�Ƽ� ù��° ��ġ�� �ݺ��ڸ� ����
	vector<int> vs(8);

	int i = 1;
	for (auto& k : vs)
		k = i++;

	vector<int>::iterator iter;

	iter = find(vs.begin(), vs.end(), 4);
	if (iter != vs.end())
		cout << *iter << "�� ã�ҽ��ϴ�. ��ġ�� " << iter - vs.begin() + 1 << "��° ��� �Դϴ�." << endl;
	else
		cout << "ã�� ���� �����ϴ�." << endl;

	auto k = find(vs.begin(), vs.end(), 20);
	if (k != vs.end())
		cout << *k << "�� ã�ҽ��ϴ�." << endl;
	else
		cout << "ã�� ���� �����ϴ�." << endl;
}
void _find_if()
{
	//find_if�� ������ �Ű������� ������ �Լ��� �Ѱ��ְ� ���������� �Լ��� ������ �����ϴ� ��Ҹ� ã��, �� ��ġ�� �ݺ��� ���·� ��ȯ�Ѵ�.
	vector<int> v(8);

	for (int i = 0; i < v.size(); i++)
		v[i] = i + 1;

	auto iter = find_if(v.begin(), v.end(), Greater5);
	if (iter != v.end())
		cout << *iter << " ���� ã�ҽ��ϴ�. ��ġ�� " << iter - v.begin() + 1 << " ��°�Դϴ�." << endl;
	else
		cout << "���� ��ã�ҽ��ϴ�." << endl;
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
	cout <<"3�� ��� ������ " << n << endl;
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
	cout << "Ȧ���� ��� ������ " << n << endl;
}
//equal
void _equal()
{
	vector<int> v1 = { 3,2,7,9,4,1,3 }, v2 = {1,3,7,9,4,2};

	cout << "��ü ����" << endl;
	for_each(v1.begin(), v1.end(), PrintElement);	cout << endl;
	for_each(v2.begin(), v2.end(), PrintElement);	cout << endl;
	cout << endl;

	cout << "��ҵ��� ��ġ�ϴ��� ������ ����" << endl;
	for_each(v1.begin()+2, v1.begin()+5, PrintElement);	cout << endl;
	for_each(v2.begin()+2, v2.begin()+5, PrintElement);	cout << endl;
	cout << endl;
	
	if (equal(v1.begin() + 2, v1.begin() + 5, v2.begin() + 2) == true)
		cout << "�Ϻ� ������ ��ġ��" << endl;
	else
		cout << "��ġ���� ����" << endl;
}
//search
void _search()
{
	vector<int> v1 = { 1,2,3,4,5 }, v2 = { 3,4 };

	auto iter = search(v1.begin(), v1.end(), v2.begin(), v2.end());

	if (iter != v1.end())
	{
		cout << "v2�� v1�� ���������̸� ������ �����ϴ�." << endl;
		cout << "ù��° �������� ���� ��ġ�� index�� " << iter - v1.begin() << " �Դϴ�." << endl;
	}
}

