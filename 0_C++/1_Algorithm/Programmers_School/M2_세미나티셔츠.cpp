/*
문제 설명
최대한 많은 세미나 참가자에게 티셔츠를 나눠주려 합니다. 티셔츠를 나눠주는 조건은 다음과 같습니다.

한 사람당 티셔츠를 최대 하나씩 줍니다.
모든 참가자는 자신의 상의 크기와 같거나 큰 티셔츠를 받습니다.
예를 들어 크기가 [1, 2, 3] 인 티셔츠가 있고, 각각 상의 크기가 [2, 3, 4]인 참가자 셋이 있습니다. 
첫 번째 사람에게 두 번째 티셔츠를, 두 번째 사람에게 세 번째 티셔츠를 나눠줄 수 있습니다. 크기가 4인 참가자는 티셔츠를 받지 못합니다. 따라서 최대 2명에게 티셔츠를 줄 수 있습니다.

참가자별 상의 크기 people과 세미나 주최 측이 가진 티셔츠 크기 tshirts가 매개변수로 주어질 때, 최대 몇 명에게 티셔츠를 나눠 줄 수 있는지 return 하도록 solution 함수를 작성하세요.

제한 사항
세미나에 참가한 사람 수는 2명 이상 5,000명 이하입니다.
주최 측은 티셔츠를 2벌 이상 5,000벌 이하로 준비했습니다.
참가자의 상의 크기와 준비한 티셔츠 크기는 1 이상 1,000 이하인 정수입니다.
입출력 예시
people	tshirts	result
[2, 3]	[1, 2, 3]	2
[1, 2, 3]	[1, 1]	1
입출력 예시 설명
입출력 예 #1
첫 번째 사람에게 두 번째 티셔츠를, 두 번째 사람에게 세 번째 티셔츠를 주면 최대 2명에게 티셔츠를 줄 수 있습니다.

입출력 예 #2

첫 번째 사람에게만 티셔츠를 줄 수 있습니다.
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, vector<int> tshirts) {
    int answer = 0;
    int index = 0;
    //오름차순으로 정렬 
    sort(people.begin(), people.end());
    sort(tshirts.begin(), tshirts.end());
    //인덱스를 기준으로 tshirts 분배
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