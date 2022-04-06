/* B_10828
������ �����ϴ� ������ ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.

����� �� �ټ� �����̴�.

- push X: ���� X�� ���ÿ� �ִ� �����̴�.
- pop: ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
- size: ���ÿ� ����ִ� ������ ������ ����Ѵ�.
- empty: ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
- top: ������ ���� ���� �ִ� ������ ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.

ù° �ٿ� �־����� ����� �� N (1 �� N �� 10,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ����� �ϳ��� �־�����. �־����� ������ 1���� ũ�ų� ����, 100,000���� �۰ų� ����. ������ �������� ���� ����� �־����� ���� ����.
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
	/* �����Ҵ� �̿��� version
		int inputCmd;	 //Cmd ���� = N
	string inputData;	//��ɾ� - ex) push, pop, ...etc
	int* stackA; //���� ���� ����
	int countNum = 0;

	cin >> inputCmd;
	stackA = new int(inputCmd);
	cin.ignore();

	while (inputCmd--)
	{
		cin >> inputData;
		
		getline(cin, inputData);

		if (inputData == "pop")
		{
			if (countNum)
			{
				cout << stackA[countNum - 1] << endl;
				stackA[countNum - 1] = 0;
				countNum--;
			}
			else
			{
				cout << "-1" << endl;
			}
		}
		else if (inputData == "size")
		{
			cout << countNum << endl;
		}
		else if (inputData == "empty")
		{
			if (countNum)
				cout << "0" << endl;
			else
				cout << "1" << endl;
		}
		else if (inputData == "top")
		{
			if (countNum)
			{
				cout << stackA[countNum - 1] << endl;
			}
			else
			{
				cout << "-1" << endl;
			}
		}
		else // push X
		{
			//int popNum;
			//cin >> popNum;
			countNum++;
			stackA[countNum - 1] = stoi(inputData.substr(5));
			//stackA[countNum - 1] = popNum;
		}
	}
	return 0;
	*/
	int inputCmd;	 //Cmd ���� = N
	string inputData;	//��ɾ� - ex) push, pop, ...etc
	int stackA[10001]; //���� ���� ����
	int countNum = 0;

	cin >> inputCmd;

	while (inputCmd--)
	{
		cin >> inputData;

		if (inputData == "pop")
		{
			if (countNum)
			{
				cout << stackA[countNum - 1] << endl;
				stackA[countNum - 1] = 0;
				countNum--;
			}
			else
			{
				cout << "-1" << endl;
			}
		}
		else if (inputData == "size")
		{
			cout << countNum << endl;
		}
		else if (inputData == "empty")
		{
			if (countNum)
				cout << "0" << endl;
			else
				cout << "1" << endl;
		}
		else if (inputData == "top")
		{
			if (countNum)
			{
				cout << stackA[countNum - 1] << endl;
			}
			else
			{
				cout << "-1" << endl;
			}
		}
		else // push X
		{
			int popNum;
			cin >> popNum;
			countNum++;
			stackA[countNum - 1] = popNum;
		}
	}
	return 0;
}

