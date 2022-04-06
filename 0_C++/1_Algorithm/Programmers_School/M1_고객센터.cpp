/*
���� ����
�� ���Ϳ��� "��㿹����"�� �ǽ��մϴ�. ��㿹������ ���� ���� ������ �Ϲ� ���� �������� ���� ó���ϴ� ����� ���մϴ�. ��㿹������ ������ ���� �������� �����մϴ�.

1. ���� �� �� ���� ������ ���� ������ ���� ó��
2. ���� ���� ������ ���� ������ �Ϲ� ���� ������ ó��
3. ��, ������ ������ �߰��� �ߴ����� ����
    - ��, �Ϲ� ���� ������ ó���ϴ� ���� ���� ���� �� ���, �Ϲ� �� ������ ���� �� ���� ���� ������ ó����
â���� �ϳ����̸� â������ ������ ó���ϴ� ������ 10���� �ɸ��ϴ�. �̶� â������ � �մ��� ������ ���� ó���ߴ��� �˾ƺ��� �մϴ�.
���� ��� ������ ���� �մ��� ���� ���

���� �ð�	�մ� �̸�	���� ����
09:00	kim	���� �� ��
09:05	bae	���� �� ��
09:10	lee	������
â���� ������ ���� ["kim", "lee", "bae"] ������ ������ ó���մϴ�.

09:00 ~ 09:10 �� kim�� ������ ó��
09:10 ~ 09:20 �� lee�� ������ ó��
09:20 ~ 09:30 �� bae�� ������ ó��

���� ���� ���� �ð��� �̸��� ���� �迭 booked, �Ϲ� ���� ���� �ð��� �̸��� ���� �迭 unbooked�� �Ű������� �־����ϴ�.
�̶� ���� �̸��� ������ ó���� ������ ���� �迭�� return �ϵ��� �Լ��� �ϼ����ּ���.

���ѻ���
booked�� ���̴� 1 �̻� 50 �����Դϴ�.
unbooked�� ���̴� 1 �̻� 50 �����Դϴ�.
booked �迭�� ���̿� unbooked �迭�� ���Ҵ� [hh:mm ������ ���� �ð�, �̸�] �����Դϴ�.
hh:mm�� "00:01" ~ "23:50" ���� �ȿ��� �־����ϴ�.
�̸��� ���̰� 1 �̻� 5 ������ ���ڿ��Դϴ�.
�̸��� ���ĺ� �ҹ��ڷθ� �̷���� �ֽ��ϴ�.
�� �迭�� ���� �ð� ������ ���ĵǾ� �ֽ��ϴ�.
���� �ð��� ���� ���� �����ϴ�.
booked, unbooked �迭���� ���� �Ϸ� ���� �� ���� ������ �־����ϴ�.
����� ��
booked	unbooked	result
[["09:10", "lee"]]	[["09:00", "kim"], ["09:05", "bae"]]	["kim", "lee", "bae"]
[["09:55", "hae"], ["10:05", "jee"]]	[["10:04", "hee"], ["14:07", "eom"]]	["hae", "jee", "hee", "eom"]
����� �� ����
����� �� #1

�ռ� ������ ���� �����ϴ�.

����� �� #2

09:55 ~ 10:05 �� hae�� ������ ó��
10:05 ~ 10:15 �� jee�� ������ ó��
10:15 ~ 10:25 �� hee�� ������ ó��
14:07 ~ 14:17 �� eom�� ������ ó��
*/
#include <string>
#include <vector>
#include <queue>

using namespace std;
//hh:mm �� int �������� ��ȯ
int time_converter(string t)
{
    int hour = stoi(t.substr(0, 2));
    int minute = stoi(t.substr(3, 2));
    return hour * 60 + minute;
}

