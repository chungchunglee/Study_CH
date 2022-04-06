/*
문제 설명
점심시간에 도둑이 들어, 일부 학생이 체육복을 도난당했습니다. 다행히 여벌 체육복이 있는 학생이 이들에게 체육복을 빌려주려 합니다.
학생들의 번호는 체격 순으로 매겨져 있어, 바로 앞번호의 학생이나 바로 뒷번호의 학생에게만 체육복을 빌려줄 수 있습니다.
예를 들어, 4번 학생은 3번 학생이나 5번 학생에게만 체육복을 빌려줄 수 있습니다. 체육복이 없으면 수업을 들을 수 없기 때문에 체육복을 적절히 빌려 
최대한 많은 학생이 체육수업을 들어야 합니다.

전체 학생의 수 n, 체육복을 도난당한 학생들의 번호가 담긴 배열 lost, 
여벌의 체육복을 가져온 학생들의 번호가 담긴 배열 reserve가 매개변수로 주어질 때, 체육수업을 들을 수 있는 학생의 최댓값을 return 하도록 solution 함수를 작성해주세요.

제한사항
전체 학생의 수는 2명 이상 30명 이하입니다.
체육복을 도난당한 학생의 수는 1명 이상 n명 이하이고 중복되는 번호는 없습니다.
여벌의 체육복을 가져온 학생의 수는 1명 이상 n명 이하이고 중복되는 번호는 없습니다.
여벌 체육복이 있는 학생만 다른 학생에게 체육복을 빌려줄 수 있습니다.
여벌 체육복을 가져온 학생이 체육복을 도난당했을 수 있습니다. 이때 이 학생은 체육복을 하나만 도난당했다고 가정하며, 
남은 체육복이 하나이기에 다른 학생에게는 체육복을 빌려줄 수 없습니다.
입출력 예
n	lost	reserve	return
5	[2, 4]	[1, 3, 5]	5
5	[2, 4]	[3]	4
3	[3]	[1]	2
입출력 예 설명
예제 #1
1번 학생이 2번 학생에게 체육복을 빌려주고, 3번 학생이나 5번 학생이 4번 학생에게 체육복을 빌려주면 학생 5명이 체육수업을 들을 수 있습니다.

예제 #2
3번 학생이 2번 학생이나 4번 학생에게 체육복을 빌려주면 학생 4명이 체육수업을 들을 수 있습니다.

출처

※ 공지 - 2019년 2월 18일 지문이 리뉴얼되었습니다.
※ 공지 - 2019년 2월 27일, 28일 테스트케이스가 추가되었습니다.
※ 공지 - 2021년 7월 28일 테스트케이스가 추가되었습니다.
※ 공지 - 2021년 8월 30일 테스트케이스가 추가되었습니다.*/

#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    //학생수+2 만큼 배열 선언 후 1로 초기화 (0번 인덱스와 n+2번인덱스는 추후 조건문의 배열 선언 범위를 넘어가지 않기 위해 사용)
    vector<int> students_status(n + 2, 1);
    //잃어버린 학생 반영
    for (auto l : lost)
        students_status[l]--;
    //더가져온 학생 반영
    for (auto r : reserve)
        students_status[r]++;
    //체육복 가져온 학생 재분배(0개 일경우 좌우 탐색하여 2인학생에게 대여)
    for (int i = 0; i < n; i++)
    {
        if (students_status[i] != 0)
            continue;
        if (students_status[i - 1] == 2)
        {
            students_status[i - 1]--;
            students_status[i]++;
        }
        else if (students_status[i + 1] == 2)
        {
            students_status[i + 1]--;
            students_status[i]++;
        }
    }
    //체육복 가져온 학생(1개 혹은 2개)만큼 answer++
    for (auto s : students_status)
    {
        if (s > 0)
            answer++;
    }
    // 0번째와 n+1번째는 dummy data 1이 들어가있으므로 2 빼기
    return answer - 2;
}
void main()
{
    //5	[2, 4]	[1, 3, 5]	5
    int a = solution(5, { 1,3,5 }, { 2,4 });
    a = solution(5, { 2,4 }, { 1,3,5 });
    a = solution(5, { 2,4 }, { 1,3,5 });
}

#ifdef __FAILED__
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    //학생수+2 만큼 배열 선언 후 1로 초기화
    vector<int> students_status(n, 1);
    //잃어버린 학생 반영
    for (auto l : lost)
        students_status[l-1]--;
    //더가져온 학생 반영
    for (auto r : reserve)
        students_status[r-1]++;
    for (int i = 0; i < n; i++)
    {
        if (students_status[i] != 0)
            continue;
        if (students_status[i - 1] == 2)
        {
            students_status[i - 1]--;
            students_status[i]++;
        }
        else if (students_status[i + 1] == 2)
        {
            students_status[i + 1]--;
            students_status[i]++;
        }
    }
    for (auto s : students_status)
    {
        if (s > 0)
            answer++;
    }

    return answer;
}
#endif // __FAILED__