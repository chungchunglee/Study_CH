/*https://programmers.co.kr/learn/courses/30/lessons/42885
* ����Ʈ
���� ����
���ε��� ���� ������� ����Ʈ�� �̿��Ͽ� �����Ϸ��� �մϴ�. ����Ʈ�� �۾Ƽ� �� ���� �ִ� 2�� �ۿ� Ż �� ����, ���� ���ѵ� �ֽ��ϴ�.

���� ���, ������� �����԰� [70kg, 50kg, 80kg, 50kg]�̰� ����Ʈ�� ���� ������ 100kg�̶�� 2��° ����� 4��° ����� ���� Ż �� ������
1��° ����� 3��° ����� ������ ���� 150kg�̹Ƿ� ����Ʈ�� ���� ������ �ʰ��Ͽ� ���� Ż �� �����ϴ�.

����Ʈ�� �ִ��� ���� ����Ͽ� ��� ����� �����Ϸ��� �մϴ�.

������� �����Ը� ���� �迭 people�� ����Ʈ�� ���� ���� limit�� �Ű������� �־��� ��, ��� ����� �����ϱ� ���� �ʿ��� ����Ʈ ������ �ּڰ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
���ε��� ���� ����� 1�� �̻� 50,000�� �����Դϴ�.
�� ����� �����Դ� 40kg �̻� 240kg �����Դϴ�.
����Ʈ�� ���� ������ 40kg �̻� 240kg �����Դϴ�.
����Ʈ�� ���� ������ �׻� ������� ������ �� �ִ񰪺��� ũ�� �־����Ƿ� ������� ������ �� ���� ���� �����ϴ�.
����� ��
people	limit	return
[70, 50, 80, 50]	100	3
[70, 80, 50]	100	3
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int solution(vector<int> people, int limit)
{
    int answer = 0;
    answer = people.size();
    int index = people.size() - 1;
    sort(people.begin(), people.end());
    for (int i = 0; i <= index; i++)
    {
        //���۰� ���� ¦¢��
        for (; index > i; index--)
        {
            if (people[i] + people[index] <= limit)
            {
                index--;
                answer--;
                break;
            }
        }
    }
    return answer;
}

int main()
{
    int a = solution({ 70,50,80,50 }, 100);
    a = solution({50,50,50 }, 100);
    ;
}

#ifdef __OTHERS
//���� ����
int solution(vector<int> people, int limit)
{
    int answer = 0;
    answer = people.size();
    int index = people.size() - 1;
    sort(people.begin(), people.end());
    for (int i = 0; i <= index; i++)
    {
        //������ limit�� ���� ������ ��� �������� ��� ¦���� ���� ����
        if (people[index] * 2 <= limit)
        {
            answer -= (index - i + 1) / 2;
            break;
        }
        //���۰��� limit�� ���� �ʰ��� ��� �������� ��� ¦�������� ����
        if (people[i] * 2 > limit)
        {
            break;
        }
        //���۰� ���� ¦¢��
        for (int j = index; j > i; j--)
        {
            if (people[i] + people[j] <= limit)
            {
                index = j;
                index--;
                answer--;
                break;
            }
        }
    }
    return answer;
}
//sol1
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    reverse(people.begin(), people.end());
    int N = (int)people.size();
    int res = 0;
    for (int i = 0, j = N - 1; i <= j; i++) {
        if (people[i] + people[j] <= limit) {
            j--;
        }
        res++;
    }
    return res;
}
//sol2
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    int maxPeopleIdx = people.size() - 1;
    int minPeopleIdx = 0;

    while (maxPeopleIdx > minPeopleIdx)
    {
        if (people[maxPeopleIdx--] + people[minPeopleIdx] <= limit)
            ++minPeopleIdx;
    }

    int answer = people.size() - minPeopleIdx;
    return answer;
}
//sol3
#include <string>
#include <vector>

#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;


int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end(), greater<int>());
    int back_index = people.size() - 1;
    for (int i = 0; i < people.size(); i++)
    {
        if (people[i] == 0)
            break;
        if (people[i] + people[back_index] <= limit)
        {
            people[i] = 0;
            people[back_index] = 0;
            back_index -= 1;
            answer += 1;
        }
        else
        {
            people[i] = 0;
            answer += 1;
        }
    }
    return answer;
}

#endif // __OTHERS
