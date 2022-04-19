/*
N���� ǥ��
���� ����
�Ʒ��� ���� 5�� ��Ģ���길���� 12�� ǥ���� �� �ֽ��ϴ�.

12 = 5 + 5 + (5 / 5) + (5 / 5)
12 = 55 / 5 + 5 / 5
12 = (55 + 5) / 5

5�� ����� Ƚ���� ���� 6,5,4 �Դϴ�. �׸��� ���� ���� ���� ���� 4�Դϴ�.
��ó�� ���� N�� number�� �־��� ��, N�� ��Ģ���길 ����ؼ� ǥ�� �� �� �ִ� ��� �� N ���Ƚ���� �ּڰ��� return �ϵ��� solution �Լ��� �ۼ��ϼ���.

���ѻ���
N�� 1 �̻� 9 �����Դϴ�.
number�� 1 �̻� 32,000 �����Դϴ�.
���Ŀ��� ��ȣ�� ��Ģ���길 �����ϸ� ������ ���꿡�� �������� �����մϴ�.
�ּڰ��� 8���� ũ�� -1�� return �մϴ�.
����� ��
N	number	return
5	12	4
2	11	3
����� �� ����
���� #1
������ ���� ���� �����ϴ�.

���� #2
11 = 22 / 2�� ���� 2�� 3���� ����Ͽ� ǥ���� �� �ֽ��ϴ�.

��ó

�� ���� - 2020�� 9�� 3�� �׽�Ʈ���̽��� �߰��Ǿ����ϴ�.*/
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int create_continuous_num(int N, int digit)
{
    string answer;
    string s = to_string(N);
    for (int i = 0; i < digit; i++)
        answer += s;
    return stoi(answer);
}
void create_pool(int N,int digit,vector<unordered_set<int>>& pool)
{
    pool[digit-1].insert(create_continuous_num(N, digit));
    for (int i = 0; i < digit - 1; i++)
    {
        for (auto u : pool[i])
        {
            for (auto v : pool[digit -2 - i])
            {
                int num;
                num = u + v;
                pool[digit-1].insert(num);
                num = u * v;
                pool[digit-1].insert(num);
                num = u - v;
                if(num > 0)
                    pool[digit-1].insert(num);
                num = u / v;
                if(num > 0)
                    pool[digit-1].insert(num);
            }
        }
    }
}

int solution(int N, int number) {
    int answer = 1;
    vector<unordered_set<int>> pool(8);
    pool[0].insert(N);
    while (++answer != 9)
    {
        create_pool(N, answer, pool);
        if (pool[answer-1].find(number) != pool[answer-1].end())
            return answer;
    }
    return -1;
}
int main()
{
    int s0 = solution(5, 12);
    int s1 = solution(8, 53);
    int s2 = solution(2, 11425);
    int s3 = solution(2, 11);
    return 0;
}