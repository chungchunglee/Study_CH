/*https://www.acmicpc.net/problem/2609
* �ִ������� �ּҰ����
�ð� ����	�޸� ����	����	����	���� ���	���� ����
1 ��	128 MB	58746	34559	28009	59.935%
����
�� ���� �ڿ����� �Է¹޾� �ִ� ������� �ּ� ������� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ��� �� ���� �ڿ����� �־�����. �� ���� 10,000������ �ڿ����̸� ���̿� �� ĭ�� ������ �־�����.

���
ù° �ٿ��� �Է����� �־��� �� ���� �ִ�������, ��° �ٿ��� �Է����� �־��� �� ���� �ּ� ������� ����Ѵ�.

���� �Է� 1 
24 18
���� ��� 1 
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