vector<string> solution(vector<vector<string>> booked, vector<vector<string>> unbooked) {
    vector<string> answer;
    int booked_size = booked.size(), unbooked_size = unbooked.size();
    int total_size = booked_size + unbooked_size;
    queue<pair<int, string>> convert_booked, converted_unbooked;
    //<�ð�,�̸�> pair�� ������
    for (int i = 0; i < booked_size; i++)
        convert_booked.push(make_pair(time_converter(booked[i][0]), booked[i][1]));
    for (int i = 0; i < unbooked_size; i++)
        converted_unbooked.push(make_pair(time_converter(unbooked[i][0]), unbooked[i][1]));
    //���� �ð��� 1��
    int temp_time = 1;
    //ť �߿� �ϳ��� ��� �� ����� �ʿ���� �ݺ��� break -> ť�� �ð������� ���ĵǾ��ֱ⶧���� �����ϸ� �Ϸ�
    while (!convert_booked.empty() && !converted_unbooked.empty())
    {
        //�����ѻ���� �湮�ð��� ����ð����� ���� ��� -> answer�� �����ѻ�� push_back
        if (convert_booked.front().first <= temp_time)
        {
            answer.push_back(convert_booked.front().second);
            convert_booked.pop();
            temp_time += 10;
        }
        // �� ������ �ƴϸ鼭 ������ѻ���� �湮�ð��� ����ð����� ���� ��� -> answer�� ������ѻ�� push_back
        else if (converted_unbooked.front().first <= temp_time)
        {
            answer.push_back(converted_unbooked.front().second);
            converted_unbooked.pop();
            temp_time += 10;
        }
        //��� �ƴѰ�� time�� 10���ϱ� ���ٴ� �� ���� �ð��� �湮�ѻ������ ���� �ð� �ʱ�ȭ.(ó�� �ݺ��� ���ۿ��� �ش籸�� ����)
        else
        {
            if (convert_booked.front().first <= converted_unbooked.front().first)
            {
                answer.push_back(convert_booked.front().second);
                temp_time = convert_booked.front().first;
                convert_booked.pop();
            }
            else
            {
                answer.push_back(converted_unbooked.front().second);
                temp_time = converted_unbooked.front().first;
                converted_unbooked.pop();
            }
            temp_time += 10;
        }
    }
    //�ݺ��� break�� ���� ť ����
    while (!convert_booked.empty())
    {
        answer.push_back(convert_booked.front().second);
        convert_booked.pop();
    }
    while (!converted_unbooked.empty())
    {
        answer.push_back(converted_unbooked.front().second);
        converted_unbooked.pop();
    }
    return answer;
}

int main()
{
    //int a = time_converter("02:20");
    //{{"09:10", "lee"}}	{{"09:00", "kim"}, {"09:05", "bae"}}	["kim", "lee", "bae"]
    //{{"09:55", "hae"}, {"10:05", "jee"}} {{"10:04", "hee"}, {"14:07", "eom"}} ["hae", "jee", "hee", "eom"]
    vector<string> s1 = solution({ {"09:10", "lee"} }, { {"09:00", "kim"}, { "09:05", "bae" } });
    vector<string> s2 = solution({ {"07:05", "a"} , {"07:15", "b"}, {"07:16", "c"}, {"10:00", "jee"} }, { {"10:04", "hee"}, { "14:07", "eom" }});
    ;
    return 0;
}


/*
vector<string> solution(vector<vector<string>> booked, vector<vector<string>> unbooked) {
    vector<string> answer;
    int booked_size = booked.size(), unbooked_size = unbooked.size();
    int total_size = booked_size + unbooked_size;
    queue<pair<int, string>> booked_converted, unbooked_converted;

    for (int i = 0; i < booked_size; i++)
        booked_converted.push(make_pair(time_converter(booked[i][0]), booked[i][1]));
    for (int i = 0; i < unbooked_size; i++)
        unbooked_converted.push(make_pair(time_converter(unbooked[i][0]), unbooked[i][1]));

    int temp_time;
    if (booked_converted.front().first <= unbooked_converted.front().first)
    {
        answer.push_back(booked_converted.front().second);
        temp_time = booked_converted.front().first;
        booked_converted.pop();
    }
    else
    {
        answer.push_back(unbooked_converted.front().second);
        temp_time = unbooked_converted.front().first;
        unbooked_converted.pop();
    }
    temp_time += 10;

    while (!booked_converted.empty() && !unbooked_converted.empty())
    {
        if (booked_converted.front().first <= temp_time)
        {
            answer.push_back(booked_converted.front().second);
            booked_converted.pop();
        }
        else if (unbooked_converted.front().first <= temp_time)
        {
            answer.push_back(unbooked_converted.front().second);
            unbooked_converted.pop();
        }
        temp_time += 10;
    }
    while (!booked_converted.empty())
    {
        answer.push_back(booked_converted.front().second);
        booked_converted.pop();
    }
    while (!unbooked_converted.empty())
    {
        answer.push_back(unbooked_converted.front().second);
        unbooked_converted.pop();
    }
    return answer;
}
*/