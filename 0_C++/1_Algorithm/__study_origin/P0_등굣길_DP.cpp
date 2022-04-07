/*https://programmers.co.kr/learn/courses/30/lessons/42898
등굣길
문제 설명
계속되는 폭우로 일부 지역이 물에 잠겼습니다. 물에 잠기지 않은 지역을 통해 학교를 가려고 합니다. 집에서 학교까지 가는 길은 m x n 크기의 격자모양으로 나타낼 수 있습니다.

아래 그림은 m = 4, n = 3 인 경우입니다.

image0.png

가장 왼쪽 위, 즉 집이 있는 곳의 좌표는 (1, 1)로 나타내고 가장 오른쪽 아래, 즉 학교가 있는 곳의 좌표는 (m, n)으로 나타냅니다.

격자의 크기 m, n과 물이 잠긴 지역의 좌표를 담은 2차원 배열 puddles이 매개변수로 주어집니다. 
오른쪽과 아래쪽으로만 움직여 집에서 학교까지 갈 수 있는 최단경로의 개수를 1,000,000,007로 나눈 나머지를 return 하도록 solution 함수를 작성해주세요.

제한사항
격자의 크기 m, n은 1 이상 100 이하인 자연수입니다.
m과 n이 모두 1인 경우는 입력으로 주어지지 않습니다.
물에 잠긴 지역은 0개 이상 10개 이하입니다.
집과 학교가 물에 잠긴 경우는 입력으로 주어지지 않습니다.
입출력 예
m	n	puddles	return
4	3	[[2, 2]]	4
입출력 예 설명
image1.png
*/
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> map_v(m, vector<int>(n, 1));
    for (auto p : puddles)
    {
        int u = p[0] - 1, v = p[1] - 1;
        map_v[u][v] = 0;
        if (u == 0)
        {
            for (int i = v; i < n; i++)
                map_v[0][i] = 0;
        }
        if (v == 0)
        {
            for (int i = u; i < m; i++)
                map_v[i][0] = 0;
        }
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (map_v[i][j] == 0)
                continue;
            map_v[i][j] = (map_v[i][j - 1] % 1000000007 + map_v[i - 1][j] % 1000000007) % 1000000007;
        }
    }
    answer = map_v.back().back();
    return answer;
}
int main()
{
    int s1 = solution(4, 3, { {2,2} });
    s1 = solution(1, 3, { {1, 2} });
    s1 = solution(3, 1, { {2, 1} });
    s1 = solution(2, 2, { {2, 1}, { 1, 2} });
}