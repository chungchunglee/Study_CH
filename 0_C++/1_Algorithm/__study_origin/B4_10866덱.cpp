/*https://www.acmicpc.net/problem/10866
* ����
������ �����ϴ� ��(Deque)�� ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.

����� �� ���� �����̴�.

push_front X: ���� X�� ���� �տ� �ִ´�.
push_back X: ���� X�� ���� �ڿ� �ִ´�.
pop_front: ���� ���� �տ� �ִ� ���� ����, �� ���� ����Ѵ�. ����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
pop_back: ���� ���� �ڿ� �ִ� ���� ����, �� ���� ����Ѵ�. ����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ���� ����ִ� ������ ������ ����Ѵ�.
empty: ���� ��������� 1��, �ƴϸ� 0�� ����Ѵ�.
front: ���� ���� �տ� �ִ� ������ ����Ѵ�. ���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
back: ���� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
�Է�
ù° �ٿ� �־����� ����� �� N (1 �� N �� 10,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ����� �ϳ��� �־�����. �־����� ������ 1���� ũ�ų� ����, 100,000���� �۰ų� ����. ������ �������� ���� ����� �־����� ���� ����.

���
����ؾ��ϴ� ����� �־��� ������, �� �ٿ� �ϳ��� ����Ѵ�.
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N, p, front_index = 0, end_index = 0;
	string cmd;

	cin >> N;
	int* M = new int[N] {};
	while (N--)
	{
		cin >> cmd;
		//push_front X : ���� X�� ���� �տ� �ִ´�.
		if (cmd == "push_front")
		{
			cin >> p;
			if (front_index != end_index) 
			{
				for (int i = end_index; i >= front_index; i--)
					M[i] = M[i - 1];
				M[front_index] = p;
				end_index++;
			}
			else
			{
				M[front_index] = p;
				end_index++;
			}
		}
		//push_back X : ���� X�� ���� �ڿ� �ִ´�.
		else if (cmd == "push_back")
		{
			cin >> p;
			end_index++;
			M[end_index - 1] = p;
		}
		//pop_front : ���� ���� �տ� �ִ� ���� ����, �� ���� ����Ѵ�.����, ���� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�.
		else if (cmd == "pop_front")
		{
			if (front_index == end_index)
				cout << "-1" << endl;
			else
			{
				cout << M[front_index] << endl;
				M[front_index] = NULL;
				front_index++;
			}
		}
		//pop_back : ���� ���� �ڿ� �ִ� ���� ����, �� ���� ����Ѵ�.����, ���� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�.
		else if (cmd == "pop_back")
		{
			if (front_index == end_index)
				cout << "-1" << endl;
			else
			{
				cout << M[end_index - 1] << endl;
				end_index--;
			}
		}
		//size : ���� ����ִ� ������ ������ ����Ѵ�.
		else if (cmd == "size")
			cout << end_index - front_index << endl;
		//empty : ���� ��������� 1��, �ƴϸ� 0�� ����Ѵ�.
		else if (cmd == "empty")
		{
			if (end_index - front_index)
				cout << "0" << endl;
			else
				cout << "1" << endl;
		}
		//front : ���� ���� �տ� �ִ� ������ ����Ѵ�.���� ���� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�.
		else if (cmd == "front")
		{
			if (front_index == end_index)
				cout << "-1" << endl;
			else
				cout << M[front_index] << endl;
		}
		//back : ���� ���� �ڿ� �ִ� ������ ����Ѵ�.���� ���� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�.
		else if (cmd == "back")
		{
			if (front_index == end_index)
				cout << "-1" << endl;
			else
				cout << M[end_index-1] << endl;
		}
	}
	delete[] M;
	return 0;
}