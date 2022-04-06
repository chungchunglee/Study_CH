/*
https://www.acmicpc.net/problem/11655
ROT13�� ī�̻縣 ��ȣ�� �������� ���� ���ĺ��� 13���ھ� �о �����.

���� ���, "Baekjoon Online Judge"�� ROT13���� ��ȣȭ�ϸ� "Onrxwbba Bayvar Whqtr"�� �ȴ�. ROT13���� ��ȣȭ�� ������ ���� �������� �ٲٷ��� ��ȣȭ�� ���ڿ��� �ٽ� ROT13�ϸ� �ȴ�. �տ��� ��ȣȭ�� ���ڿ� "Onrxwbba Bayvar Whqtr"�� �ٽ� ROT13�� �����ϸ� "Baekjoon Online Judge"�� �ȴ�.

ROT13�� ���ĺ� �빮�ڿ� �ҹ��ڿ��� ������ �� �ִ�. ���ĺ��� �ƴ� ���ڴ� ���� ���� �״�� ���� �־�� �Ѵ�. ���� ���, "One is 1"�� ROT13���� ��ȣȭ�ϸ� "Bar vf 1"�� �ȴ�.

���ڿ��� �־����� ��, "ROT13"���� ��ȣȭ�� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���ĺ� �빮��, �ҹ���, ����, ���ڷθ� �̷���� ���ڿ� S�� �־�����. S�� ���̴� 100�� ���� �ʴ´�.

���
ù° �ٿ� S�� ROT13���� ��ȣȭ�� ������ ����Ѵ�.
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string S;
	getline(cin, S);

	for (int i = 0; i < (int)S.size(); i++)
	{
		if (S[i] >= 'A' && S[i] <= 'Z') //97~122
		{
			if (S[i] + 13 > 'Z')
				S[i] -= 13;
			else
				S[i] += 13;
		}
		else if (S[i] >= 'a' && S[i] <= 'z') //65~90
		{
			if (S[i] + 13 > 'z')
				S[i] -= 13;
			else
				S[i] += 13;
		}
	}
	cout << S;

	return 0;
}