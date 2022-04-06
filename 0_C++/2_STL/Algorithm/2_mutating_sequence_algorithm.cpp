#include "2_mutating_sequence_algorithm.h"

//utility
int Increment(int n) { return n + 1; }

void _copy()
{
	vector<int> v1 = { 3,5,1,4,8,7,0,9,2,6 }, v2(10);
	
	//�׻� destination���� ����� ������ �־����
	copy(v1.begin(), v1.begin() + 10, v2.begin());
	
	cout << " ** ��ҵ��� ǥ�� ��� ��ġ�� ��� **" << endl;
	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " : "));
	cout << endl << endl;

	cout << " ** ��ҵ��� ǥ�� ��� ��ġ�� ��� version 2 **" << endl;
	ostream_iterator<int> out_iter(cout);
	copy(v2.begin(), v2.end(), out_iter);
	cout << endl << endl;

	cout << " ** ��ҵ��� ǥ�� ��� ��ġ�� ����� version 2 **" << endl;
	copy(v2.rbegin(), v2.rend(), out_iter);
	cout << endl << endl;

}

void _transform()
{
	vector<int> v(8);

	for (int i = 0; i < v.size(); i++)
		v[i] = i + 1;

	ostream_iterator<int> out_iter(cout, " : ");
	cout << " -- ������ --" << endl;
	copy(v.begin(), v.end(), out_iter);

	transform(v.begin(), v.end(), v.begin(), Increment);
	cout << "-- ������ --" << endl;
	copy(v.begin(), v.end(), out_iter);
}

void _replace()
{
	int arr[10] = { 3,5,7,3,10,8,9,7,4,3 };
	vector<int> v(10);

	copy(arr, arr + 10, v.begin());

	ostream_iterator<int> out_iter(cout, " : ");
	cout << endl << "������" << endl;
	copy(v.begin(), v.end(), out_iter);
	cout << endl;
	
	replace(v.begin(), v.end(), 3, 10);
	cout << endl << "������" << endl;
	copy(v.begin(), v.end(), out_iter);
}

void _fill()
{
	vector<int> v1 = { 1,2,3 };
	vector<int>v2(8);

	copy(v1.begin(), v1.end(), v2.begin());
	ostream_iterator<int> out_iter(cout, " : ");
	cout << "������" << endl;
	copy(v2.begin(), v2.end(), out_iter);
	cout << endl;

	fill(v2.begin(), v2.end(), 5);
	cout << "������" << endl;
	copy(v2.begin(), v2.end(), out_iter);
	cout << endl;
}

void _reverse()
{
	vector<int> v = { 1,2,3,4,5 };
	ostream_iterator<int> out_iter(cout, " : ");

	cout << "������" << endl;
	copy(v.begin(), v.end(), out_iter);
	cout << endl;

	reverse(v.begin(), v.end());
	cout << "������1" << endl;
	copy(v.begin(), v.end(), out_iter);
	cout << endl;

	reverse(v.begin(), v.end()-2);
	cout << "������2" << endl;
	copy(v.begin(), v.end(), out_iter);
	cout << endl;
}

void _random_shuffle()
{
	vector<int> v(8);
	for (int i = 0; i < (int)v.size(); i++)
		v[i] = i + 1;

	cout << "������" << endl;
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	random_shuffle(v.begin(), v.end());
	cout << "������" << endl;
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}
