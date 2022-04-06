/*https://www.acmicpc.net/problem/1934
�ּҰ����
�ð� ����	�޸� ����	����	����	���� ���	���� ����
1 ��	128 MB	38520	22005	18758	58.610%
����
�� �ڿ��� A�� B�� ���ؼ�, A�� ����̸鼭 B�� ����� �ڿ����� A�� B�� �������� �Ѵ�. �̷� ����� �߿��� ���� ���� ���� �ּҰ������� �Ѵ�. ���� ���, 6�� 15�� ������� 30, 60, 90���� ������, �ּ� ������� 30�̴�.

�� �ڿ��� A�� B�� �־����� ��, A�� B�� �ּҰ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� T(1 �� T �� 1,000)�� �־�����. ��° �ٺ��� T���� �ٿ� ���ļ� A�� B�� �־�����. (1 �� A, B �� 45,000)

���
ù° �ٺ��� T���� �ٿ� A�� B�� �ּҰ������ �Է¹��� ������� �� �ٿ� �ϳ��� ����Ѵ�.

���� �Է� 1
3
1 45000
6 10
13 17
���� ��� 1
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
	//�Էº�
	cin >> T;
	vector<pair<int, int>> tc(T);
	for (auto& k : tc)
		cin >> k.first >> k.second;
	//����
	//�ִ�����
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
#include <iostream> using namespace std; // �ִ������� ���ϴ� �Լ� (��Ŭ���� ȣ���� �̿�)
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
	// �׽�Ʈ ���̽��� ���� 
	int A, B; int lcd; // �ּҰ���� 
	cin >> T;
	for (int i = 0; i < T; i++) 
	{
		cin >> A >> B; // �ּҰ���� = (A x B) / �ִ�����
		lcd = (A * B) / (gcd(A, B)); cout << lcd << "\n";
	} 
	return 0;
}

#endif // __OTHERS__
