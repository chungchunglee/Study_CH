/*
https://www.acmicpc.net/problem/10820ㅋㅁ
문제
문자열 N개가 주어진다. 이때, 문자열에 포함되어 있는 소문자, 대문자, 숫자, 공백의 개수를 구하는 프로그램을 작성하시오.

각 문자열은 알파벳 소문자, 대문자, 숫자, 공백으로만 이루어져 있다.

입력
첫째 줄부터 N번째 줄까지 문자열이 주어진다. (1 ≤ N ≤ 100) 문자열의 길이는 100을 넘지 않는다.

출력
첫째 줄부터 N번째 줄까지 각각의 문자열에 대해서 소문자, 대문자, 숫자, 공백의 개수를 공백으로 구분해 출력한다.
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	while (getline(cin, str))
	{
		int _a = 0, _A = 0, _num = 0, _sp = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				_a++;
			else if (str[i] >= 'A' && str[i] <= 'Z')
				_A++;
			else if (str[i] >= '0' && str[i] <= '9')
				_num++;
			else if (str[i] == ' ')
				_sp++;
		}
		cout << _a << " " << _A << " " << _num << " " << _sp << endl;
	}
	return 0;
}