/*https://programmers.co.kr/learn/courses/30/lessons/42840
* ���ǰ��
���� ����
�����ڴ� ������ ������ ����� �ظ��Դϴ�. ������ ���ι��� ���ǰ�翡 ���� ������ ���� ������ �մϴ�. �����ڴ� 1�� �������� ������ �������� ������ ���� ����ϴ�.

1�� �����ڰ� ��� ���: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...
2�� �����ڰ� ��� ���: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
3�� �����ڰ� ��� ���: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...

1�� �������� ������ ���������� ������ ������� ���� �迭 answers�� �־����� ��, ���� ���� ������ ���� ����� �������� �迭�� ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���� ����
������ �ִ� 10,000 ������ �����Ǿ��ֽ��ϴ�.
������ ������ 1, 2, 3, 4, 5�� �ϳ��Դϴ�.
���� ���� ������ ���� ����� ������ ���, return�ϴ� ���� �������� �������ּ���.
����� ��
answers	return
[1,2,3,4,5]	[1]
[1,3,2,4,2]	[1,2,3]
����� �� ����
����� �� #1

������ 1�� ��� ������ �������ϴ�.
������ 2�� ��� ������ Ʋ�Ƚ��ϴ�.
������ 3�� ��� ������ Ʋ�Ƚ��ϴ�.
���� ���� ������ ���� ���� ����� ������ 1�Դϴ�.

����� �� #2

��� ����� 2�������� ������ϴ�.
* 
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> one = { 1,2,3,4,5 };
vector<int> two = { 2,1,2,3,2,4,2,5 };
vector<int> three = { 3,3,1,1,2,2,4,4,5,5 };

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> grade(3);

    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == one[i % one.size()]) grade[0]++;
        if (answers[i] == two[i % two.size()]) grade[1]++;
        if (answers[i] == three[i % three.size()]) grade[2]++;
    }
        int max_g = *max_element(grade.begin(), grade.end());

        for (int i = 0 ; i < grade.size() ; i++)
            if (grade[i] == max_g) answer.push_back(i + 1);
        return answer;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int acnt = 0, bcnt = 0, ccnt = 0;
    int a[5] = { 1,2,3,4,5 };
    int b[8] = { 2,1,2,3,2,4,2,5 };
    int c[10] = { 3,3,1,1,2,2,4,4,5,5 };
    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == a[i % 5]) acnt++;
        if (answers[i] == b[i % 8]) bcnt++;
        if (answers[i] == c[i % 10]) ccnt++;
    }
    priority_queue<pair<int, int>,vector<pair<int,int>>,less<pair<int,int>>> answer_pq;
    answer_pq.push(make_pair(acnt, -1));
    answer_pq.push(make_pair(bcnt, -2));
    answer_pq.push(make_pair(ccnt, -3));
    
    int temp = answer_pq.top().first;
    answer.push_back(answer_pq.top().second * (-1));       
    answer_pq.pop();

    while (temp == answer_pq.top().first)
    {
        temp = answer_pq.top().first;
        answer.push_back(answer_pq.top().second*(-1));
        answer_pq.pop();
        if (answer_pq.empty())
            break;
    }
    return answer;
}
int main()
{
    solution({ 1,3,2,4,2 });
    return 0;
}

#ifdef __ANSWER__
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> one = { 1,2,3,4,5 };
vector<int> two = { 2,1,2,3,2,4,2,5 };
vector<int> thr = { 3,3,1,1,2,2,4,4,5,5 };

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> they(3);
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == one[i % one.size()]) they[0]++;
        if (answers[i] == two[i % two.size()]) they[1]++;
        if (answers[i] == thr[i % thr.size()]) they[2]++;
    }
    int they_max = *max_element(they.begin(), they.end());
    for (int i = 0; i < 3; i++) {
        if (they[i] == they_max) answer.push_back(i + 1);
    }
    return answer;
}
#endif