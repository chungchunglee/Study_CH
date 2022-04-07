/*https://programmers.co.kr/learn/courses/30/lessons/42884
* �ܼ�ī�޶�
���� ����
��ӵ��θ� �̵��ϴ� ��� ������ ��ӵ��θ� �̿��ϸ鼭 �ܼӿ� ī�޶� �� ���� �������� ī�޶� ��ġ�Ϸ��� �մϴ�.

��ӵ��θ� �̵��ϴ� ������ ��� routes�� �Ű������� �־��� ��, ��� ������ �� ���� �ܼӿ� ī�޶� �������� �Ϸ��� �ּ� �� ���� ī�޶� ��ġ�ؾ� �ϴ����� return �ϵ��� solution �Լ��� �ϼ��ϼ���.

���ѻ���

������ ����� 1�� �̻� 10,000�� �����Դϴ�.
routes���� ������ �̵� ��ΰ� ���ԵǾ� ������ routes[i][0]���� i��° ������ ��ӵ��ο� ������ ����, routes[i][1]���� i��° ������ ��ӵ��ο��� ���� ������ ���� �ֽ��ϴ�.
������ ����/���� ������ ī�޶� ��ġ�Ǿ� �־ ī�޶� ���������� �����մϴ�.
������ ���� ����, ���� ������ -30,000 �̻� 30,000 �����Դϴ�.
����� ��

routes	return
[[-20,-15], [-14,-5], [-18,-13], [-5,-3]]	2
����� �� ����

-5 ������ ī�޶� ��ġ�ϸ� �� ��°, �� ��° ������ ī�޶� �����ϴ�.

-15 ������ ī�޶� ��ġ�ϸ� ù ��°, �� ��° ������ ī�޶� �����ϴ�.
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool comp_routes(vector<int> a, vector<int> b)
{
    return a[1] < b[1];
}
int solution(vector<vector<int>> routes) {
    int answer = 0, flag = -30001;
    int len = routes.size();
    sort(routes.begin(), routes.end(), comp_routes);
    for (int i = 0; i < len; i++)
    {
        if (flag < routes[i][0])
        {
            flag = routes[i][1];
            answer++;
        }
    }
    return answer;
}
int main()
{
    int a = solution({{-20, -15}, { -14, -5}, { -18, -13}, { -5, -3}});
    return 0;
}
#ifdef __OTHERS__
int solution(vector<vector<int>> routes) {
    int answer = 0, flag = 30001;
    int len = routes.size();
    vector<int> solved_routes(len, 0);
    sort(routes.rbegin(), routes.rend());
    for (int i = 0; i < len; i++)
    {
        if (flag > routes[i][1])
        {
            flag = routes[i][0];
            answer++;
        }
    }
    return answer;
}

#endif // __OTHERS__
