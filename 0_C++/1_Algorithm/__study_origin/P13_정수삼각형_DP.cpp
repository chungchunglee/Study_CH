/*https://programmers.co.kr/learn/courses/30/lessons/43105
* 정수 삼각형
문제 설명
스크린샷 2018-09-14 오후 5.44.19.png

위와 같은 삼각형의 꼭대기에서 바닥까지 이어지는 경로 중, 거쳐간 숫자의 합이 가장 큰 경우를 찾아보려고 합니다. 아래 칸으로 이동할 때는 대각선 방향으로 한 칸 오른쪽 또는 왼쪽으로만 이동 가능합니다. 예를 들어 3에서는 그 아래칸의 8 또는 1로만 이동이 가능합니다.

삼각형의 정보가 담긴 배열 triangle이 매개변수로 주어질 때, 거쳐간 숫자의 최댓값을 return 하도록 solution 함수를 완성하세요.

제한사항
삼각형의 높이는 1 이상 500 이하입니다.
삼각형을 이루고 있는 숫자는 0 이상 9,999 이하의 정수입니다.
입출력 예
triangle	result
[[7], [3, 8], [8, 1, 0], [2, 7, 4, 4], [4, 5, 2, 6, 5]]	30
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int len = triangle.size();
    vector<vector<int>> r_t(triangle.rbegin(), triangle.rend());
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < r_t[i].size() - 1; j++)
        {
            if (r_t[i][j] > r_t[i][j + 1])
                r_t[i + 1][j] += r_t[i][j];
            else
                r_t[i + 1][j] += r_t[i][j + 1];
        }
    }
    return r_t[len - 1][0];
}
int main()
{
    int s1 = solution({ {7}, { 3, 8}, { 8, 1, 0}, { 2, 7, 4, 4}, { 4, 5, 2, 6, 5} });
}
#ifdef __OTHERS__
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int len = triangle.size();
    vector<vector<int>> added_triangle(triangle.begin(), triangle.end());
    for (int i = 1; i < len; i++)
    {
        int temp_len = triangle[i].size();
        added_triangle[i][0] += added_triangle[i - 1][0];
        added_triangle[i][temp_len - 1] += added_triangle[i - 1][temp_len - 2];
        for (int j = 1; j < temp_len - 1; j++)
        {
            added_triangle[i][j] += max(added_triangle[i - 1][j - 1], added_triangle[i - 1][j]);
        }
    }
    answer = *max_element(added_triangle[len - 1].begin(), added_triangle[len - 1].end());
    return answer;
}


#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> t) {
    int answer = 0;

    for (int i = t.size() - 1; i > 0; i--)
    {
        for (int j = 0; j < t[i].size() - 1; j++)
        {
            if (t[i][j] > t[i][j + 1])
            {
                t[i - 1][j] += t[i][j];
            }
            else
            {
                t[i - 1][j] += t[i][j + 1];
            }
        }
    }

    answer = t[0][0];

    return answer;
}
#endif // __OTHERS__
