//https://www.acmicpc.net/problem/10809
/*
����
���ĺ� �ҹ��ڷθ� �̷���� �ܾ� S�� �־�����. ������ ���ĺ��� ���ؼ�, �ܾ ���ԵǾ� �ִ� ��쿡�� ó�� �����ϴ� ��ġ��, ���ԵǾ� ���� ���� ��쿡�� -1�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �ܾ� S�� �־�����. �ܾ��� ���̴� 100�� ���� ������, ���ĺ� �ҹ��ڷθ� �̷���� �ִ�.

���
������ ���ĺ��� ���ؼ�, a�� ó�� �����ϴ� ��ġ, b�� ó�� �����ϴ� ��ġ, ... z�� ó�� �����ϴ� ��ġ�� �������� �����ؼ� ����Ѵ�.

����, � ���ĺ��� �ܾ ���ԵǾ� ���� �ʴٸ� -1�� ����Ѵ�. �ܾ��� ù ��° ���ڴ� 0��° ��ġ�̰�, �� ��° ���ڴ� 1��° ��ġ�̴�.
*/
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	string str;
	cin >> str;

	vector<int> ordered_alphabet(26, -1);

	for (int i = 0; i < str.size(); i++)
	{
		if (ordered_alphabet[str[i] - 'a'] == -1)
			ordered_alphabet[str[i] - 'a'] = i;
	}
	for (int i = 0; i < 26; i++)
		cout << ordered_alphabet[i] << " ";

	return 0;
}
