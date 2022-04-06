/*
문제 설명
0 또는 양의 정수가 주어졌을 때, 정수를 이어 붙여 만들 수 있는 가장 큰 수를 알아내 주세요.

예를 들어, 주어진 정수가 [6, 10, 2]라면 [6102, 6210, 1062, 1026, 2610, 2106]를 만들 수 있고, 이중 가장 큰 수는 6210입니다.

0 또는 양의 정수가 담긴 배열 numbers가 매개변수로 주어질 때, 순서를 재배치하여 만들 수 있는 가장 큰 수를 문자열로 바꾸어 return 하도록 solution 함수를 작성해주세요.

제한 사항
numbers의 길이는 1 이상 100,000 이하입니다.
numbers의 원소는 0 이상 1,000 이하입니다.
정답이 너무 클 수 있으니 문자열로 바꾸어 return 합니다.
입출력 예
numbers	return
[6, 10, 2]	"6210"
[3, 30, 34, 5, 9]	"9534330"
※ 공지 - 2021년 10월 20일 테스트케이스가 추가되었습니다.*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool comp_str(string a, string b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    int len = numbers.size();
    // 자리수 더하기를 위한 string배열로 변환
    vector<string> numbers_str(len);
    for (int i = 0; i < len; i++)
        numbers_str[i] = to_string(numbers[i]);

    //사용자 정의 함수를 통한 정렬
    sort(numbers_str.begin(), numbers_str.end(), comp_str);
    //최종 문자열 구하기
    for (auto n : numbers_str)
        answer += n;
    //만약 맨앞자리수(answer[0])가 0이라면 모든 멤버가 0 즉 00000 혹은 0인 경우 이므로 0으로 변환
    if (answer[0] == '0')
        answer = "0";
    //답 반환
    return answer;
}