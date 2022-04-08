/*https://programmers.co.kr/learn/courses/30/lessons/42898
���
���� ����
��ӵǴ� ����� �Ϻ� ������ ���� �����ϴ�. ���� ����� ���� ������ ���� �б��� ������ �մϴ�. ������ �б����� ���� ���� m x n ũ���� ���ڸ������ ��Ÿ�� �� �ֽ��ϴ�.

�Ʒ� �׸��� m = 4, n = 3 �� ����Դϴ�.

image0.png

���� ���� ��, �� ���� �ִ� ���� ��ǥ�� (1, 1)�� ��Ÿ���� ���� ������ �Ʒ�, �� �б��� �ִ� ���� ��ǥ�� (m, n)���� ��Ÿ���ϴ�.

������ ũ�� m, n�� ���� ��� ������ ��ǥ�� ���� 2���� �迭 puddles�� �Ű������� �־����ϴ�. 
�����ʰ� �Ʒ������θ� ������ ������ �б����� �� �� �ִ� �ִܰ���� ������ 1,000,000,007�� ���� �������� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
������ ũ�� m, n�� 1 �̻� 100 ������ �ڿ����Դϴ�.
m�� n�� ��� 1�� ���� �Է����� �־����� �ʽ��ϴ�.
���� ��� ������ 0�� �̻� 10�� �����Դϴ�.
���� �б��� ���� ��� ���� �Է����� �־����� �ʽ��ϴ�.
����� ��
m	n	puddles	return
4	3	[[2, 2]]	4
����� �� ����
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