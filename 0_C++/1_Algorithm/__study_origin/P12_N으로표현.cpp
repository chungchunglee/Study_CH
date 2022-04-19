/*https://programmers.co.kr/learn/courses/30/lessons/42895
* N���� ǥ��
���� ����
�Ʒ��� ���� 5�� ��Ģ���길���� 12�� ǥ���� �� �ֽ��ϴ�.

12 = 5 + 5 + (5 / 5) + (5 / 5)
12 = 55 / 5 + 5 / 5
12 = (55 + 5) / 5

5�� ����� Ƚ���� ���� 6,5,4 �Դϴ�. �׸��� ���� ���� ���� ���� 4�Դϴ�.
��ó�� ���� N�� number�� �־��� ��, N�� ��Ģ���길 ����ؼ� ǥ�� �� �� �ִ� ��� �� N ���Ƚ���� �ּڰ��� return �ϵ��� solution �Լ��� �ۼ��ϼ���.

���ѻ���
N�� 1 �̻� 9 �����Դϴ�.
number�� 1 �̻� 32,000 �����Դϴ�.
���Ŀ��� ��ȣ�� ��Ģ���길 �����ϸ� ������ ���꿡�� �������� �����մϴ�.
�ּڰ��� 8���� ũ�� -1�� return �մϴ�.
����� ��
N	number	return
5	12	4
2	11	3
����� �� ����
���� #1
������ ���� ���� �����ϴ�.

���� #2
11 = 22 / 2�� ���� 2�� 3���� ����Ͽ� ǥ���� �� �ֽ��ϴ�.
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
