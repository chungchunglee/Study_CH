/*https://programmers.co.kr/learn/courses/30/lessons/42895
* N으로 표현
문제 설명
아래와 같이 5와 사칙연산만으로 12를 표현할 수 있습니다.

12 = 5 + 5 + (5 / 5) + (5 / 5)
12 = 55 / 5 + 5 / 5
12 = (55 + 5) / 5

5를 사용한 횟수는 각각 6,5,4 입니다. 그리고 이중 가장 작은 경우는 4입니다.
이처럼 숫자 N과 number가 주어질 때, N과 사칙연산만 사용해서 표현 할 수 있는 방법 중 N 사용횟수의 최솟값을 return 하도록 solution 함수를 작성하세요.

제한사항
N은 1 이상 9 이하입니다.
number는 1 이상 32,000 이하입니다.
수식에는 괄호와 사칙연산만 가능하며 나누기 연산에서 나머지는 무시합니다.
최솟값이 8보다 크면 -1을 return 합니다.
입출력 예
N	number	return
5	12	4
2	11	3
입출력 예 설명
예제 #1
문제에 나온 예와 같습니다.

예제 #2
11 = 22 / 2와 같이 2를 3번만 사용하여 표현할 수 있습니다.
*/
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
void calc(vector<unordered_set<int>>& set_of_num,int N, int index)
{
    string s = to_string(N);
    for (int i = 1; i < index; i++)
        s += to_string(N);
    set_of_num[index].insert(stoi(s));

    for(int i = 1; i< index ; i++)
        for(auto l : set_of_num[index - i])
            for (auto k : set_of_num[i])
            {
                int a;
                set_of_num[index].insert(l + k);
                set_of_num[index].insert(l * k);
                if ((a = l - k) > 0)
                    set_of_num[index].insert(a);
                if ((a = l / k) > 0)
                    set_of_num[index].insert(a);
            }
}

int solution(int N, int number) {
    if (N == number)
        return 1;
    
    int answer = 0;
    vector<unordered_set<int>> set_of_num(9);
    set_of_num[1].insert(N);
    int index = 1;
    while (index != 8)
    {
        index++;
        calc(set_of_num, N, index);
        if (set_of_num[index].find(number) != set_of_num[index].end())
            return index;
    }
    return -1;
}
int main()
{
    int s1 = solution(8, 53);
    int s2 = solution(2, 11425);
    int s3 = solution(2, 11);
    return 0;
}

#ifdef __OTHERS__
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int N;
unordered_set<int> cache[10];
unordered_set<int> solve(int n) {
    if (!cache[n].empty()) return cache[n];
    int num = 0;
    for (int i = 0; i < n; i++) num = 10 * num + N;
    unordered_set<int> res;
    res.insert(num);
    for (int i = 1; i < n; i++) {
        int j = n - i;
        auto s1 = solve(i);
        auto s2 = solve(j);
        for (int n1 : s1) {
            for (int n2 : s2) {
                res.insert(n1 + n2);
                res.insert(n1 - n2);
                res.insert(n1 * n2);
                if (n2 != 0) res.insert(n1 / n2);
            }
        }
    }
    return cache[n] = res;
}

int solution(int _N, int number) {
    N = _N;
    for (int i = 1; i <= 8; i++) {
        solve(i);
        if (cache[i].find(number) != cache[i].end()) return i;
    }
    return -1;
}
#endif // __OTHERS__
