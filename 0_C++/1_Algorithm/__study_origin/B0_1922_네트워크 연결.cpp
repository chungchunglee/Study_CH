/*https://www.acmicpc.net/problem/1922
����
�����̴� ��ǻ�Ϳ� ��ǻ�͸� ��� �����ϴ� ��Ʈ��ũ�� �����Ϸ� �Ѵ�. ������ �ƽ��Ե� ��갡 ���� �ʾ� ��ǻ�Ϳ� ��ǻ�͸� ���� �����Ͽ��� �Ѵ�. 
�׷��� ��ΰ� �ڷḦ �����ϱ� ���ؼ��� ��� ��ǻ�Ͱ� ������ �Ǿ� �־�� �Ѵ�. (a�� b�� ������ �Ǿ� �ִٴ� ���� a���� b���� ��ΰ� �����Ѵٴ� ���� �ǹ��Ѵ�. 
a���� b�� �����ϴ� ���� �ְ�, b�� c�� �����ϴ� ���� ������ a�� c�� ������ �Ǿ� �ִ�.)

�׷��� �̿��̸� ��ǻ�͸� �����ϴ� ����� �ּҷ� �Ͽ��� ��ǻ�͸� �����ϴ� ��� �ܿ� �ٸ� ���� ���� �� �� �� ���� ���̴�.
���� �� ��ǻ�͸� �����ϴµ� �ʿ��� ����� �־����� �� ��� ��ǻ�͸� �����ϴµ� �ʿ��� �ּҺ���� ����϶�. ��� ��ǻ�͸� ������ �� ���� ���� ����.

�Է�
ù° �ٿ� ��ǻ���� �� N (1 �� N �� 1000)�� �־�����.

��° �ٿ��� ������ �� �ִ� ���� �� M (1 �� M �� 100,000)�� �־�����.

��° �ٺ��� M+2��° �ٱ��� �� M���� �ٿ� �� ��ǻ�͸� �����ϴµ� ��� ����� �־�����. �� ����� ������ �� ���� ������ �־����µ�, 
���࿡ a b c �� �־��� �ִٰ� �ϸ� a��ǻ�Ϳ� b��ǻ�͸� �����ϴµ� ����� c (1 �� c �� 10,000) ��ŭ ��ٴ� ���� �ǹ��Ѵ�. a�� b�� ���� ���� �ִ�.
*/
/*
���
��� ��ǻ�͸� �����ϴµ� �ʿ��� �ּҺ���� ù° �ٿ� ����Ѵ�.

���� �Է� 1
6
9
1 2 5
1 3 4
2 3 2
2 4 7
3 4 6
3 5 11
4 5 3
4 6 8
5 6 8
���� ��� 1
23
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int getParent(int num, vector<int> &parent)
{
	if (num == parent[num]) return num;
	return parent[num] = getParent(parent[num], parent);
}
void unionParent(int a, int b, vector<int>& parent)
{
	a = getParent(a, parent);
	b = getParent(b, parent);
	if (a != b)
		parent[a] = b;
}
bool findParent(int a, int b, vector<int>& parent)
{
	a = getParent(a, parent);
	b = getParent(b, parent);
	if (a == b)
		return true;
	else
		return false;
}
int main()
{
	int answer = 0;
	int N, M;
	set<int> stored_path;
	cin >> N >> M;
	vector<pair<int, pair<int, int>>> path(M);

	for (int i = 0; i < M; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		path[i] = { cost,{from,to} };
	}
	sort(path.begin(), path.end());
	vector<int> parent(N+1);
	for (int i = 1; i <= N; i++)
		parent[i] = i;

	for (int i = 0; i < M; i++)
	{
		int cost = path[i].first;
		int from = path[i].second.first;
		int to = path[i].second.second;
		if (!findParent(from, to, parent))
		{
			answer += cost;
			unionParent(from, to, parent);
		}
	}
	cout << answer;
	return 0;
}