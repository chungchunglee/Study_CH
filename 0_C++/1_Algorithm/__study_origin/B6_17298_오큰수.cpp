/*https://www.acmicpc.net/problem/17298
* ����
ũ�Ⱑ N�� ���� A = A1, A2, ..., AN�� �ִ�. ������ �� ���� Ai�� ���ؼ� ��ū�� NGE(i)�� ���Ϸ��� �Ѵ�. Ai�� ��ū���� �����ʿ� �����鼭 Ai���� ū �� �߿��� ���� ���ʿ� �ִ� ���� �ǹ��Ѵ�. �׷��� ���� ���� ��쿡 ��ū���� -1�̴�.

���� ���, A = [3, 5, 2, 7]�� ��� NGE(1) = 5, NGE(2) = 7, NGE(3) = 7, NGE(4) = -1�̴�. A = [9, 5, 4, 8]�� ��쿡�� NGE(1) = -1, NGE(2) = 8, NGE(3) = 8, NGE(4) = -1�̴�.

�Է�
ù° �ٿ� ���� A�� ũ�� N (1 �� N �� 1,000,000)�� �־�����. ��° �ٿ� ���� A�� ���� A1, A2, ..., AN (1 �� Ai �� 1,000,000)�� �־�����.

���
�� N���� �� NGE(1), NGE(2), ..., NGE(N)�� �������� ������ ����Ѵ�.
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> NGE(N);
	vector<int> answer(N,-1);
	stack<int> index;
	
	for(int i = 0; i<N;i++)
		cin >> NGE[i];
	
	for (int i = 0; i < N; i++)
	{
		while (!index.empty()&& NGE[index.top()] < NGE[i])
		{
			answer[index.top()] = NGE[i];
			index.pop();
		}
		index.push(i);
	}
	for (int i = 0; i < N; i++)
		cout << answer[i] << " ";
	return 0;
}