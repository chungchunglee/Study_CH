/*https://programmers.co.kr/learn/courses/30/lessons/43105
* ���� �ﰢ��
���� ����
��ũ���� 2018-09-14 ���� 5.44.19.png

���� ���� �ﰢ���� ����⿡�� �ٴڱ��� �̾����� ��� ��, ���İ� ������ ���� ���� ū ��츦 ã�ƺ����� �մϴ�. �Ʒ� ĭ���� �̵��� ���� �밢�� �������� �� ĭ ������ �Ǵ� �������θ� �̵� �����մϴ�. ���� ��� 3������ �� �Ʒ�ĭ�� 8 �Ǵ� 1�θ� �̵��� �����մϴ�.

�ﰢ���� ������ ��� �迭 triangle�� �Ű������� �־��� ��, ���İ� ������ �ִ��� return �ϵ��� solution �Լ��� �ϼ��ϼ���.

���ѻ���
�ﰢ���� ���̴� 1 �̻� 500 �����Դϴ�.
�ﰢ���� �̷�� �ִ� ���ڴ� 0 �̻� 9,999 ������ �����Դϴ�.
����� ��
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
