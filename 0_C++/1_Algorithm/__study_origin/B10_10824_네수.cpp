/*
https://www.acmicpc.net/problem/10824
����
�� �ڿ��� A, B, C, D�� �־�����. �̶�, A�� B�� ���� ���� C�� D�� ���� ���� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�� �� A�� B�� ��ġ�� ���� A�� �ڿ� B�� ���̴� ���� �ǹ��Ѵ�. ��, 20�� 30�� ���̸� 2030�� �ȴ�.

�Է�
ù° �ٿ� �� �ڿ��� A, B, C, D�� �־�����. (1 �� A, B, C, D �� 1,000,000)

���
A�� B�� ���� ���� C�� D�� ���� ���� ���� ����Ѵ�.
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string A, B, C, D;
	cin >> A >> B >> C >> D;
	long long n = stoll(A + B) + stoll(C + D);
	cout << n;
	
	return 0;
}