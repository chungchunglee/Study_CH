/*https://www.acmicpc.net/problem/10430
* ������
�ð� ����	�޸� ����	����	����	���� ���	���� ����
1 ��	256 MB	209119	112733	99626	54.679%
����
(A+B)%C�� ((A%C) + (B%C))%C �� ������?

(A��B)%C�� ((A%C) �� (B%C))%C �� ������?

�� �� A, B, C�� �־����� ��, ���� �� ���� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� A, B, C�� ������� �־�����. (2 �� A, B, C �� 10000)

���
ù° �ٿ� (A+B)%C, ��° �ٿ� ((A%C) + (B%C))%C, ��° �ٿ� (A��B)%C, ��° �ٿ� ((A%C) �� (B%C))%C�� ����Ѵ�.

���� �Է� 1 
5 8 4
���� ��� 1 
1
1
0
0
*/
#include <iostream>
using namespace std;
int main()
{
	int A, B, C;
	cin >> A >> B >> C;
	cout << (A + B) % C<< endl;
	cout << ((A % C) + (B % C)) % C << endl;
	cout << (A * B) % C << endl;
	cout << ((A % C) * (B % C)) % C << endl;
	return 0;
}