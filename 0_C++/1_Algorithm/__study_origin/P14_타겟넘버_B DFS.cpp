/*
https://programmers.co.kr/learn/courses/30/lessons/43165
Ÿ�� �ѹ�
���� ����
n���� ���� �ƴ� �������� �ֽ��ϴ�. �� �������� ������ �ٲ��� �ʰ� ������ ���ϰų� ���� Ÿ�� �ѹ��� ������� �մϴ�.
���� ��� [1, 1, 1, 1, 1]�� ���� 3�� ������� ���� �ټ� ����� �� �� �ֽ��ϴ�.

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3
����� �� �ִ� ���ڰ� ��� �迭 numbers, Ÿ�� �ѹ� target�� �Ű������� �־��� �� ���ڸ� ������ ���ϰ� ����
Ÿ�� �ѹ��� ����� ����� ���� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
�־����� ������ ������ 2�� �̻� 20�� �����Դϴ�.
�� ���ڴ� 1 �̻� 50 ������ �ڿ����Դϴ�.
Ÿ�� �ѹ��� 1 �̻� 1000 ������ �ڿ����Դϴ�.
����� ��
numbers	target	return
{1, 1, 1, 1, 1}	3	5
{4, 1, 2, 1]}	4	2
����� �� ����
����� �� #1

���� ���ÿ� �����ϴ�.

����� �� #2

+4+1-2+1 = 4
+4-1+2-1 = 4
�� 2���� ����� �����Ƿ�, 2�� return �մϴ�.
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

