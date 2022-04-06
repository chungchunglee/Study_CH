/*
문제 설명
어떤 숫자에서 k개의 수를 제거했을 때 얻을 수 있는 가장 큰 숫자를 구하려 합니다.

예를 들어, 숫자 1924에서 수 두 개를 제거하면 [19, 12, 14, 92, 94, 24] 를 만들 수 있습니다. 이 중 가장 큰 숫자는 94 입니다.

문자열 형식으로 숫자 number와 제거할 수의 개수 k가 solution 함수의 매개변수로 주어집니다. number에서 k 개의 수를 제거했을 때 만들 수 있는 수 중 가장 큰 숫자를 문자열 형태로 return 하도록 solution 함수를 완성하세요.

제한 조건
number는 1자리 이상, 1,000,000자리 이하인 숫자입니다.
k는 1 이상 number의 자릿수 미만인 자연수입니다.
입출력 예
number	k	return
"1924"	2	"94"
"1231234"	3	"3234"
"4177252841"	4	"775841"
출처*/
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int len = number.size();
    int index = -1;
    //k개의 수 를 제외하여 큰수를 만든다는 말은 len(전체길이) - k(뺄 개수) 만큼의 큰수를 뽑는다는 말과 일치

    //앞에서 부터 i+1 번째 자리수 뽑기(최고자리수 부터 역으로 진행) 
    for (int i = 0; i < len - k; i++)
    {
        index++;
        char max_num = number[index];
        /*현재 직전의 가장큰수의 인덱스로부터 시작하여 지금뽑는 자리수(i)+k까지 가장 큰 수 탐색
        가장 큰 자리수를 뽑을때에 가능한 인덱스의 범위는 직전인덱스부터 현재 뽑는 자리수의 인덱스 + k 까지 가능
        ex) 앞에서부터 3번째에 위치할 가장 큰 수 뽑을때에는 이전 인덱스(앞에서부터 2번째에 위치할 가장 큰수의 인덱스)부터 현재 뽑을 자리수의 위치(3) + 제거할수있는 숫자의 개수(k)까지 -> index ~ 3+k*/
        for (int j = index; j <= i + k; j++)
        {
            if (max_num < number[j])
            {
                max_num = number[j];
                index = j;
            }
        }
        answer += max_num;
    }
    return answer;
}
int main()
{
    //"4177252841"	4	"775841"

    string s1 = solution("4177252841", 4);
    s1 = solution("4177252841", 4);
}