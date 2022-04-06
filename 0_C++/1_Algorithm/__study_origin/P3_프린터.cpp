/*
���� ����
�Ϲ����� �����ʹ� �μ� ��û�� ���� ������� �μ��մϴ�. �׷��� ������ �߿��� ������ ���߿� �μ�� �� �ֽ��ϴ�. �̷� ������ �����ϱ� ���� �߿䵵�� ���� ������ ���� �μ��ϴ� �����͸� �����߽��ϴ�. �� ���Ӱ� ������ �����ʹ� �Ʒ��� ���� ������� �μ� �۾��� �����մϴ�.

1. �μ� ������� ���� �տ� �ִ� ����(J)�� ����Ͽ��� �����ϴ�.
2. ������ �μ� ����Ͽ��� J���� �߿䵵�� ���� ������ �� ���� �����ϸ� J�� ������� ���� �������� �ֽ��ϴ�.
3. �׷��� ������ J�� �μ��մϴ�.
���� ���, 4���� ����(A, B, C, D)�� ������� �μ� ����Ͽ� �ְ� �߿䵵�� 2 1 3 2 ��� C D A B ������ �μ��ϰ� �˴ϴ�.

���� �μ⸦ ��û�� ������ �� ��°�� �μ�Ǵ��� �˰� �ͽ��ϴ�. ���� ������ C�� 1��°��, A�� 3��°�� �μ�˴ϴ�.

���� ����Ͽ� �ִ� ������ �߿䵵�� ������� ��� �迭 priorities�� ���� �μ⸦ ��û�� ������ ���� ������� � ��ġ�� �ִ����� �˷��ִ� location�� �Ű������� �־��� ��, ���� �μ⸦ ��û�� ������ �� ��°�� �μ�Ǵ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
���� ����Ͽ��� 1�� �̻� 100�� ������ ������ �ֽ��ϴ�.
�μ� �۾��� �߿䵵�� 1~9�� ǥ���ϸ� ���ڰ� Ŭ���� �߿��ϴٴ� ���Դϴ�.
location�� 0 �̻� (���� ����Ͽ� �ִ� �۾� �� - 1) ������ ���� ������ ������� ���� �տ� ������ 0, �� ��°�� ������ 1�� ǥ���մϴ�.
����� ��
priorities	location	return
[2, 1, 3, 2]	2	1
[1, 1, 9, 1, 1, 1]	0	5
����� �� ����
���� #1

������ ���� ���� �����ϴ�.

���� #2

6���� ����(A, B, C, D, E, F)�� �μ� ����Ͽ� �ְ� �߿䵵�� 1 1 9 1 1 1 �̹Ƿ� C D E F A B ������ �μ��մϴ�.
*/
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <stack>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = -1;
    map<int, int> priorityMap;
    stack<int> priority;
    queue<pair<int,int>> printQueue;

    for (int i = 0; i < priorities.size(); i++)
    {
        priorityMap[priorities[i]] += 1;
        printQueue.push(make_pair(i,priorities[i]));
    }
    for (auto &k : priorityMap)
    {
        priority.push(k.first);
        while (k.second > 1)
        {
            k.second -= 1;
            priority.push(k.first);
        }
    }
    int cnt = 0;
    while (1)
    {
        if (priority.top() == printQueue.front().second)
        {
            answer = printQueue.front().first;
            priority.pop();
            printQueue.pop();
            cnt++;
        }
        else
        {
            printQueue.push(printQueue.front());
            printQueue.pop();
        }
        if (answer == location)
            return cnt;
    }
    return answer;
}
int main()
{
    vector<int> input = {1, 1, 9, 1, 1, 1};
    int loc = 0;
    cout<<solution(input, loc)<<endl;
    return 0;
}