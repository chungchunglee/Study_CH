/*
https://www.acmicpc.net/problem/1197
����
�׷����� �־����� ��, �� �׷����� �ּ� ���д� Ʈ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�ּ� ���д� Ʈ����, �־��� �׷����� ��� �������� �����ϴ� �κ� �׷��� �߿��� �� ����ġ�� ���� �ּ��� Ʈ���� ���Ѵ�.

�Է�
ù° �ٿ� ������ ���� V(1 �� V �� 10,000)�� ������ ���� E(1 �� E �� 100,000)�� �־�����. ���� E���� �ٿ��� �� ������ ���� ������ ��Ÿ���� �� ���� A, B, C�� �־�����.
�̴� A�� ������ B�� ������ ����ġ C�� �������� ����Ǿ� �ִٴ� �ǹ��̴�. C�� ������ ���� ������, ������ 1,000,000�� ���� �ʴ´�.

�׷����� ������ 1������ V������ ��ȣ�� �Ű��� �ְ�, ������ �� ���� ���̿� ��ΰ� �ִ�. �ּ� ���д� Ʈ���� ����ġ�� -2,147,483,648���� ũ�ų� ����, 2,147,483,647���� �۰ų� ���� �����͸� �Է����� �־�����.

���
ù° �ٿ� �ּ� ���д� Ʈ���� ����ġ�� ����Ѵ�.

���� �Է� 1
3 3
1 2 1
2 3 2
1 3 3
���� ��� 1
3
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find(int u, vector<int>& parent)
{
	if (u == parent[u]) return u;
	//��� ����
	return parent[u] = find(parent[u], parent);
}
void merge(int u, int v, vector<int>& parent)
{
	u = find(u, parent);
	v = find(v, parent);
	if (u == v) return;
	parent[u] = v;
}
bool compare_parent(int u, int v, vector<int>& parent)
{
	u = find(u, parent);
	v = find(v, parent);
	if (u == v) return true;
	else return false;
}

int main()
{
	int N, M;
	cin >> N >> M;
	vector<pair<int, pair<int, int>>> path(M);
	vector<int> parent(N + 1);
	for (int i = 0; i < M; i++)
	{
		int u, v, cost;
		cin >> u >> v >> cost;
		path[i] = { cost,{u,v} };
	}
	sort(path.begin(), path.end());
	for (int i = 1; i <= N; i++)
		parent[i] = i;
	int answer = 0;
	for (int i = 0; i < M; i++)
	{
		int u = path[i].second.first, v = path[i].second.second, cost = path[i].first;
		if (!compare_parent(u, v, parent))
		{
			merge(u, v, parent);
			answer += cost;
		}
	}
	cout << answer;
	return 0;
}
