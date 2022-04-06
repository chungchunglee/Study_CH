//https://programmers.co.kr/learn/courses/30/lessons/42626
/*
* ���� ����
�ſ� ���� �����ϴ� Leo�� ��� ������ ���ں� ������ K �̻����� ����� �ͽ��ϴ�. 
��� ������ ���ں� ������ K �̻����� ����� ���� Leo�� ���ں� ������ ���� ���� �� ���� ������ �Ʒ��� ���� Ư���� ������� ���� ���ο� ������ ����ϴ�.

���� ������ ���ں� ���� = ���� ���� ���� ������ ���ں� ���� + (�� ��°�� ���� ���� ������ ���ں� ���� * 2)
Leo�� ��� ������ ���ں� ������ K �̻��� �� ������ �ݺ��Ͽ� �����ϴ�.
Leo�� ���� ������ ���ں� ������ ���� �迭 scoville�� ���ϴ� ���ں� ���� K�� �־��� ��, 
��� ������ ���ں� ������ K �̻����� ����� ���� ����� �ϴ� �ּ� Ƚ���� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���� ����
scoville�� ���̴� 2 �̻� 1,000,000 �����Դϴ�.
K�� 0 �̻� 1,000,000,000 �����Դϴ�.
scoville�� ���Ҵ� ���� 0 �̻� 1,000,000 �����Դϴ�.
��� ������ ���ں� ������ K �̻����� ���� �� ���� ��쿡�� -1�� return �մϴ�.
����� ��
scoville	K	return
[1, 2, 3, 9, 10, 12]	7	2
����� �� ����
���ں� ������ 1�� ���İ� 2�� ������ ������ ������ ���ں� ������ �Ʒ��� ���� �˴ϴ�.
���ο� ������ ���ں� ���� = 1 + (2 * 2) = 5
���� ������ ���ں� ���� = [5, 3, 9, 10, 12]

���ں� ������ 3�� ���İ� 5�� ������ ������ ������ ���ں� ������ �Ʒ��� ���� �˴ϴ�.
���ο� ������ ���ں� ���� = 3 + (5 * 2) = 13
���� ������ ���ں� ���� = [13, 9, 10, 12]

��� ������ ���ں� ������ 7 �̻��� �Ǿ��� �̶� ���� Ƚ���� 2ȸ�Դϴ�.
*/
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int mixed_val = 0;
    priority_queue <int> food_list;

    for (int i = 0; i<int(scoville.size()); i++)
        food_list.push(-1 * scoville[i]);
    while ((food_list.top() * -1) <= K)
    {
        if ((food_list.size() == 1) && ((food_list.top() * -1) < K))
            return -1;
        answer++;
        mixed_val = food_list.top();
        food_list.pop();
        mixed_val += 2*(food_list.top()) ;
        food_list.pop();
        food_list.push(mixed_val);
    }
    return answer;
}
/*
int solution(vector<int> scoville, int K) {
    int answer = 0;
    sort(scoville.begin(), scoville.end());
    vector<int> scovile_check;


    while (scoville[answer] < K)
    {
        scoville[answer + 1] = scoville[answer] + scoville[answer + 1] * 2;
        answer++;
        if (answer == scoville.size() && scoville[answer] < K)
            return -1;

        sort(scoville.begin() + answer, scoville.end());
    }
    return answer;
}
*/
