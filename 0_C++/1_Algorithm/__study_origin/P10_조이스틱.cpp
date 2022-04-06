/*
https://programmers.co.kr/learn/courses/30/lessons/42860
���̽�ƽ
���� ����
���̽�ƽ���� ���ĺ� �̸��� �ϼ��ϼ���. �� ó���� A�θ� �̷���� �ֽ��ϴ�.
ex) �ϼ��ؾ� �ϴ� �̸��� �� ���ڸ� AAA, �� ���ڸ� AAAA

���̽�ƽ�� �� �������� �����̸� �Ʒ��� �����ϴ�.

�� - ���� ���ĺ�
�� - ���� ���ĺ� (A���� �Ʒ������� �̵��ϸ� Z��)
�� - Ŀ���� �������� �̵� (ù ��° ��ġ���� �������� �̵��ϸ� ������ ���ڿ� Ŀ��)
�� - Ŀ���� ���������� �̵� (������ ��ġ���� ���������� �̵��ϸ� ù ��° ���ڿ� Ŀ��)
���� ��� �Ʒ��� ������� "JAZ"�� ���� �� �ֽ��ϴ�.

- ù ��° ��ġ���� ���̽�ƽ�� ���� 9�� �����Ͽ� J�� �ϼ��մϴ�.
- ���̽�ƽ�� �������� 1�� �����Ͽ� Ŀ���� ������ ���� ��ġ�� �̵���ŵ�ϴ�.
- ������ ��ġ���� ���̽�ƽ�� �Ʒ��� 1�� �����Ͽ� Z�� �ϼ��մϴ�.
���� 11�� �̵����� "JAZ"�� ���� �� �ְ�, �̶��� �ּ� �̵��Դϴ�.
������� �ϴ� �̸� name�� �Ű������� �־��� ��, 
�̸��� ���� ���̽�ƽ ���� Ƚ���� �ּڰ��� return �ϵ��� solution �Լ��� ���弼��.

���� ����
name�� ���ĺ� �빮�ڷθ� �̷���� �ֽ��ϴ�.
name�� ���̴� 1 �̻� 20 �����Դϴ�.
����� ��
name	return
"JEROEN"	56
"JAN"	23
��ó
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;



int solution(string name) {
    int answer = 0;
    vector<int> non_A_index;
    int len = name.size();

    for (int i = 0; i < len; i++)
    {
        answer += (int)(name[i] - 'A' < 'Z' - name[i] + 1) ? name[i] - 'A' : 'Z' - name[i] + 1;
        if (name[i] != 'A')
            non_A_index.push_back(i);
    }
    //���� ó�� 1 - �ٲ��ʿ���� ���
    if (!non_A_index.size())
        return answer;
    int next = 1;
    //�ʱ갪 ���� - min��
    int min_val = min(non_A_index.back(),len - non_A_index.front());

    for (int i = 0; i < non_A_index.size() - 1; i++)
    {
        min_val = min(min_val, non_A_index[i] + len - non_A_index[i + 1] + min(non_A_index[i], len - non_A_index[i + 1]));
    }
    answer += min_val;
    return answer;
}
int main()
{
    int a_b = solution("AABAAAAAAAB");
    a_b = solution("AAAAAAAA");
    a_b = solution("ABBBBAAAAABAAA");
    a_b = solution("ABBBBAAAAABAAA");
    return 0;
}

#ifdef __OTHERS__
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    for (auto ch : name) answer += min(ch - 'A', 91 - ch);

    int len = name.length();
    int move = len - 1;
    int next;
    for (int i = 0; i < len; i++) 
    {
        next = i + 1;
        while (next < len && name[next] == 'A') next++;
        move = min(move, i + (len - next) + min(i, len - next));
    }
    answer += move;

    return answer;
}

#endif // __OTHERS__
