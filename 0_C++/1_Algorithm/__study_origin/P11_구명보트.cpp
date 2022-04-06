/*https://programmers.co.kr/learn/courses/30/lessons/42885
* 구명보트
문제 설명
무인도에 갇힌 사람들을 구명보트를 이용하여 구출하려고 합니다. 구명보트는 작아서 한 번에 최대 2명씩 밖에 탈 수 없고, 무게 제한도 있습니다.

예를 들어, 사람들의 몸무게가 [70kg, 50kg, 80kg, 50kg]이고 구명보트의 무게 제한이 100kg이라면 2번째 사람과 4번째 사람은 같이 탈 수 있지만
1번째 사람과 3번째 사람의 무게의 합은 150kg이므로 구명보트의 무게 제한을 초과하여 같이 탈 수 없습니다.

구명보트를 최대한 적게 사용하여 모든 사람을 구출하려고 합니다.

사람들의 몸무게를 담은 배열 people과 구명보트의 무게 제한 limit가 매개변수로 주어질 때, 모든 사람을 구출하기 위해 필요한 구명보트 개수의 최솟값을 return 하도록 solution 함수를 작성해주세요.

제한사항
무인도에 갇힌 사람은 1명 이상 50,000명 이하입니다.
각 사람의 몸무게는 40kg 이상 240kg 이하입니다.
구명보트의 무게 제한은 40kg 이상 240kg 이하입니다.
구명보트의 무게 제한은 항상 사람들의 몸무게 중 최댓값보다 크게 주어지므로 사람들을 구출할 수 없는 경우는 없습니다.
입출력 예
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
        //시작과 끝을 짝짖기
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
//기존 구현
int solution(vector<int> people, int limit)
{
    int answer = 0;
    answer = people.size();
    int index = people.size() - 1;
    sort(people.begin(), people.end());
    for (int i = 0; i <= index; i++)
    {
        //끝값이 limit의 절반 이하일 경우 나머지는 모두 짝지어 갈수 있음
        if (people[index] * 2 <= limit)
        {
            answer -= (index - i + 1) / 2;
            break;
        }
        //시작값이 limit의 절반 초과일 경우 나머지는 모두 짝지어질수 없음
        if (people[i] * 2 > limit)
        {
            break;
        }
        //시작과 끝을 짝짖기
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
