/*P1
* ���� ����
������ ������ �������� �����濡 �����Ͽ����ϴ�. �� �� ���� ������ �����ϰ�� ��� ������ �������� �����Ͽ����ϴ�.

�����濡 ������ �������� �̸��� ��� �迭 participant�� ������ �������� �̸��� ��� �迭 completion�� �־��� ��, �������� ���� ������ �̸��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
������ ��⿡ ������ ������ ���� 1�� �̻� 100,000�� �����Դϴ�.
completion�� ���̴� participant�� ���̺��� 1 �۽��ϴ�.
�������� �̸��� 1�� �̻� 20�� ������ ���ĺ� �ҹ��ڷ� �̷���� �ֽ��ϴ�.
������ �߿��� ���������� ���� �� �ֽ��ϴ�.
����� ��
participant	completion	return
["leo", "kiki", "eden"]	["eden", "kiki"]	"leo"
["marina", "josipa", "nikola", "vinko", "filipa"]	["josipa", "filipa", "marina", "nikola"]	"vinko"
["mislav", "stanko", "mislav", "ana"]	["stanko", "ana", "mislav"]	"mislav"
����� �� ����
���� #1
"leo"�� ������ ��ܿ��� ������, ������ ��ܿ��� ���� ������ �������� ���߽��ϴ�.

���� #2
"vinko"�� ������ ��ܿ��� ������, ������ ��ܿ��� ���� ������ �������� ���߽��ϴ�.

���� #3
"mislav"�� ������ ��ܿ��� �� ���� ������, ������ ��ܿ��� �� ��ۿ� ���� ������ �Ѹ��� �������� ���߽��ϴ�.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {

    //������ �̿��� Ǯ��
    /*
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for(int i = 0 ; i < completion.size() ; i++)
    {
        if(participant[i] != completion[i])
            return participant[i];
    }
    */

    //�ؽ����̺� �̿��� Ǯ��
    string answer = ""; // ���ϰ��� �����ϴ� ����.
    unordered_map<string, int> playerMap; // string(key��)�� ������ �̸�, int(value��)�� ������ ��.

    for (int i = 0; i < participant.size(); i++)   // for������ �������� Ž��.
    {
        if (!playerMap.count(participant[i]))
            playerMap[participant[i]] = 1;
        else
            playerMap[participant[i]]++;
    }
    for (int i = 0; i < completion.size(); i++)
    {
        auto playerComp = playerMap.find(completion[i]);
        playerComp->second--;
    }
    for (auto i = playerMap.begin(); i != playerMap.end(); i++)
    {
        if (i->second != 0)
            return i->first;
    }

}