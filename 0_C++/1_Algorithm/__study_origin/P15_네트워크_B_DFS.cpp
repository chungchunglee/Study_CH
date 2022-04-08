/*https://programmers.co.kr/learn/courses/30/lessons/43162?language=cpp
네트워크
문제 설명
네트워크란 컴퓨터 상호 간에 정보를 교환할 수 있도록 연결된 형태를 의미합니다. 예를 들어, 컴퓨터 A와 컴퓨터 B가 직접적으로 연결되어있고, 컴퓨터 B와 컴퓨터 C가 직접적으로 연결되어 있을 때 컴퓨터 A와 컴퓨터 C도 간접적으로 연결되어 정보를 교환할 수 있습니다. 따라서 컴퓨터 A, B, C는 모두 같은 네트워크 상에 있다고 할 수 있습니다.

컴퓨터의 개수 n, 연결에 대한 정보가 담긴 2차원 배열 computers가 매개변수로 주어질 때, 네트워크의 개수를 return 하도록 solution 함수를 작성하시오.

제한사항
컴퓨터의 개수 n은 1 이상 200 이하인 자연수입니다.
각 컴퓨터는 0부터 n-1인 정수로 표현합니다.
i번 컴퓨터와 j번 컴퓨터가 연결되어 있으면 computers[i][j]를 1로 표현합니다.
computer[i][i]는 항상 1입니다.
입출력 예
n	computers	return
3	{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}	2
3	{{1, 1, 0}, {1, 1, 1}, {0, 1, 1}}	1
입출력 예 설명
예제 #1
아래와 같이 2개의 네트워크가 있습니다.
image0.png

예제 #2
아래와 같이 1개의 네트워크가 있습니다.
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
