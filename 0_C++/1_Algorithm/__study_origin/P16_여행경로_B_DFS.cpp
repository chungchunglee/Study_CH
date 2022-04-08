/*
https://programmers.co.kr/learn/courses/30/lessons/43164
여행경로
문제 설명
주어진 항공권을 모두 이용하여 여행경로를 짜려고 합니다. 항상 "ICN" 공항에서 출발합니다.

항공권 정보가 담긴 2차원 배열 tickets가 매개변수로 주어질 때, 방문하는 공항 경로를 배열에 담아 return 하도록 solution 함수를 작성해주세요.

제한사항
모든 공항은 알파벳 대문자 3글자로 이루어집니다.
주어진 공항 수는 3개 이상 10,000개 이하입니다.
tickets의 각 행 [a, b]는 a 공항에서 b 공항으로 가는 항공권이 있다는 의미입니다.
주어진 항공권은 모두 사용해야 합니다.
만일 가능한 경로가 2개 이상일 경우 알파벳 순서가 앞서는 경로를 return 합니다.
모든 도시를 방문할 수 없는 경우는 주어지지 않습니다.
입출력 예
tickets	return
{{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}}	{"ICN", "JFK", "HND", "IAD"}
{{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL","SFO"}}	{"ICN", "ATL", "ICN", "SFO", "ATL", "SFO"}
입출력 예 설명
예제 #1

["ICN", "JFK", "HND", "IAD"] 순으로 방문할 수 있습니다.

예제 #2

["ICN", "SFO", "ATL", "ICN", "ATL", "SFO"] 순으로 방문할 수도 있지만 ["ICN", "ATL", "ICN", "SFO", "ATL", "SFO"] 가 알파벳 순으로 앞섭니다.
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