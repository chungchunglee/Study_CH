/*https://programmers.co.kr/learn/courses/30/lessons/42839
* 소수 찾기
문제 설명
한자리 숫자가 적힌 종이 조각이 흩어져있습니다. 흩어진 종이 조각을 붙여 소수를 몇 개 만들 수 있는지 알아내려 합니다.

각 종이 조각에 적힌 숫자가 적힌 문자열 numbers가 주어졌을 때, 종이 조각으로 만들 수 있는 소수가 몇 개인지 return 하도록 solution 함수를 완성해주세요.

제한사항
numbers는 길이 1 이상 7 이하인 문자열입니다.
numbers는 0~9까지 숫자만으로 이루어져 있습니다.
"013"은 0, 1, 3 숫자가 적힌 종이 조각이 흩어져있다는 의미입니다.
입출력 예
numbers	return
"17"	3
"011"	2
입출력 예 설명
예제 #1
[1, 7]으로는 소수 [7, 17, 71]를 만들 수 있습니다.

예제 #2
[0, 1, 1]으로는 소수 [11, 101]를 만들 수 있습니다.

11과 011은 같은 숫자로 취급합니다.
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