/*https://www.acmicpc.net/problem/11656
* ���̻� �迭
�ð� ����	�޸� ����	����	����	���� ���	���� ����
1 ��	256 MB	15054	10338	8475	69.960%
����
���̻� �迭�� ���ڿ� S�� ��� ���̻縦 ���������� ������ ���� �迭�̴�.

baekjoon�� ���̻�� baekjoon, aekjoon, ekjoon, kjoon, joon, oon, on, n ���� �� 8������ �ְ�, �̸� ���������� �����ϸ�, aekjoon, baekjoon, ekjoon, joon, kjoon, n, on, oon�� �ȴ�.

���ڿ� S�� �־����� ��, ��� ���̻縦 ���������� ������ ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���ڿ� S�� �־�����. S�� ���ĺ� �ҹ��ڷθ� �̷���� �ְ�, ���̴� 1,000���� �۰ų� ����.

���
ù° �ٺ��� S�� ���̻縦 ���������� �� �ٿ� �ϳ��� ����Ѵ�.

���� �Է� 1 
baekjoon
���� ��� 1 
aekjoon
baekjoon
ekjoon
joon
kjoon
n
on
oon
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<string> str_data_v;
	string str;
	cin >> str;
	for (int i = 0; i < (int)str.size(); i++)
		str_data_v.push_back(str.substr(i));
	sort(str_data_v.begin(), str_data_v.end());
	for (auto k : str_data_v)
		cout << k<<endl;
	return 0;
}