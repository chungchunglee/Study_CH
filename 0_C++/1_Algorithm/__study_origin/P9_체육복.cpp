/*
https://programmers.co.kr/learn/courses/30/lessons/42862
ü����
���� ����
���ɽð��� ������ ���, �Ϻ� �л��� ü������ �������߽��ϴ�. ������ ���� ü������ �ִ� �л��� �̵鿡�� ü������ �����ַ� �մϴ�.
�л����� ��ȣ�� ü�� ������ �Ű��� �־�, �ٷ� �չ�ȣ�� �л��̳� �ٷ� �޹�ȣ�� �л����Ը� ü������ ������ �� �ֽ��ϴ�.
���� ���, 4�� �л��� 3�� �л��̳� 5�� �л����Ը� ü������ ������ �� �ֽ��ϴ�. 
ü������ ������ ������ ���� �� ���� ������ ü������ ������ ���� �ִ��� ���� �л��� ü�������� ���� �մϴ�.

��ü �л��� �� n, ü������ �������� �л����� ��ȣ�� ��� �迭 lost, ������ ü������ ������ �л����� ��ȣ�� ��� �迭 reserve�� �Ű������� �־��� ��,
ü�������� ���� �� �ִ� �л��� �ִ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
��ü �л��� ���� 2�� �̻� 30�� �����Դϴ�.
ü������ �������� �л��� ���� 1�� �̻� n�� �����̰� �ߺ��Ǵ� ��ȣ�� �����ϴ�.
������ ü������ ������ �л��� ���� 1�� �̻� n�� �����̰� �ߺ��Ǵ� ��ȣ�� �����ϴ�.
���� ü������ �ִ� �л��� �ٸ� �л����� ü������ ������ �� �ֽ��ϴ�.
���� ü������ ������ �л��� ü������ ���������� �� �ֽ��ϴ�.
�̶� �� �л��� ü������ �ϳ��� �������ߴٰ� �����ϸ�, ���� ü������ �ϳ��̱⿡ �ٸ� �л����Դ� ü������ ������ �� �����ϴ�.
����� ��
n	lost	reserve	return
5	[2, 4]	[1, 3, 5]	5
5	[2, 4]	[3]	4
3	[3]	[1]	2
����� �� ����
���� #1
1�� �л��� 2�� �л����� ü������ �����ְ�, 3�� �л��̳� 5�� �л��� 4�� �л����� ü������ �����ָ� �л� 5���� ü�������� ���� �� �ֽ��ϴ�.

���� #2
3�� �л��� 2�� �л��̳� 4�� �л����� ü������ �����ָ� �л� 4���� ü�������� ���� �� �ֽ��ϴ�
*/
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    //���� �л� ��Ȳ �ֽ�ȭ
    vector<int> students(n, 1);
    for (int i = 0; i < (int)lost.size(); i++)
        students[lost[i]-1]--;
    for (int i = 0; i < (int)reserve.size(); i++)
        students[reserve[i]-1]++;
    
    for (int i = 0; i < (int)students.size(); i++)
    {
        if (students[i] != 2)
            continue;
        if (i == 0)
        {
            if (students[i + 1] == 0)
            {
                students[i]--;
                students[i + 1]++;
            }
        }
        else if (i == (int)students.size() - 1)
        {
            if (students[i - 1] == 0)
            {
                students[i]--;
                students[i - 1]++;
            }
        }
        else
        {
            if (students[i - 1] == 0)
            {
                students[i]--; 
                students[i - 1]++;
            }
            else if (students[i + 1] == 0)
            {
                students[i]--;
                students[i + 1]++;
            }
        }
    }
    for (auto k : students)
    {
        if (k >= 1)
            answer++;
    }

    return answer;
}
int main()
{
    vector<int> a1 = { 2,4 };
    vector<int> a2 = { 1,3,5 };
    int a = solution(5, a1, a2);
    ;
    return 0;
}

#ifdef __OTHERS__
#include <string>
#include <vector>

using namespace std;
int student[35];
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    for (int i : reserve) student[i] += 1;
    for (int i : lost) student[i] += -1;
    for (int i = 1; i <= n; i++) {
        if (student[i] == -1) {
            if (student[i - 1] == 1)
                student[i - 1] = student[i] = 0;
            else if (student[i + 1] == 1)
                student[i] = student[i + 1] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
        if (student[i] != -1) answer++;

    return answer;
}

#endif // __OTHERS__
