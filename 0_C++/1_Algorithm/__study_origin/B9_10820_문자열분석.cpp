/*
https://www.acmicpc.net/problem/10820����
����
���ڿ� N���� �־�����. �̶�, ���ڿ��� ���ԵǾ� �ִ� �ҹ���, �빮��, ����, ������ ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�� ���ڿ��� ���ĺ� �ҹ���, �빮��, ����, �������θ� �̷���� �ִ�.

�Է�
ù° �ٺ��� N��° �ٱ��� ���ڿ��� �־�����. (1 �� N �� 100) ���ڿ��� ���̴� 100�� ���� �ʴ´�.

���
ù° �ٺ��� N��° �ٱ��� ������ ���ڿ��� ���ؼ� �ҹ���, �빮��, ����, ������ ������ �������� ������ ����Ѵ�.
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	while (getline(cin, str))
	{
		int _a = 0, _A = 0, _num = 0, _sp = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				_a++;
			else if (str[i] >= 'A' && str[i] <= 'Z')
				_A++;
			else if (str[i] >= '0' && str[i] <= '9')
				_num++;
			else if (str[i] == ' ')
				_sp++;
		}
		cout << _a << " " << _A << " " << _num << " " << _sp << endl;
	}
	return 0;
}