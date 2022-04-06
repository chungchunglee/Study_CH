/* B_9033
문제
문장이 주어졌을 때, 단어를 모두 뒤집어서 출력하는 프로그램을 작성하시오. 단, 단어의 순서는 바꿀 수 없다. 단어는 영어 알파벳으로만 이루어져 있다.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있으며, 문장이 하나 주어진다. 
단어의 길이는 최대 20, 문장의 길이는 최대 1000이다. 단어와 단어 사이에는 공백이 하나 있다.

출력
각 테스트 케이스에 대해서, 입력으로 주어진 문장의 단어를 모두 뒤집어 출력한다.
*/
#include <iostream>
#include <string>
#include <stack>

using namespace std;
//stack을 이용한 구현

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




// 멍청식 구현 -  무식하게 swap함수를 구현하여 swapping 
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
		//뒤집는 로직 구현
		{
			string swapData = swapVoca(input, pos);
		
			// 처음이 아니라면 delimeter(" ")추가
			if (!bFirst)
				convertOutput += delimiter;
			else
				bFirst = false;
			//swapOutput에 뒤집은 단어 추가
			convertOutput += swapData;
		}
		//단어 자르는 로직 구현
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
	//delimeter를 기준으로 단어 뒤집기 - 양끝 반복
	for (int i = 0; i < pos / 2; i++)
	{
		swapVoca[pos - i - 1] = voca[i];
		swapVoca[i] = voca[pos - 1 - i];
	}
	return swapVoca;
}
*/
