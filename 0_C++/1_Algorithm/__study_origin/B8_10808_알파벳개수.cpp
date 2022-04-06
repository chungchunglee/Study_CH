//https://www.acmicpc.net/problem/10808
/*
* ����
���ĺ� �ҹ��ڷθ� �̷���� �ܾ� S�� �־�����. �� ���ĺ��� �ܾ �� ���� ���ԵǾ� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �ܾ� S�� �־�����. �ܾ��� ���̴� 100�� ���� ������, ���ĺ� �ҹ��ڷθ� �̷���� �ִ�.

���
�ܾ ���ԵǾ� �ִ� a�� ����, b�� ����, ��, z�� ������ �������� �����ؼ� ����Ѵ�.
*/
#include <string>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
	string str;
	vector<int>  alphabet(26);
	cin >> str;

	for (int i = 0; i < str.size(); i++)
		alphabet[str[i] - 'a']++;

	ostream_iterator<int> out_iter(cout," ");
	copy(alphabet.begin(), alphabet.end(), out_iter);

	return 0;
}