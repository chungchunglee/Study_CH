/*https://programmers.co.kr/learn/courses/30/lessons/43162?language=cpp
��Ʈ��ũ
���� ����
��Ʈ��ũ�� ��ǻ�� ��ȣ ���� ������ ��ȯ�� �� �ֵ��� ����� ���¸� �ǹ��մϴ�. ���� ���, ��ǻ�� A�� ��ǻ�� B�� ���������� ����Ǿ��ְ�, ��ǻ�� B�� ��ǻ�� C�� ���������� ����Ǿ� ���� �� ��ǻ�� A�� ��ǻ�� C�� ���������� ����Ǿ� ������ ��ȯ�� �� �ֽ��ϴ�. ���� ��ǻ�� A, B, C�� ��� ���� ��Ʈ��ũ �� �ִٰ� �� �� �ֽ��ϴ�.

��ǻ���� ���� n, ���ῡ ���� ������ ��� 2���� �迭 computers�� �Ű������� �־��� ��, ��Ʈ��ũ�� ������ return �ϵ��� solution �Լ��� �ۼ��Ͻÿ�.

���ѻ���
��ǻ���� ���� n�� 1 �̻� 200 ������ �ڿ����Դϴ�.
�� ��ǻ�ʹ� 0���� n-1�� ������ ǥ���մϴ�.
i�� ��ǻ�Ϳ� j�� ��ǻ�Ͱ� ����Ǿ� ������ computers[i][j]�� 1�� ǥ���մϴ�.
computer[i][i]�� �׻� 1�Դϴ�.
����� ��
n	computers	return
3	{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}	2
3	{{1, 1, 0}, {1, 1, 1}, {0, 1, 1}}	1
����� �� ����
���� #1
�Ʒ��� ���� 2���� ��Ʈ��ũ�� �ֽ��ϴ�.
image0.png

���� #2
�Ʒ��� ���� 1���� ��Ʈ��ũ�� �ֽ��ϴ�.
image1.png
*/
#include <string>
#include <vector>

using namespace std;

void DFS(int n, vector<vector<int>>& computers, vector<int>& visited, int index)
{
    for (int i = 0; i < n; i++)
    {
        if (i != index && visited[i] == 0 && computers[i][index] == 1)
        {
            visited[i] = 1;
            DFS(n, computers, visited, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<int> visited(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 1)
            continue;
        answer++;
        DFS(n,computers,visited,i);
    }

    return answer;
}
int main()
{
    int s1;
    //(4, {{1, 1, 0, 1}, {1, 1, 0, 0}, {0, 0, 1, 1}, {1, 0, 1, 1}})
    s1 = solution(4, { {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 0, 1, 1}, {1, 0, 1, 1} });
    s1 = solution(4, { {1, 0, 0, 0}, { 1,1, 0, 0 }, { 0, 1, 1,0 },{1,1,1,1} });
    s1 = solution(3, { {1, 1, 0}, { 1, 1, 0 }, { 0, 0, 1 } });
    s1 = solution(3,	{ {1, 1, 0}, { 1, 1, 1 }, { 0, 1, 1 }});
    s1 = solution(4, { {1, 1, 1, 1}, { 1,1, 1, 0 }, { 0, 1, 1,1 },{1,1,1,1} });
    
    return 0;
}
#ifdef __OTHERS__
#include <string>
#include <vector>

using namespace std;

void DFS(int from, int n, vector<int>& visited, vector<vector<int>>& computers) {

    for (int i = 0; i < n; i++) {
        if (from != i && computers[from][i] == 1 && visited[i] == 0) {
            visited[i] = 1;
            DFS(i, n, visited, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {

    int network = 0;
    vector<int> visited(n, 0);

    for (int i = 0; i < n; i++) {
        if (visited[i] == 1) {
            continue;
        }

        // visit node and start DFS
        network++;
        visited[i] = 1;

        DFS(i, n, visited, computers);
    }

    return network;
}
#endif

#ifdef __MYSOL__
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int find(int u, vector<int>& nodes)
{
    if (u == nodes[u])
        return u;
    return nodes[u] = find(nodes[u], nodes);
}
void merge(int u, int v, vector<int>& nodes)
{
    u = find(u, nodes);
    v = find(v, nodes);
    if (u != v)
        nodes[u] = v;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int len = computers.size();
    vector<int> nodes(len);
    for (int i = 0; i < len; i++)
        nodes[i] = i;

    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {

            if (computers[i][j] == 1)
            {
                merge(i, j, nodes);
            }
        }
    }
    for (int i = 0; i < len; i++)
        find(i, nodes);
    unordered_set<int> ans;
    for (int i = 0; i < len; i++)
        ans.insert(nodes[i]);
    answer = ans.size();
    return answer;
}
#endif // __MYSOL__
