/*P1
���� ����
��ȭ��ȣ�ο� ���� ��ȭ��ȣ ��, �� ��ȣ�� �ٸ� ��ȣ�� ���ξ��� ��찡 �ִ��� Ȯ���Ϸ� �մϴ�.
��ȭ��ȣ�� ������ ���� ���, ������ ��ȭ��ȣ�� �������� ��ȭ��ȣ�� ���λ��Դϴ�.

������ : 119
���ؿ� : 97 674 223
������ : 11 9552 4421
��ȭ��ȣ�ο� ���� ��ȭ��ȣ�� ���� �迭 phone_book �� solution �Լ��� �Ű������� �־��� ��, � ��ȣ�� �ٸ� ��ȣ�� ���ξ��� ��찡 ������ false�� �׷��� ������ true�� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���� ����
phone_book�� ���̴� 1 �̻� 1,000,000 �����Դϴ�.
�� ��ȭ��ȣ�� ���̴� 1 �̻� 20 �����Դϴ�.
���� ��ȭ��ȣ�� �ߺ��ؼ� ������� �ʽ��ϴ�.
����� ����
phone_book	return
["119", "97674223", "1195524421"]	false
["123","456","789"]	true
["12","123","1235","567","88"]	false
����� �� ����
����� �� #1
�տ��� ������ ���� �����ϴ�.

����� �� #2
�� ��ȣ�� �ٸ� ��ȣ�� ���λ��� ��찡 �����Ƿ�, ���� true�Դϴ�.

����� �� #3
ù ��° ��ȭ��ȣ, ��12���� �� ��° ��ȭ��ȣ ��123���� ���λ��Դϴ�. ���� ���� false�Դϴ�.

�˸�

2021�� 3�� 4��, �׽�Ʈ ���̽��� ����Ǿ����ϴ�. �̷� ���� ������ ����ϴ� �ڵ尡 �� �̻� ������� ���� �� �ֽ��ϴ�.
*/
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
//���İ� string�� �̿��� Ǯ��

bool solution(vector<string> phone_book)
{
    bool answer = true;
    int pSize = phone_book.size();
    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < pSize - 1; i++)
    {
        if (phone_book[i] == (phone_book[i + 1].substr(0, phone_book[i].length())))
            return false;
    }


    return answer;
}
/*
//�ؽø� ����� Ǯ��
bool solution(vector<string> phone_book)
{
    unordered_map<string,int> hash_map;
    int pSize = phone_book.size();

    for(int i =0;i < pSize; i++)
        hash_map[phone_book[i]] = 1;

    for(int i = 0; i< pSize; i++)
    {
        string phone_number = "";
        for(int j = 0; j < phone_book[i].size(); j++)
        {
            phone_number += phone_book[i][j];
            if(hash_map[phone_number] && (phone_number != phone_book[i]))
                return false;
        }
    }
    return true;
}
*/