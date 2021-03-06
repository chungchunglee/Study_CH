/*
https://programmers.co.kr/learn/courses/30/lessons/43165
타겟 넘버
문제 설명
n개의 음이 아닌 정수들이 있습니다. 이 정수들을 순서를 바꾸지 않고 적절히 더하거나 빼서 타겟 넘버를 만들려고 합니다.
예를 들어 [1, 1, 1, 1, 1]로 숫자 3을 만들려면 다음 다섯 방법을 쓸 수 있습니다.

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3
사용할 수 있는 숫자가 담긴 배열 numbers, 타겟 넘버 target이 매개변수로 주어질 때 숫자를 적절히 더하고 빼서
타겟 넘버를 만드는 방법의 수를 return 하도록 solution 함수를 작성해주세요.

제한사항
주어지는 숫자의 개수는 2개 이상 20개 이하입니다.
각 숫자는 1 이상 50 이하인 자연수입니다.
타겟 넘버는 1 이상 1000 이하인 자연수입니다.
입출력 예
numbers	target	return
{1, 1, 1, 1, 1}	3	5
{4, 1, 2, 1]}	4	2
입출력 예 설명
입출력 예 #1

문제 예시와 같습니다.

입출력 예 #2

+4+1-2+1 = 4
+4-1+2-1 = 4
총 2가지 방법이 있으므로, 2를 return 합니다.
*/
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

void DFS(vector<int>& numbers, int target, int n, int sum, int& answer)
{
    if (n >= numbers.size())
    {
        if (sum == target) answer++;
        return;
    }
    DFS(numbers, target, n + 1, sum + numbers[n], answer);
    DFS(numbers, target, n + 1, sum - numbers[n], answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    DFS(numbers, target, 1, numbers[0], answer);
    DFS(numbers, target, 1, -numbers[0], answer);

    return answer;
}
int main()
{
    int s1 = solution({ 1, 1, 1, 1, 1 }, 3);
    int s2 = solution({ 4, 1, 2, 1}, 4);
        //{1, 1, 1, 1, 1}	3	5
        //{4, 1, 2, 1]}	4	2
}
#ifdef __OTHERS__
#include <string>
#include <vector>

using namespace std;

int total;

void DFS(vector<int>& numbers, int& target, int sum, int n) {
    if (n >= numbers.size()) {
        if (sum == target) total++;
        return;
    }

    DFS(numbers, target, sum + numbers[n], n + 1);
    DFS(numbers, target, sum - numbers[n], n + 1);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    DFS(numbers, target, numbers[0], 1);
    DFS(numbers, target, -numbers[0], 1);

    answer = total;

    return answer;
}

#endif // __OTHERS__
#ifdef __MYSOL__
int solution(vector<int> numbers, int target) {
    int answer = 0;
    int len = numbers.size();
    int x = 1 << len;

    unordered_map<int, int> n_m;
    for (int i = 0; i < x; i++)
    {
        int ans = 0;
        for (int j = 0; j < len; j++)
        {
            if (((i >> j) & 1) == 1)
                ans += numbers[j];
            else
                ans -= numbers[j];
        }
        n_m[ans]++;
    }
    return n_m[target];

    return answer;
}
#endif // __MYSOL__

