/*https://www.acmicpc.net/problem/2609
* 최대공약수와 최소공배수
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	128 MB	58746	34559	28009	59.935%
문제
두 개의 자연수를 입력받아 최대 공약수와 최소 공배수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에는 두 개의 자연수가 주어진다. 이 둘은 10,000이하의 자연수이며 사이에 한 칸의 공백이 주어진다.

출력
첫째 줄에는 입력으로 주어진 두 수의 최대공약수를, 둘째 줄에는 입력으로 주어진 두 수의 최소 공배수를 출력한다.

예제 입력 1 
24 18
예제 출력 1 
6
72
*/
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if (!a % b)
		return b;
	else
		gcd(a % b, b);
}

int main()
{
	int input_1, input_2;
	cin >> input_1 >> input_2;

	int gcm = 1, lcm = 1;
	if (input_1 > input_2)
	{
		int temp = input_1;
		input_1 = input_2;
		input_2 = temp;
	}
	for (int j = input_1; j >= 1; j--)
	{
		if (input_1 % j == 0 && input_2 % j == 0)
		{
			gcm = j;
			lcm = input_1 * input_2 / gcm;
			cout << gcm << endl;
			cout << lcm << endl;
			break;
		}
	}
	return 0;
}