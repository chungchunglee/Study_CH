/*
https://programmers.co.kr/learn/courses/30/lessons/42883
큰 수 만들기
문제 설명
어떤 숫자에서 k개의 수를 제거했을 때 얻을 수 있는 가장 큰 숫자를 구하려 합니다.

예를 들어, 숫자 1924에서 수 두 개를 제거하면 [19, 12, 14, 92, 94, 24] 를 만들 수 있습니다. 이 중 가장 큰 숫자는 94 입니다.

문자열 형식으로 숫자 number와 제거할 수의 개수 k가 solution 함수의 매개변수로 주어집니다. 
number에서 k 개의 수를 제거했을 때 만들 수 있는 수 중 가장 큰 숫자를 문자열 형태로 return 하도록 solution 함수를 완성하세요.

제한 조건
number는 1자리 이상, 1,000,000자리 이하인 숫자입니다.
k는 1 이상 number의 자릿수 미만인 자연수입니다.
입출력 예
number	k	return
"1924"	2	"94"
"1231234"	3	"3234"
"4177252841"	4	"775841"
*/
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


string solution(string number, int k) {
    string answer = "";

    for (int j = 0, index = -1; j < number.size() - k; j++)
    {
        char max = 0;
        for (int i = index + 1; i <= k + j; i++)
        {
            if (max < number[i])
            {
                index = i;
                max = number[i];
            }
        }
        answer += max;
    }
    return answer;
}
int main()
{
    string s1 = solution("1222",4);
    s1 = solution("1231234",3);
    s1 = solution("4177252841",4);
    s1 = solution("4177252841",4);
    return 0;
}

#ifdef __FAILED__
string solution(string number, int k) {
    string answer = "";

    if (number.size() == k)
        return "0";
    else if (number.size() == k + 1)
        return answer = *max_element(number.begin(), number.end());

    while (k--)
    {
        auto min_index = number.begin();
        auto max_index = max_element(number.begin(), number.end());
        if (number.begin() == max_index)
        {
            min_index = min_element(max_index, number.end());
            number.erase(min_index);
            continue;
        }
        min_index = min_element(number.begin(), max_index);
        if (min_index == max_index)
            min_index = min_element(max_index, number.end());
        number.erase(min_index);
    }
    while (number[0] == '0')
        number.erase(0);
    return number;
}
#endif // __FAILED__
