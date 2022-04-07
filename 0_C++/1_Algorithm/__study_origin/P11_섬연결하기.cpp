/*https://programmers.co.kr/learn/courses/30/lessons/42861
�� �����ϱ�
���� ����
n���� �� ���̿� �ٸ��� �Ǽ��ϴ� ���(costs)�� �־��� ��, �ּ��� ������� ��� ���� ���� ���� �����ϵ��� ���� �� �ʿ��� �ּ� ����� return �ϵ��� solution�� �ϼ��ϼ���.

�ٸ��� ���� �� �ǳʴ���, ������ ���� ������ ���� �����ϴٰ� ���ϴ�. ���� ��� A ���� B �� ���̿� �ٸ��� �ְ�, B ���� C �� ���̿� �ٸ��� ������ A ���� C ���� ���� ���� �����մϴ�.

���ѻ���

���� ���� n�� 1 �̻� 100 �����Դϴ�.
costs�� ���̴� ((n-1) * n) / 2�����Դϴ�.
������ i�� ����, costs[i][0] �� costs[i] [1]���� �ٸ��� ����Ǵ� �� ���� ��ȣ�� ����ְ�, costs[i] [2]���� �� �� ���� �����ϴ� �ٸ��� �Ǽ��� �� ��� ����Դϴ�.
���� ������ �� �� �־����� �ʽ��ϴ�. ���� ������ �ٲ���� ���� ����� ���ϴ�. �� 0�� 1 ���̸� �����ϴ� ����� �־����� ��, 1�� 0�� ����� �־����� �ʽ��ϴ�.
��� �� ������ �ٸ� �Ǽ� ����� �־����� �ʽ��ϴ�. �� ���, �� �� ������ �Ǽ��� �Ұ����� ������ ���ϴ�.
������ �� ���� ���� �־����� �ʽ��ϴ�.
����� ��

n	costs	return
4	[[0,1,1],[0,2,2],[1,2,5],[1,3,1],[2,3,8]]	4
����� �� ����

costs�� �׸����� ǥ���ϸ� ������ ������, �̶� �ʷϻ� ��η� �����ϴ� ���� ���� ���� ������� ��θ� ������ �� �ֵ��� ����� ����Դϴ�.
*/
#include <string>
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
    if (u != v)
        parent[u] = v;
}
bool compare_parent(int u, int v, vector<int>& parent)
{
    u = find(u, parent);
    v = find(v, parent);
    if (u == v) return true;
    else return false;
}

int solution(int n, vector<vector<int>> costs) 
{
    int answer = 0;
    int len = costs.size();
    vector<pair<int, pair<int, int>>> path(len);
    for (int i = 0; i < len; i++)
    {
        int u, v, cost;
        u = costs[i][0];
        v = costs[i][1];
        cost = costs[i][2];
        path[i] = { cost,{u,v} };
    }
    sort(path.begin(), path.end());
    
    vector<int> parent(n + 1);
    for (int i = 1; i < n + 1; i++)
        parent[i] = i;
    
    for (int i = 0; i < len; i++)
    {
        int u, v, cost;
        u = path[i].second.first;
        v = path[i].second.second;
        cost = path[i].first;
        if (compare_parent(u, v, parent))
        {
            merge(u, v, parent);
            answer += cost;
        }
    }
    return answer;
}