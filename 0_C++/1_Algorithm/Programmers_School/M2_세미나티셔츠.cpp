/*
���� ����
�ִ��� ���� ���̳� �����ڿ��� Ƽ������ �����ַ� �մϴ�. Ƽ������ �����ִ� ������ ������ �����ϴ�.

�� ����� Ƽ������ �ִ� �ϳ��� �ݴϴ�.
��� �����ڴ� �ڽ��� ���� ũ��� ���ų� ū Ƽ������ �޽��ϴ�.
���� ��� ũ�Ⱑ [1, 2, 3] �� Ƽ������ �ְ�, ���� ���� ũ�Ⱑ [2, 3, 4]�� ������ ���� �ֽ��ϴ�. 
ù ��° ������� �� ��° Ƽ������, �� ��° ������� �� ��° Ƽ������ ������ �� �ֽ��ϴ�. ũ�Ⱑ 4�� �����ڴ� Ƽ������ ���� ���մϴ�. ���� �ִ� 2���� Ƽ������ �� �� �ֽ��ϴ�.

�����ں� ���� ũ�� people�� ���̳� ���� ���� ���� Ƽ���� ũ�� tshirts�� �Ű������� �־��� ��, �ִ� �� ���� Ƽ������ ���� �� �� �ִ��� return �ϵ��� solution �Լ��� �ۼ��ϼ���.

���� ����
���̳��� ������ ��� ���� 2�� �̻� 5,000�� �����Դϴ�.
���� ���� Ƽ������ 2�� �̻� 5,000�� ���Ϸ� �غ��߽��ϴ�.
�������� ���� ũ��� �غ��� Ƽ���� ũ��� 1 �̻� 1,000 ������ �����Դϴ�.
����� ����
people	tshirts	result
[2, 3]	[1, 2, 3]	2
[1, 2, 3]	[1, 1]	1
����� ���� ����
����� �� #1
ù ��° ������� �� ��° Ƽ������, �� ��° ������� �� ��° Ƽ������ �ָ� �ִ� 2���� Ƽ������ �� �� �ֽ��ϴ�.

����� �� #2

ù ��° ������Ը� Ƽ������ �� �� �ֽ��ϴ�.
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, vector<int> tshirts) {
    int answer = 0;
    int index = 0;
    //������������ ���� 
    sort(people.begin(), people.end());
    sort(tshirts.begin(), tshirts.end());
    //�ε����� �������� tshirts �й�
    for (int i = 0; i < people.size(); i++)
    {
        for (int j = index; j < tshirts.size(); j++)
        {
            if (people[i] <= tshirts[j])
            {
                answer++;
                index = j + 1;
                break;
            }
        }
    }
    return answer;
}
/*
int solution(vector<int> people, vector<int> tshirts) {
    int answer = 0;
    unordered_map<int, int> people_m, tshirts_m;
    for (auto p : people)
        people_m[p]++;
    for (auto t : tshirts)
        tshirts_m[t]++;
    for (int i = 0; i < people.size(); i++)
    {
        for(auto t:tshirts_m)
            if (t.second>0 && (people[i] <= t.first))
            {
                t.second--;
                answer++;
                break;
            }
    }

    return answer;
}
*/