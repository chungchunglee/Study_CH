//https://www.acmicpc.net/problem/17413
/*
* ����
���ڿ� S�� �־����� ��, �� ���ڿ����� �ܾ ���������� �Ѵ�.

����, ���ڿ� S�� �Ʒ��Ͱ� ���� ��Ģ�� ��Ų��.

���ĺ� �ҹ���('a'-'z'), ����('0'-'9'), ����(' '), Ư�� ����('<', '>')�θ� �̷���� �ִ�.
���ڿ��� ���۰� ���� ������ �ƴϴ�.
'<'�� '>'�� ���ڿ��� �ִ� ��� �����ư��鼭 �����ϸ�, '<'�� ���� �����Ѵ�. ��, �� ������ ������ ����.
�±״� '<'�� �����ؼ� '>'�� ������ ���̰� 3 �̻��� �κ� ���ڿ��̰�, '<'�� '>' ���̿��� ���ĺ� �ҹ��ڿ� ���鸸 �ִ�. �ܾ�� ���ĺ� �ҹ��ڿ� ���ڷ� �̷���� �κ� ���ڿ��̰�, 
�����ϴ� �� �ܾ�� ���� �ϳ��� �����Ѵ�. �±״� �ܾ �ƴϸ�, �±׿� �ܾ� ���̿��� ������ ����.

�Է�
ù° �ٿ� ���ڿ� S�� �־�����. S�� ���̴� 100,000 �����̴�.

���
ù° �ٿ� ���ڿ� S�� �ܾ ����� ����Ѵ�.

���� �Է� 1 
baekjoon online judge
���� ��� 1 
noojkeab enilno egduj
*/
#include <string>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

int main()
{
	string S;
	string S2;
	char temp;
	stack<char> reverse;
	bool bReverse_stack = true;
	getline(cin, S);

	for (int i = 0; i<int(S.size()); i++)
	{
		if (!bReverse_stack || S[i] == '<' )
		{
			while (!reverse.empty())
			{
				S2 += reverse.top();
				reverse.pop();
			}
			S2 += S[i];
			bReverse_stack= false;
			if (S[i] == '>')
				bReverse_stack = true;
			continue;
		}
		if (S[i] == ' ')
		{
			while (!reverse.empty())
			{
				S2 += reverse.top();
				reverse.pop();
			}
			S2 += ' ';
			continue;
		}
		reverse.push(S[i]);
	}
	while (!reverse.empty())
	{
		S2 += reverse.top();
		reverse.pop();
	}
	cout << S2;
	return 0;
}