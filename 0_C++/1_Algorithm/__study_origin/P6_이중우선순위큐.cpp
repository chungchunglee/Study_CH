/*https://programmers.co.kr/learn/courses/30/lessons/42628
���߿켱����ť
���� ����
���� �켱���� ť�� ���� ������ �� �� �ִ� �ڷᱸ���� ���մϴ�.

��ɾ�	���� ž(����)
I ����	ť�� �־��� ���ڸ� �����մϴ�.
D 1	ť���� �ִ��� �����մϴ�.
D -1	ť���� �ּڰ��� �����մϴ�.
���� �켱���� ť�� �� ���� operations�� �Ű������� �־��� ��, ��� ������ ó���� �� ť�� ��������� [0,0] ������� ������ [�ִ�, �ּڰ�]�� return �ϵ��� solution �Լ��� �������ּ���.

���ѻ���
operations�� ���̰� 1 �̻� 1,000,000 ������ ���ڿ� �迭�Դϴ�.
operations�� ���Ҵ� ť�� ������ ������ ��Ÿ���ϴ�.
���Ҵ� ����ɾ� �����͡� �������� �־����ϴ�.- �ִ�/�ּڰ��� �����ϴ� ���꿡�� �ִ�/�ּڰ��� �� �̻��� ���, �ϳ��� �����մϴ�.
�� ť�� �����͸� �����϶�� ������ �־��� ���, �ش� ������ �����մϴ�.
����� ��
operations	return
["I 16","D 1"]	[0,0]
["I 7","I 5","I -5","D -1"]	[7,5]
����� �� ����
16�� ���� �� �ִ��� �����մϴ�. ��������Ƿ� [0,0]�� ��ȯ�մϴ�.
7,5,-5�� ���� �� �ּڰ��� �����մϴ�. �ִ밪 7, �ּҰ� 5�� ��ȯ�մϴ�.
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> operations) 
{
    vector<int> answer;

    for (int i = 0; i<int(operations.size()); i++)
    {
        int temp = 0;
        if (operations[i][0] == 'I')
        {
            temp = stoi(operations[i].substr(2));
            answer.push_back(temp);
        }
        else if(operations[i] == "D 1" && !answer.empty())
        {
            answer.pop_back();
        }
        else if (operations[i] == "D -1" && !answer.empty())
        {
           answer.erase(answer.begin());
        }

        if (!answer.empty())
            sort(answer.begin(), answer.end());
    }

    if (answer.empty())
        return { 0,0 };
    else if (answer.size() == 1)
        return { answer[0],answer[0] };
    else
        return { answer.back(),answer.front() };
}