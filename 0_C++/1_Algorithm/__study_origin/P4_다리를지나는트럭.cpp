/*https://programmers.co.kr/learn/courses/30/lessons/42583
���� ����
Ʈ�� ���� �밡 ���� ���������� ������ �ٸ��� ������ ������ �ǳʷ� �մϴ�. ��� Ʈ���� �ٸ��� �ǳʷ��� �ּ� �� �ʰ� �ɸ����� �˾Ƴ��� �մϴ�.
�ٸ����� Ʈ���� �ִ� bridge_length�� �ö� �� ������, �ٸ��� weight ���ϱ����� ���Ը� �ߵ� �� �ֽ��ϴ�. 
��, �ٸ��� ������ ������ ���� Ʈ���� ���Դ� �����մϴ�.

���� ���, Ʈ�� 2�밡 �ö� �� �ְ� ���Ը� 10kg���� �ߵ�� �ٸ��� �ֽ��ϴ�.
���԰� [7, 4, 5, 6]kg�� Ʈ���� ������� �ִ� �ð� �ȿ� �ٸ��� �ǳʷ��� ������ ���� �ǳʾ� �մϴ�.

��� �ð�	�ٸ��� ���� Ʈ��	�ٸ��� �ǳʴ� Ʈ��	��� Ʈ��
0	[]	[]	[7,4,5,6]
1~2	[]	[7]	[4,5,6]
3	[7]	[4]	[5,6]
4	[7]	[4,5]	[6]
5	[7,4]	[5]	[6]
6~7	[7,4,5]	[6]	[]
8	[7,4,5,6]	[]	[]
����, ��� Ʈ���� �ٸ��� �������� �ּ� 8�ʰ� �ɸ��ϴ�.

solution �Լ��� �Ű������� �ٸ��� �ö� �� �ִ� Ʈ�� �� bridge_length, �ٸ��� �ߵ� �� �ִ� ���� weight,
Ʈ�� �� ���� truck_weights�� �־����ϴ�. �̶� ��� Ʈ���� �ٸ��� �ǳʷ��� �ּ� �� �ʰ� �ɸ����� return �ϵ��� solution �Լ��� �ϼ��ϼ���.

���� ����
bridge_length�� 1 �̻� 10,000 �����Դϴ�.
weight�� 1 �̻� 10,000 �����Դϴ�.
truck_weights�� ���̴� 1 �̻� 10,000 �����Դϴ�.
��� Ʈ���� ���Դ� 1 �̻� weight �����Դϴ�.
����� ��
bridge_length	weight	truck_weights	return
2	10	[7,4,5,6]	8
100	100	[10]	101
100	100	[10,10,10,10,10,10,10,10,10,10]	110
��ó

�� ���� - 2020�� 4�� 06�� �׽�Ʈ���̽��� �߰��Ǿ����ϴ�.
*/
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> bridge_status;
    int bridge_length_v = bridge_length;
    int weight_sum = 0;

    //Bridge Queue �ʱ�ȭ 
    while (bridge_length_v--)
        bridge_status.push(0);
    //Ʈ������ ��ȸ �� ť�� ����
    for (int i = 0; i < truck_weights.size(); i++)
    {
        //Ʈ���� ���� ���ѿ� �Ȱɸ������� ���� ���� ���鼭 �ð� ����
        while (1)
        {
            //�ð� ���� �� ť �Ǿ� ó��
            answer++;
            weight_sum -= bridge_status.front();
            bridge_status.pop();
            //Ʈ�� ���� ���� Ȯ���� ť ����
            if (weight >= (weight_sum + truck_weights[i]))
            {
                weight_sum += truck_weights[i];
                bridge_status.push(truck_weights[i]);
                break;
            }
            else
                bridge_status.push(0);
        }
    }
    //������ Ʈ���� ������ �ð� ����
    answer += bridge_length;

    return answer;
}