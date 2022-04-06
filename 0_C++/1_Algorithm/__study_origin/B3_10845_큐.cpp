/*
https://www.acmicpc.net/problem/10845
����
������ �����ϴ� ť�� ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.

����� �� ���� �����̴�.

push X: ���� X�� ť�� �ִ� �����̴�.
pop: ť���� ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ť�� ����ִ� ������ ������ ����Ѵ�.
empty: ť�� ��������� 1, �ƴϸ� 0�� ����Ѵ�.
front: ť�� ���� �տ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
back: ť�� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
�Է�
ù° �ٿ� �־����� ����� �� N (1 �� N �� 10,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ����� �ϳ��� �־�����. �־����� ������ 1���� ũ�ų� ����, 100,000���� �۰ų� ����. ������ �������� ���� ����� �־����� ���� ����.

���
����ؾ��ϴ� ����� �־��� ������, �� �ٿ� �ϳ��� ����Ѵ�.
*/
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	int N, x;
	string cmd;
	int queue[100000] = { 0, };
	int tempQueue[99999] = { 0, };
	int index = 0;

	cin >> N;
	while (N--)
	{
		cin >> cmd;
		if (cmd == "push")
		{
			cin >> x;
			queue[index++] = x;
		}
		else if (cmd == "pop")
		{
			if (!index)
				cout << "-1" << endl;
			else 
			{
				cout << queue[0]<<endl;
				index--;
				memcpy(tempQueue, queue+1, sizeof(int) * index);
				memcpy(queue, tempQueue, sizeof(int) * index);
			}
		}
		else if (cmd == "size")
		{
			cout << index << endl;
		}
		else if (cmd == "empty")
		{
			if (!index)
				cout << "1" << endl;
			else
				cout << "0" << endl;
		}
		else if (cmd == "front")
		{
			if (!index)
				cout << "-1" << endl;
			else
				cout << queue[0] << endl;
		}
		else if (cmd == "back")
		{
			if (!index)
				cout << "-1" << endl;
			else
				cout << queue[index-1] << endl;
		}
	}
	return 0;
}

