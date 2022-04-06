/*
https://programmers.co.kr/learn/courses/30/lessons/42860
조이스틱
문제 설명
조이스틱으로 알파벳 이름을 완성하세요. 맨 처음엔 A로만 이루어져 있습니다.
ex) 완성해야 하는 이름이 세 글자면 AAA, 네 글자면 AAAA

조이스틱을 각 방향으로 움직이면 아래와 같습니다.

▲ - 다음 알파벳
▼ - 이전 알파벳 (A에서 아래쪽으로 이동하면 Z로)
◀ - 커서를 왼쪽으로 이동 (첫 번째 위치에서 왼쪽으로 이동하면 마지막 문자에 커서)
▶ - 커서를 오른쪽으로 이동 (마지막 위치에서 오른쪽으로 이동하면 첫 번째 문자에 커서)
예를 들어 아래의 방법으로 "JAZ"를 만들 수 있습니다.

- 첫 번째 위치에서 조이스틱을 위로 9번 조작하여 J를 완성합니다.
- 조이스틱을 왼쪽으로 1번 조작하여 커서를 마지막 문자 위치로 이동시킵니다.
- 마지막 위치에서 조이스틱을 아래로 1번 조작하여 Z를 완성합니다.
따라서 11번 이동시켜 "JAZ"를 만들 수 있고, 이때가 최소 이동입니다.
만들고자 하는 이름 name이 매개변수로 주어질 때, 
이름에 대해 조이스틱 조작 횟수의 최솟값을 return 하도록 solution 함수를 만드세요.

제한 사항
name은 알파벳 대문자로만 이루어져 있습니다.
name의 길이는 1 이상 20 이하입니다.
입출력 예
name	return
"JEROEN"	56
"JAN"	23
출처
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;



int solution(string name) {
    int answer = 0;
    vector<int> non_A_index;
    int len = name.size();

    for (int i = 0; i < len; i++)
    {
        answer += (int)(name[i] - 'A' < 'Z' - name[i] + 1) ? name[i] - 'A' : 'Z' - name[i] + 1;
        if (name[i] != 'A')
            non_A_index.push_back(i);
    }
    //예외 처리 1 - 바꿀필요없을 경우
    if (!non_A_index.size())
        return answer;
    int next = 1;
    //초깃값 설정 - min값
    int min_val = min(non_A_index.back(),len - non_A_index.front());

    for (int i = 0; i < non_A_index.size() - 1; i++)
    {
        min_val = min(min_val, non_A_index[i] + len - non_A_index[i + 1] + min(non_A_index[i], len - non_A_index[i + 1]));
    }
    answer += min_val;
    return answer;
}
int main()
{
    int a_b = solution("AABAAAAAAAB");
    a_b = solution("AAAAAAAA");
    a_b = solution("ABBBBAAAAABAAA");
    a_b = solution("ABBBBAAAAABAAA");
    return 0;
}

#ifdef __OTHERS__
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    for (auto ch : name) answer += min(ch - 'A', 91 - ch);

    int len = name.length();
    int move = len - 1;
    int next;
    for (int i = 0; i < len; i++) 
    {
        next = i + 1;
        while (next < len && name[next] == 'A') next++;
        move = min(move, i + (len - next) + min(i, len - next));
    }
    answer += move;

    return answer;
}

#endif // __OTHERS__
