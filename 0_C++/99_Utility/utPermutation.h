#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class utPermutation
{
private:
	//�⺻ data pool
	vector<T>  origin_data;
	//���� data pool
	vector<vector<T>>  permutated_data;
	void swap(T& a, T& b);
public:
	//�⺻ ������
	utPermutation(vector<T> data) :origin_data(data) {}
	//r ���� �������� ���� ��� nPr. -1 �Է½� ��� ����� ��
	utPermutation(vector<T> data, int r);

	//nPr ���ȣ��
	void permutation(int depth, int n, int r);
	//��� ����� ��
	void allpermutation();
	//���� ���� data pool return
	vector<vector<T>> get_permutation();
	//���� ���� data pool ���
	void print_permutation();
};

