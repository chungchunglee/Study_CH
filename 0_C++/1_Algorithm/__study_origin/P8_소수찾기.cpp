/*https://programmers.co.kr/learn/courses/30/lessons/42839
* �Ҽ� ã��
���� ����
���ڸ� ���ڰ� ���� ���� ������ ������ֽ��ϴ�. ����� ���� ������ �ٿ� �Ҽ��� �� �� ���� �� �ִ��� �˾Ƴ��� �մϴ�.

�� ���� ������ ���� ���ڰ� ���� ���ڿ� numbers�� �־����� ��, ���� �������� ���� �� �ִ� �Ҽ��� �� ������ return �ϵ��� solution �Լ��� �ϼ����ּ���.

���ѻ���
numbers�� ���� 1 �̻� 7 ������ ���ڿ��Դϴ�.
numbers�� 0~9���� ���ڸ����� �̷���� �ֽ��ϴ�.
"013"�� 0, 1, 3 ���ڰ� ���� ���� ������ ������ִٴ� �ǹ��Դϴ�.
����� ��
numbers	return
"17"	3
"011"	2
����� �� ����
���� #1
[1, 7]���δ� �Ҽ� [7, 17, 71]�� ���� �� �ֽ��ϴ�.

���� #2
[0, 1, 1]���δ� �Ҽ� [11, 101]�� ���� �� �ֽ��ϴ�.

11�� 011�� ���� ���ڷ� ����մϴ�.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <iostream>

using namespace std;

vector<int> check_pNum(vector<int> input)
{
    vector<int> answer;
    for(int j = 0; j < input.size(); j++)
    {
        bool bP = true;
        if (input[j] <= 1)
            continue;
        
        for (int i = 2; i <= sqrt(input[j]); i++)
        {
            if (input[j] % i == 0)
            {
                bP = false;
                break;
            }
        }
        if (bP) answer.push_back(input[j]);
    }
    return answer;
}
vector<int> create_numbers(string numbers)
{
    unordered_set<int> nums;

    sort(numbers.begin(), numbers.end());
    do
    {
        for (int i = 1; i < numbers.size() + 1; i++)
        {
            nums.insert(stoi(numbers.substr(0, i)));
        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    vector<int> answer(nums.begin(), nums.end());
    return answer;
}


int solution(string numbers) {
    int answer = 0;
    
    vector<int> reroc_nums = create_numbers(numbers);
    vector<int> p_nums = check_pNum(reroc_nums);

    return p_nums.size();
}

int main()
{
    cout << solution("1230");

    return 0;
}