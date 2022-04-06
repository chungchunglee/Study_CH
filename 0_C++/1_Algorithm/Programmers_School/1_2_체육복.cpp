/*
���� ����
���ɽð��� ������ ���, �Ϻ� �л��� ü������ �������߽��ϴ�. ������ ���� ü������ �ִ� �л��� �̵鿡�� ü������ �����ַ� �մϴ�.
�л����� ��ȣ�� ü�� ������ �Ű��� �־�, �ٷ� �չ�ȣ�� �л��̳� �ٷ� �޹�ȣ�� �л����Ը� ü������ ������ �� �ֽ��ϴ�.
���� ���, 4�� �л��� 3�� �л��̳� 5�� �л����Ը� ü������ ������ �� �ֽ��ϴ�. ü������ ������ ������ ���� �� ���� ������ ü������ ������ ���� 
�ִ��� ���� �л��� ü�������� ���� �մϴ�.

��ü �л��� �� n, ü������ �������� �л����� ��ȣ�� ��� �迭 lost, 
������ ü������ ������ �л����� ��ȣ�� ��� �迭 reserve�� �Ű������� �־��� ��, ü�������� ���� �� �ִ� �л��� �ִ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
��ü �л��� ���� 2�� �̻� 30�� �����Դϴ�.
ü������ �������� �л��� ���� 1�� �̻� n�� �����̰� �ߺ��Ǵ� ��ȣ�� �����ϴ�.
������ ü������ ������ �л��� ���� 1�� �̻� n�� �����̰� �ߺ��Ǵ� ��ȣ�� �����ϴ�.
���� ü������ �ִ� �л��� �ٸ� �л����� ü������ ������ �� �ֽ��ϴ�.
���� ü������ ������ �л��� ü������ ���������� �� �ֽ��ϴ�. �̶� �� �л��� ü������ �ϳ��� �������ߴٰ� �����ϸ�, 
���� ü������ �ϳ��̱⿡ �ٸ� �л����Դ� ü������ ������ �� �����ϴ�.
����� ��
n	lost	reserve	return
5	[2, 4]	[1, 3, 5]	5
5	[2, 4]	[3]	4
3	[3]	[1]	2
����� �� ����
���� #1
1�� �л��� 2�� �л����� ü������ �����ְ�, 3�� �л��̳� 5�� �л��� 4�� �л����� ü������ �����ָ� �л� 5���� ü�������� ���� �� �ֽ��ϴ�.

���� #2
3�� �л��� 2�� �л��̳� 4�� �л����� ü������ �����ָ� �л� 4���� ü�������� ���� �� �ֽ��ϴ�.

��ó

�� ���� - 2019�� 2�� 18�� ������ ������Ǿ����ϴ�.
�� ���� - 2019�� 2�� 27��, 28�� �׽�Ʈ���̽��� �߰��Ǿ����ϴ�.
�� ���� - 2021�� 7�� 28�� �׽�Ʈ���̽��� �߰��Ǿ����ϴ�.
�� ���� - 2021�� 8�� 30�� �׽�Ʈ���̽��� �߰��Ǿ����ϴ�.*/

#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    //�л���+2 ��ŭ �迭 ���� �� 1�� �ʱ�ȭ (0�� �ε����� n+2���ε����� ���� ���ǹ��� �迭 ���� ������ �Ѿ�� �ʱ� ���� ���)
    vector<int> students_status(n + 2, 1);
    //�Ҿ���� �л� �ݿ�
    for (auto l : lost)
        students_status[l]--;
    //�������� �л� �ݿ�
    for (auto r : reserve)
        students_status[r]++;
    //ü���� ������ �л� ��й�(0�� �ϰ�� �¿� Ž���Ͽ� 2���л����� �뿩)
    for (int i = 0; i < n; i++)
    {
        if (students_status[i] != 0)
            continue;
        if (students_status[i - 1] == 2)
        {
            students_status[i - 1]--;
            students_status[i]++;
        }
        else if (students_status[i + 1] == 2)
        {
            students_status[i + 1]--;
            students_status[i]++;
        }
    }
    //ü���� ������ �л�(1�� Ȥ�� 2��)��ŭ answer++
    for (auto s : students_status)
    {
        if (s > 0)
            answer++;
    }
    // 0��°�� n+1��°�� dummy data 1�� �������Ƿ� 2 ����
    return answer - 2;
}
void main()
{
    //5	[2, 4]	[1, 3, 5]	5
    int a = solution(5, { 1,3,5 }, { 2,4 });
    a = solution(5, { 2,4 }, { 1,3,5 });
    a = solution(5, { 2,4 }, { 1,3,5 });
}

#ifdef __FAILED__
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    //�л���+2 ��ŭ �迭 ���� �� 1�� �ʱ�ȭ
    vector<int> students_status(n, 1);
    //�Ҿ���� �л� �ݿ�
    for (auto l : lost)
        students_status[l-1]--;
    //�������� �л� �ݿ�
    for (auto r : reserve)
        students_status[r-1]++;
    for (int i = 0; i < n; i++)
    {
        if (students_status[i] != 0)
            continue;
        if (students_status[i - 1] == 2)
        {
            students_status[i - 1]--;
            students_status[i]++;
        }
        else if (students_status[i + 1] == 2)
        {
            students_status[i + 1]--;
            students_status[i]++;
        }
    }
    for (auto s : students_status)
    {
        if (s > 0)
            answer++;
    }

    return answer;
}
#endif // __FAILED__