/*https://programmers.co.kr/learn/courses/30/lessons/42747
H-Index
���� ����
H-Index�� �������� ���꼺�� ������� ��Ÿ���� ��ǥ�Դϴ�. ��� �������� H-Index�� ��Ÿ���� ���� h�� ���Ϸ��� �մϴ�. ��Ű���1�� ������, H-Index�� ������ ���� ���մϴ�.

� �����ڰ� ��ǥ�� �� n�� ��, h�� �̻� �ο�� ���� h�� �̻��̰� ������ ���� h�� ���� �ο�Ǿ��ٸ� h�� �ִ��� �� �������� H-Index�Դϴ�.

� �����ڰ� ��ǥ�� ���� �ο� Ƚ���� ���� �迭 citations�� �Ű������� �־��� ��, �� �������� H-Index�� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
�����ڰ� ��ǥ�� ���� ���� 1�� �̻� 1,000�� �����Դϴ�.
���� �ο� Ƚ���� 0ȸ �̻� 10,000ȸ �����Դϴ�.
����� ��
citations	return
[3, 0, 6, 1, 5]	3
����� �� ����
�� �����ڰ� ��ǥ�� ���� ���� 5���̰�, ���� 3���� ���� 3ȸ �̻� �ο�Ǿ����ϴ�. �׸��� ������ 2���� ���� 3ȸ ���� �ο�Ǿ��� ������ �� �������� H-Index�� 3�Դϴ�.

�� ���� - 2019�� 2�� 28�� �׽�Ʈ ���̽��� �߰��Ǿ����ϴ�.*/
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    map <int, int, greater<int>> sorted_ciat;
    int val = 0;

    for (int i = 0; i < citations.size(); i++)
    {
        sorted_ciat[citations[i]] += 1;
    }

    for (int i = sorted_ciat.begin()->first; i >= 0; i--)
    {
        int h = i;
        if (sorted_ciat[i] == NULL)
            val += 0;
        else 
            val += sorted_ciat[i];
        if (h <= val && h >= (citations.size() - val))
            return h;
    }
    return answer;
}
int main()
{
    cout<<solution({ 3,0,6,1,5 });
}