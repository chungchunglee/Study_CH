/*https://www.acmicpc.net/problem/1934
최소공배수
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	128 MB	38520	22005	18758	58.610%
문제
두 자연수 A와 B에 대해서, A의 배수이면서 B의 배수인 자연수를 A와 B의 공배수라고 한다. 이런 공배수 중에서 가장 작은 수를 최소공배수라고 한다. 예를 들어, 6과 15의 공배수는 30, 60, 90등이 있으며, 최소 공배수는 30이다.

두 자연수 A와 B가 주어졌을 때, A와 B의 최소공배수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 T(1 ≤ T ≤ 1,000)가 주어진다. 둘째 줄부터 T개의 줄에 걸쳐서 A와 B가 주어진다. (1 ≤ A, B ≤ 45,000)

출력
첫째 줄부터 T개의 줄에 A와 B의 최소공배수를 입력받은 순서대로 한 줄에 하나씩 출력한다.

예제 입력 1
3
1 45000
6 10
13 17
예제 출력 1
45000
30
221
*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int T;
	//입력부
	cin >> T;
	vector<pair<int, int>> tc(T);
	for (auto& k : tc)
		cin >> k.first >> k.second;
	//계산부
	//최대공약수
	int gcm = 1, lcm = 1;
	{
		for (int i = 0; i < T; i++)
		{
			if (tc[i].first > tc[i].second)
			{
				int temp = tc[i].first;
				tc[i].first = tc[i].second;
				tc[i].second = temp;
			}
			for (int j = tc[i].first; j >= 1; j--)
			{
				if (tc[i].first % j == 0 && tc[i].second % j == 0)
				{
					gcm = j;
					lcm = tc[i].first * tc[i].second / gcm;
					cout << lcm << endl;
					break;
				}
			}
		}
	}
	return 0;
}
#ifdef __OTHERS__
#include <iostream> using namespace std; // 최대공약수를 구하는 함수 (유클리드 호제법 이용)
int gcd(int a, int b) 
{ 
	int r = a % b; 
	if (r == 0) 
	{ 
		return b; 
	} 
	else 
	{ 
		return gcd(b, r); 
	} 
} 
int main() 
{
	int T;
	// 테스트 케이스의 개수 
	int A, B; int lcd; // 최소공배수 
	cin >> T;
	for (int i = 0; i < T; i++) 
	{
		cin >> A >> B; // 최소공배수 = (A x B) / 최대공약수
		lcd = (A * B) / (gcd(A, B)); cout << lcd << "\n";
	} 
	return 0;
}

#endif // __OTHERS__
