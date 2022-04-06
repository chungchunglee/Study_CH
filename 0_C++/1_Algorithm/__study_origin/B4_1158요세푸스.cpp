/*
https://www.acmicpc.net/problem/1158
����
�似Ǫ�� ������ ������ ����.

1������ N������ N���� ����� ���� �̷�鼭 �ɾ��ְ�, ���� ���� K(�� N)�� �־�����. ���� ������� K��° ����� �����Ѵ�.
�� ����� ���ŵǸ� ���� ������ �̷���� ���� ���� �� ������ ����� ������. �� ������ N���� ����� ��� ���ŵ� ������ ��ӵȴ�.
������ ������� ���ŵǴ� ������ (N, K)-�似Ǫ�� �����̶�� �Ѵ�. ���� ��� (7, 3)-�似Ǫ�� ������ <3, 6, 2, 7, 5, 1, 4>�̴�.

N�� K�� �־����� (N, K)-�似Ǫ�� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� K�� �� ĭ�� ���̿� �ΰ� ������� �־�����. (1 �� K �� N �� 5,000)

���
������ ���� �似Ǫ�� ������ ����Ѵ�.
*/
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int N, K, count;
	cin >> N >> K;
	queue<int> round, answer;

	for (int i = 1; i <= N; i++)
		round.push(i);
	while (!round.empty())
	{
		count = K - 1;
		while (count && round.size())
		{
			round.push(round.front());
			round.pop();
			count--;
		}
		answer.push(round.front());
		round.pop();
	}
	cout << "<" << answer.front();
	answer.pop();
	while (!answer.empty())
	{
		cout << ", " << answer.front();
		answer.pop();
	}
	cout << ">" ;
		
	return 0;
}