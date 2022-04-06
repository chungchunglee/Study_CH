/*
https://programmers.co.kr/learn/courses/30/lessons/42842
ī��
���� ����
Leo�� ī���� �緯 ���ٰ� �Ʒ� �׸��� ���� �߾ӿ��� ��������� ĥ���� �ְ� �׵θ� 1���� �������� ĥ���� �ִ� ���� ��� ī���� �ý��ϴ�.

carpet.png

Leo�� ������ ���ƿͼ� �Ʊ� �� ī���� ������� �������� ��ĥ�� ������ ������ ���������, ��ü ī���� ũ��� ������� ���߽��ϴ�.

Leo�� �� ī�꿡�� ���� ������ �� brown, ����� ������ �� yellow�� �Ű������� �־��� �� ī���� ����, ���� ũ�⸦ ������� �迭�� ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
���� ������ �� brown�� 8 �̻� 5,000 ������ �ڿ����Դϴ�.
����� ������ �� yellow�� 1 �̻� 2,000,000 ������ �ڿ����Դϴ�.
ī���� ���� ���̴� ���� ���̿� ���ų�, ���� ���̺��� ��ϴ�.
����� ��
brown	yellow	return
10	2	[4, 3]
8	1	[3, 3]
24	24	[8, 6]
��ó*/

/*
  ab-2a -2b +4 = yellow
  ab = brown +yellow
  brown + 4  = 2a + 2b
  */

#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
  
    int  a = sqrt(brown + yellow);
    int b = a;

    if (a * b == (brown + yellow) && (a - 2) * (b - 2) == yellow)
    {
        answer.push_back(a);
        answer.push_back(b);
    }
    else
    {
        while (a * b != (brown + yellow) && (a - 2) * (b - 2) != yellow)
        {
            a++;
            b = (brown + yellow) / a;
        }
        answer.push_back(a);
        answer.push_back(b);
    }

    return answer;
}
#ifdef __OTHERS__
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {

    int len = brown / 2 + 2;

    int w = len - 3;
    int h = 3;

    while (w >= h) {
        if (w * h == (brown + red)) break;

        w--;
        h++;
    }

    return vector<int>{w, h};
}
#endif // 
