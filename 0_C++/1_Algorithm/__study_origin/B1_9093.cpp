/* B_9033
����
������ �־����� ��, �ܾ ��� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. ��, �ܾ��� ������ �ٲ� �� ����. �ܾ�� ���� ���ĺ����θ� �̷���� �ִ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����. �� �׽�Ʈ ���̽��� �� �ٷ� �̷���� ������, ������ �ϳ� �־�����. 
�ܾ��� ���̴� �ִ� 20, ������ ���̴� �ִ� 1000�̴�. �ܾ�� �ܾ� ���̿��� ������ �ϳ� �ִ�.

���
�� �׽�Ʈ ���̽��� ���ؼ�, �Է����� �־��� ������ �ܾ ��� ������ ����Ѵ�.
*/
#include <iostream>
#include <string>
#include <stack>

using namespace std;
//stack�� �̿��� ����

int main()
{
	int T;
	string input;
	
	cin >> T;
	cin.ignore();
	while (T--)
	{
		string sentence;
		stack<char> testCase;

		getline(cin, input);
		input += " ";
		for (int i = 0; i < input.length()+1; i++)
		{
			if (input[i] == ' ')
			{
				while(!testCase.empty())
				{
					sentence += testCase.top();
					testCase.pop();
				}
				sentence += " ";
			}
			else
				testCase.push(input[i]);
		}
		
		cout << sentence << endl;
	}
	return 0;
}




// ��û�� ���� -  �����ϰ� swap�Լ��� �����Ͽ� swapping 
/*
string convertData(string input);
string swapVoca(string voca, size_t pos);

int main()
{
	int testCaseNum = 0;
	string testCase;
	int Num = 0;
	int i = 0;

	cin >> testCaseNum;
	cin.ignore();
	while (testCaseNum--)
	{
		getline(cin, testCase);
		cout << convertData(testCase) << endl;
	}

	return 0;
}

string convertData(string input)
{
	string convertOutput = "";
	
	string delimiter = " ";
	size_t tempPos = 0;
	size_t pos = 0;
	bool bFirst = true;

	while ((pos = input.find(delimiter)) != string::npos)
	{
		//������ ���� ����
		{
			string swapData = swapVoca(input, pos);
		
			// ó���� �ƴ϶�� delimeter(" ")�߰�
			if (!bFirst)
				convertOutput += delimiter;
			else
				bFirst = false;
			//swapOutput�� ������ �ܾ� �߰�
			convertOutput += swapData;
		}
		//�ܾ� �ڸ��� ���� ����
		input.erase(0,pos+1);
	}
	if(bFirst)
		convertOutput += swapVoca(input, input.length());
	else
		convertOutput += " " + swapVoca(input, input.length());
	return convertOutput;
}
string swapVoca(string voca, size_t pos)
{
	string swapVoca = voca.substr(0, pos);
	//delimeter�� �������� �ܾ� ������ - �糡 �ݺ�
	for (int i = 0; i < pos / 2; i++)
	{
		swapVoca[pos - i - 1] = voca[i];
		swapVoca[i] = voca[pos - 1 - i];
	}
	return swapVoca;
}
*/
