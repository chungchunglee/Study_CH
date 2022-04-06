/*https://programmers.co.kr/learn/courses/30/lessons/42840
* 모의고사
문제 설명
수포자는 수학을 포기한 사람의 준말입니다. 수포자 삼인방은 모의고사에 수학 문제를 전부 찍으려 합니다. 수포자는 1번 문제부터 마지막 문제까지 다음과 같이 찍습니다.

1번 수포자가 찍는 방식: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...
2번 수포자가 찍는 방식: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
3번 수포자가 찍는 방식: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...

1번 문제부터 마지막 문제까지의 정답이 순서대로 들은 배열 answers가 주어졌을 때, 가장 많은 문제를 맞힌 사람이 누구인지 배열에 담아 return 하도록 solution 함수를 작성해주세요.

제한 조건
시험은 최대 10,000 문제로 구성되어있습니다.
문제의 정답은 1, 2, 3, 4, 5중 하나입니다.
가장 높은 점수를 받은 사람이 여럿일 경우, return하는 값을 오름차순 정렬해주세요.
입출력 예
answers	return
[1,2,3,4,5]	[1]
[1,3,2,4,2]	[1,2,3]
입출력 예 설명
입출력 예 #1

수포자 1은 모든 문제를 맞혔습니다.
수포자 2는 모든 문제를 틀렸습니다.
수포자 3은 모든 문제를 틀렸습니다.
따라서 가장 문제를 많이 맞힌 사람은 수포자 1입니다.

입출력 예 #2

모든 사람이 2문제씩을 맞췄습니다.
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