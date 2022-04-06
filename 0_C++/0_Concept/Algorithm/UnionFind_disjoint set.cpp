/*https://bowbowbow.tistory.com/26*/
#include <iostream>
#include <vector>
using namespace std;
//UnionFind 알고리즘
struct UnionFind
{
	vector<int> parent;
	UnionFind(int n) :parent(n) {
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}
	//Find 연산 
	//u가 속한 트리의 루트 노드 번호를 반환
	int find(int u) const
	{
		//루트 노드는 부모노드로 자기자신을 가르킨다.
		if (u == parent[u])return u;

		//각 노드의 부모노드를 찾아 올라간다.
		return find(parent[u]);
	}
	//Union 연산
	//u가 속한 트리와 v가 속한 트리를 합친다.
	void merge(int u, int v)
	{
		//각 원소가 속한 트리의 루트 노드를 찾는다.
		u = find(u); v = find(v);
		//u와 v가 이미 같은 트리에 속하는 경우에는 합치지 않는다.
		if (u == v) return;
		parent[u] = v;
	}
};
//UnionByRank 알고리즘
//UnionFind알고리즘에서 최악의 경우 비대칭 트리-연결리스트의 형태로 구현이 되는걸 방지하기위해 높이 저장
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