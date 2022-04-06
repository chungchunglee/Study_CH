/*
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
�� ���� - 2021�� 10�� 20�� �׽�Ʈ���̽��� �߰��Ǿ����ϴ�.*/
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
    // �ڸ��� ���ϱ⸦ ���� string�迭�� ��ȯ
    vector<string> numbers_str(len);
    for (int i = 0; i < len; i++)
        numbers_str[i] = to_string(numbers[i]);

    //����� ���� �Լ��� ���� ����
    sort(numbers_str.begin(), numbers_str.end(), comp_str);
    //���� ���ڿ� ���ϱ�
    for (auto n : numbers_str)
        answer += n;
    //���� �Ǿ��ڸ���(answer[0])�� 0�̶�� ��� ����� 0 �� 00000 Ȥ�� 0�� ��� �̹Ƿ� 0���� ��ȯ
    if (answer[0] == '0')
        answer = "0";
    //�� ��ȯ
    return answer;
}