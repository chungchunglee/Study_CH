#include "utPermutation.h"
#include "utPermutation.cpp"

int main()
{
	vector<int> data1 = { 1,2,3 };
	utPermutation<int> perm(data1);
	perm.allpermutation();
	perm.print_permutation();

	vector<int> data2 = { 4,1,3,2,6 };
	utPermutation<int> perm2(data2, 3);
	perm2.print_permutation();

	return 0;
}