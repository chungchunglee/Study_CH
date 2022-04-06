/*
https://programmers.co.kr/learn/courses/30/lessons/42883
ū �� �����
���� ����
� ���ڿ��� k���� ���� �������� �� ���� �� �ִ� ���� ū ���ڸ� ���Ϸ� �մϴ�.

���� ���, ���� 1924���� �� �� ���� �����ϸ� [19, 12, 14, 92, 94, 24] �� ���� �� �ֽ��ϴ�. �� �� ���� ū ���ڴ� 94 �Դϴ�.

���ڿ� �������� ���� number�� ������ ���� ���� k�� solution �Լ��� �Ű������� �־����ϴ�. 
number���� k ���� ���� �������� �� ���� �� �ִ� �� �� ���� ū ���ڸ� ���ڿ� ���·� return �ϵ��� solution �Լ��� �ϼ��ϼ���.

���� ����
number�� 1�ڸ� �̻�, 1,000,000�ڸ� ������ �����Դϴ�.
k�� 1 �̻� number�� �ڸ��� �̸��� �ڿ����Դϴ�.
����� ��
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
