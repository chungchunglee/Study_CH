#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class utPermutation
{
private:
	//기본 data pool
	vector<T>  origin_data;
	//순열 data pool
	vector<vector<T>>  permutated_data;
	void swap(T& a, T& b);
public:
	//기본 생성자
	utPermutation(vector<T> data) :origin_data(data) {}
	//r 값을 바탕으로 순열 계산 nPr. -1 입력시 모든 경우의 수
	utPermutation(vector<T> data, int r);

	//nPr 재귀호출
	void permutation(int depth, int n, int r);
	//모든 경우의 수
	void allpermutation();
	//현재 순열 data pool return
	vector<vector<T>> get_permutation();
	//현재 순열 data pool 출력
	void print_permutation();
};

