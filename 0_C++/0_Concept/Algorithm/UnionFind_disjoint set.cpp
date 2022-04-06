/*https://bowbowbow.tistory.com/26*/
#include <iostream>
#include <vector>
using namespace std;
//UnionFind �˰���
struct UnionFind
{
	vector<int> parent;
	UnionFind(int n) :parent(n) {
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}
	//Find ���� 
	//u�� ���� Ʈ���� ��Ʈ ��� ��ȣ�� ��ȯ
	int find(int u) const
	{
		//��Ʈ ���� �θ���� �ڱ��ڽ��� ����Ų��.
		if (u == parent[u])return u;

		//�� ����� �θ��带 ã�� �ö󰣴�.
		return find(parent[u]);
	}
	//Union ����
	//u�� ���� Ʈ���� v�� ���� Ʈ���� ��ģ��.
	void merge(int u, int v)
	{
		//�� ���Ұ� ���� Ʈ���� ��Ʈ ��带 ã�´�.
		u = find(u); v = find(v);
		//u�� v�� �̹� ���� Ʈ���� ���ϴ� ��쿡�� ��ġ�� �ʴ´�.
		if (u == v) return;
		parent[u] = v;
	}
};
//UnionByRank �˰���
//UnionFind�˰��򿡼� �־��� ��� ���Ī Ʈ��-���Ḯ��Ʈ�� ���·� ������ �Ǵ°� �����ϱ����� ���� ����
struct UnionByRank {
	vector<int> parent, rank;
	UnionByRank(int n) : parent(n), rank(n, 1) {
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}
	int find(int u)
	{
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}
	void merge(int u, int v)
	{
		u = find(u); v = find(v);
		if (u == v)return;
		if (rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		if (rank[u] == rank[v]) rank[v]++;
	}
};