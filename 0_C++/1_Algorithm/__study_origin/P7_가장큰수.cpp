//https://programmers.co.kr/learn/courses/30/lessons/42746
/*
* 가장 큰 수
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
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool comp_str(string a, string b)
{
    return (a + b) > (b + a);
}


string solution(vector<int> numbers) {
    string answer = "", fail = "";
    vector<string> numbers_str(numbers.size());

    for (int i = 0; i < numbers.size(); i++) 
        numbers_str[i] = to_string(numbers[i]);

    sort(numbers_str.begin(), numbers_str.end(), comp_str);
    for (auto k : numbers_str)
    {
        answer += k;
        fail += '0';
    }
    if (answer == fail)
        answer = '0';

    return answer;
}
int main()
{
    cout << solution({0,0,0,0,0}) << endl;
}
#ifdef __OTHERS__
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool compare(const string& a, const string& b)
{
    if (b + a < a + b)
        return true;
    return false;
}

string solution(vector<int> numbers) {
    string answer = "";

    vector<string> strings;

    for (int i : numbers)
        strings.push_back(to_string(i));

    sort(strings.begin(), strings.end(), compare);

    for (auto iter = strings.begin(); iter < strings.end(); ++iter)
        answer += *iter;

    if (answer[0] == '0')
        answer = "0";

    return answer;
}
#endif // __OTHERS__


//fail 1
/*
string solution(vector<int> numbers) {
    string answer = "";
    map <float, int,greater<float>> checker;
    for (int i = 0 ; i < numbers.size(); i++)
    {
        int n = 0;
        float m = numbers[i];
        while (1)
        {
            if (m  < 10.0f)
                break;
            m = m / 10;
            n++;
        }
        checker[m] = n;
    }
    for (auto& k : checker)
    {
        int n = k.second;
        int m = k.first;
        while (n--)
            m *= 10;
        answer += to_string(int(m));
    }

    return answer;
}
*/

//fail 2
/*
string solution(vector<int> numbers) {
    string answer = "";
    priority_queue <pair<float, int>> checker;
    for (int i = 0 ; i < numbers.size(); i++)
    {
        int n = 0;
        float m = numbers[i];
        while (1)
        {
            if (m  < 10.0f)
                break;
            m = m / 10;
            n--;
        }
        checker.push(make_pair(m, n));
    }
    while(!checker.empty())
    {
        int n = checker.top().second;
        float m = checker.top().first;
        checker.pop();

        while (n++)
            m *= 10;
        answer += to_string(int(m));
    }

    return answer;
}
*/