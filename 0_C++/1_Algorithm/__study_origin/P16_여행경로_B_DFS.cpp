/*
https://programmers.co.kr/learn/courses/30/lessons/43164
������
���� ����
�־��� �װ����� ��� �̿��Ͽ� �����θ� ¥���� �մϴ�. �׻� "ICN" ���׿��� ����մϴ�.

�װ��� ������ ��� 2���� �迭 tickets�� �Ű������� �־��� ��, �湮�ϴ� ���� ��θ� �迭�� ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
��� ������ ���ĺ� �빮�� 3���ڷ� �̷�����ϴ�.
�־��� ���� ���� 3�� �̻� 10,000�� �����Դϴ�.
tickets�� �� �� [a, b]�� a ���׿��� b �������� ���� �װ����� �ִٴ� �ǹ��Դϴ�.
�־��� �װ����� ��� ����ؾ� �մϴ�.
���� ������ ��ΰ� 2�� �̻��� ��� ���ĺ� ������ �ռ��� ��θ� return �մϴ�.
��� ���ø� �湮�� �� ���� ���� �־����� �ʽ��ϴ�.
����� ��
tickets	return
{{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}}	{"ICN", "JFK", "HND", "IAD"}
{{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL","SFO"}}	{"ICN", "ATL", "ICN", "SFO", "ATL", "SFO"}
����� �� ����
���� #1

["ICN", "JFK", "HND", "IAD"] ������ �湮�� �� �ֽ��ϴ�.

���� #2

["ICN", "SFO", "ATL", "ICN", "ATL", "SFO"] ������ �湮�� ���� ������ ["ICN", "ATL", "ICN", "SFO", "ATL", "SFO"] �� ���ĺ� ������ �ռ��ϴ�.
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int route[10000] = { 0, };
bool fin = false;

void DFS(vector<vector<string>>& tickets,vector<int>& visited, int from, int depth)
{
    route[depth-1] = from;
    if (tickets.size() == depth)
    {
        fin = true;
        return;
    }
    for (int i = 0; i < tickets.size(); i++)
    {
        if ((tickets[from][1] != tickets[i][0]) || (visited[i] == 1))
            continue;
        visited[i] = 1;
        DFS(tickets, visited, i, depth + 1);
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    answer.push_back("ICN");
    sort(tickets.begin(), tickets.end());

    for (int i = 0; i < tickets.size(); i++)
    {
        vector<int> visited(tickets.size());
        int depth = 0;
        if ("ICN" != tickets[i][0])
            continue;

        visited[i] = 1;
        DFS(tickets, visited, i, depth + 1);
        if (fin) 
            break;
    }
    for (int i = 0; i < tickets.size(); i++)
    {
        answer.push_back( tickets[route[i]][1]);
    }
    return answer;
}
int main()
{
    vector<string> s1;
    s1 = solution({ {"ICN", "SFO"}, { "ICN", "ATL" }, { "SFO", "ATL" }, { "ATL", "ICN" }, { "ATL","SFO" } });
    s1 = solution({{"ICN", "AOO"}, {"AOO", "BOO"}, {"BOO", "COO"}, {"COO", "DOO"}, {"DOO", "EOO"}, {"EOO", "DOO"}, {"DOO", "COO"}, {"COO", "BOO"}, {"BOO", "AOO"}});
    s1 = solution({ {"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"} });

    

}