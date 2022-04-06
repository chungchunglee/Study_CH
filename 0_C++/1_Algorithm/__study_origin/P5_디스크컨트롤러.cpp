/*https://programmers.co.kr/learn/courses/30/lessons/42627
* ���� ����
�ϵ��ũ�� �� ���� �ϳ��� �۾��� ������ �� �ֽ��ϴ�. ��ũ ��Ʈ�ѷ��� �����ϴ� ����� ���� ������ �ֽ��ϴ�. ���� �Ϲ����� ����� ��û�� ���� ������� ó���ϴ� ���Դϴ�.

�������

- 0ms ������ 3ms�� �ҿ�Ǵ� A�۾� ��û
- 1ms ������ 9ms�� �ҿ�Ǵ� B�۾� ��û
- 2ms ������ 6ms�� �ҿ�Ǵ� C�۾� ��û
�� ���� ��û�� ���Խ��ϴ�. �̸� �׸����� ǥ���ϸ� �Ʒ��� �����ϴ�.
Screen Shot 2018-09-13 at 6.34.58 PM.png

�� ���� �ϳ��� ��û���� ������ �� �ֱ� ������ ������ �۾��� ��û���� ������� ó���ϸ� ������ ���� ó�� �˴ϴ�.
Screen Shot 2018-09-13 at 6.38.52 PM.png

- A: 3ms ������ �۾� �Ϸ� (��û���� ������� : 3ms)
- B: 1ms���� ����ϴٰ�, 3ms ������ �۾��� �����ؼ� 12ms ������ �۾� �Ϸ�(��û���� ������� : 11ms)
- C: 2ms���� ����ϴٰ�, 12ms ������ �۾��� �����ؼ� 18ms ������ �۾� �Ϸ�(��û���� ������� : 16ms)
�� �� �� �۾��� ��û���� ������� �ɸ� �ð��� ����� 10ms(= (3 + 11 + 16) / 3)�� �˴ϴ�.

������ A �� C �� B ������� ó���ϸ�
Screen Shot 2018-09-13 at 6.41.42 PM.png

- A: 3ms ������ �۾� �Ϸ�(��û���� ������� : 3ms)
- C: 2ms���� ����ϴٰ�, 3ms ������ �۾��� �����ؼ� 9ms ������ �۾� �Ϸ�(��û���� ������� : 7ms)
- B: 1ms���� ����ϴٰ�, 9ms ������ �۾��� �����ؼ� 18ms ������ �۾� �Ϸ�(��û���� ������� : 17ms)
�̷��� A �� C �� B�� ������ ó���ϸ� �� �۾��� ��û���� ������� �ɸ� �ð��� ����� 9ms(= (3 + 7 + 17) / 3)�� �˴ϴ�.

�� �۾��� ���� [�۾��� ��û�Ǵ� ����, �۾��� �ҿ�ð�]�� ���� 2���� �迭 jobs�� �Ű������� �־��� ��, �۾��� ��û���� ������� �ɸ� �ð��� ����� ���� ���̴� ������� ó���ϸ� ����� �󸶰� �Ǵ��� return �ϵ��� solution �Լ��� �ۼ����ּ���. (��, �Ҽ��� ������ ���� �����ϴ�)

���� ����
jobs�� ���̴� 1 �̻� 500 �����Դϴ�.
jobs�� �� ���� �ϳ��� �۾��� ���� [�۾��� ��û�Ǵ� ����, �۾��� �ҿ�ð�] �Դϴ�.
�� �۾��� ���� �۾��� ��û�Ǵ� �ð��� 0 �̻� 1,000 �����Դϴ�.
�� �۾��� ���� �۾��� �ҿ�ð��� 1 �̻� 1,000 �����Դϴ�.
�ϵ��ũ�� �۾��� �����ϰ� ���� ���� ������ ���� ��û�� ���� �۾����� ó���մϴ�.
����� ��
jobs	return
[[0, 3], [1, 9], [2, 6]]	9
����� �� ����
������ �־��� ���� �����ϴ�.

0ms ������ 3ms �ɸ��� �۾� ��û�� ���ɴϴ�.
1ms ������ 9ms �ɸ��� �۾� ��û�� ���ɴϴ�.
2ms ������ 6ms �ɸ��� �۾� ��û�� ���ɴϴ�.
*/
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue < pair<int, int>, vector<pair<int,int>>,greater<pair<int,int>>> pq_jobs;
    priority_queue < pair<int, int>, vector<pair<int,int>>,greater<pair<int,int>>> pq_jobs_reverse;
        

    for (int i = 0; i < jobs.size(); i++)
        pq_jobs.push( make_pair(jobs[i][0],jobs[i][1]));
    
    int time = pq_jobs.top().first + pq_jobs.top().second;
    answer = pq_jobs.top().second;
    pq_jobs.pop();

    while (!pq_jobs.empty())
    {
        while (!pq_jobs.empty() && pq_jobs.top().first <= time)
        {
            pq_jobs_reverse.push(make_pair(pq_jobs.top().second, pq_jobs.top().first));
            pq_jobs.pop();
        }
        if (!pq_jobs.empty() && pq_jobs_reverse.empty())
        {
            time = pq_jobs.top().first;
            continue;
        }
        time = time + pq_jobs_reverse.top().first;
        answer += time - pq_jobs_reverse.top().second;
        pq_jobs_reverse.pop();
        while (!pq_jobs_reverse.empty())
        {
            pq_jobs.push(make_pair(pq_jobs_reverse.top().second, pq_jobs_reverse.top().first));
            pq_jobs_reverse.pop();
        }
    }
    answer = answer / int(jobs.size());
    return answer;
}
int main()
{
    vector<vector<int>> jobs = { {0, 3} ,{1, 9},{2, 6 }};

    cout << solution(jobs);


    return 0;
}