//https://programmers.co.kr/learn/courses/30/lessons/42746
/*
* ���� ū ��
���� ����
0 �Ǵ� ���� ������ �־����� ��, ������ �̾� �ٿ� ���� �� �ִ� ���� ū ���� �˾Ƴ� �ּ���.

���� ���, �־��� ������ [6, 10, 2]��� [6102, 6210, 1062, 1026, 2610, 2106]�� ���� �� �ְ�, ���� ���� ū ���� 6210�Դϴ�.

0 �Ǵ� ���� ������ ��� �迭 numbers�� �Ű������� �־��� ��, ������ ���ġ�Ͽ� ���� �� �ִ� ���� ū ���� ���ڿ��� �ٲپ� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���� ����
numbers�� ���̴� 1 �̻� 100,000 �����Դϴ�.
numbers�� ���Ҵ� 0 �̻� 1,000 �����Դϴ�.
������ �ʹ� Ŭ �� ������ ���ڿ��� �ٲپ� return �մϴ�.
����� ��
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