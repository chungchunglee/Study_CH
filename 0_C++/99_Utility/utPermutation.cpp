#include "utPermutation.h"

template<typename T>
void utPermutation<T>::swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
utPermutation<T>::utPermutation(vector<T> data, int r)
{
	origin_data = data;
	if (r == -1)
		allpermutation();
	else
		permutation(0, origin_data.size(), r);
}

template<typename T>
void utPermutation<T>::permutation(int depth, int n, int r)
{
	if (depth == r)
	{
		vector<T> temp(origin_data.begin(), origin_data.begin() + r);
		permutated_data.push_back(temp);
		return;
	}
	for (int i = depth; i < n; i++)
	{
		swap(origin_data[depth], origin_data[i]);
		permutation(depth + 1, n, r);
		swap(origin_data[depth], origin_data[i]);
	}
}

template<typename T>
void utPermutation<T>::allpermutation()
{
	for (int i = 1; i < origin_data.size() + 1; i++)
		permutation(0, origin_data.size(), i);
}

template<typename T>
vector<vector<T>> utPermutation<T>::get_permutation()
{
	return permutated_data;
}

template<typename T>
void utPermutation<T>::print_permutation()
{
	for (int i = 0; i < permutated_data.size(); i++)
	{
		for (int j = 0; j < permutated_data[i].size(); j++)
			cout << permutated_data[i][j];
		cout << endl;
	}
	cout << endl << endl;
}
