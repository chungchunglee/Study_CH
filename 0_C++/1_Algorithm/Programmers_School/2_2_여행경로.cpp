/*
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
[["ICN", "JFK"], ["HND", "IAD"], ["JFK", "HND"]]	["ICN", "JFK", "HND", "IAD"]
[["ICN", "SFO"], ["ICN", "ATL"], ["SFO", "ATL"], ["ATL", "ICN"], ["ATL","SFO"]]	["ICN", "ATL", "ICN", "SFO", "ATL", "SFO"]
����� �� ����
���� #1

["ICN", "JFK", "HND", "IAD"] ������ �湮�� �� �ֽ��ϴ�.

���� #2

["ICN", "SFO", "ATL", "ICN", "ATL", "SFO"] ������ �湮�� ���� ������ ["ICN", "ATL", "ICN", "SFO", "ATL", "SFO"] �� ���ĺ� ������ �ռ��ϴ�.
*/
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    sort(tickets.begin(), tickets.end(),greater<vector<string>>());
    unordered_map<string, vector<string>> routes;
    for (auto t : tickets)
    {
        routes[t[0]].push_back(t[1]);
    }
    vector<string> s;
    s.push_back("ICN");
    while (!s.empty())
    {
        string airport = s.back();
        if (routes.find(airport) == routes.end() || routes[airport].size() == 0)
        {
            answer.push_back(airport);
            s.pop_back();
        }
        else
        {
            s.push_back(routes[airport].back());
            routes[airport].pop_back();
        }
    }
    reverse(answer.begin(), answer.end());

    return answer;
}
int main()
{
    vector<string> s1;
    s1 = solution({ {"A", "B"}, { "B", "D" }, { "D", "A" }, { "D", "C" }, { "E","D" }, { "C","E" } });
    s1 = solution({ {"ICN", "SFO"}, { "ICN", "ATL" }, { "SFO", "ATL" }, { "ATL", "ICN" }, { "ATL","SFO" } });
    s1 = solution({ {"ICN", "AOO"}, {"AOO", "BOO"}, {"BOO", "COO"}, {"COO", "DOO"}, {"DOO", "EOO"}, {"EOO", "DOO"}, {"DOO", "COO"}, {"COO", "BOO"}, {"BOO", "AOO"} });
    s1 = solution({ {"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"} });



}