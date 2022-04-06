/*
문제 설명
고객 센터에서 "상담예약제"를 실시합니다. 상담예약제란 예약 고객의 업무를 일반 고객의 업무보다 먼저 처리하는 방식을 말합니다. 상담예약제는 다음과 같은 로직으로 동작합니다.

1. 예약 고객 중 먼저 도착한 고객의 업무를 먼저 처리
2. 예약 고객이 없으면 먼저 도착한 일반 고객의 업무를 처리
3. 단, 시작한 업무는 중간에 중단하지 않음
    - 즉, 일반 고객의 업무를 처리하는 도중 예약 고객이 온 경우, 일반 고객 업무를 끝낸 후 예약 고객의 업무를 처리함
창구는 하나뿐이며 창구에서 업무를 처리하는 데에는 10분이 걸립니다. 이때 창구에서 어떤 손님의 업무를 먼저 처리했는지 알아보려 합니다.
예를 들어 다음과 같이 손님이 들어온 경우

도착 시각	손님 이름	예약 여부
09:00	kim	예약 안 함
09:05	bae	예약 안 함
09:10	lee	예약함
창구는 다음과 같이 ["kim", "lee", "bae"] 순으로 업무를 처리합니다.

09:00 ~ 09:10 → kim의 업무를 처리
09:10 ~ 09:20 → lee의 업무를 처리
09:20 ~ 09:30 → bae의 업무를 처리

예약 고객의 도착 시각과 이름을 담은 배열 booked, 일반 고객의 도착 시각과 이름을 담은 배열 unbooked가 매개변수로 주어집니다.
이때 고객의 이름을 업무가 처리된 순으로 담은 배열을 return 하도록 함수를 완성해주세요.

제한사항
booked의 길이는 1 이상 50 이하입니다.
unbooked의 길이는 1 이상 50 이하입니다.
booked 배열의 길이와 unbooked 배열의 원소는 [hh:mm 형식의 도착 시각, 이름] 형식입니다.
hh:mm은 "00:01" ~ "23:50" 범위 안에서 주어집니다.
이름은 길이가 1 이상 5 이하인 문자열입니다.
이름은 알파벳 소문자로만 이루어져 있습니다.
각 배열은 도착 시각 순으로 정렬되어 있습니다.
도착 시각이 같은 고객은 없습니다.
booked, unbooked 배열에는 오늘 하루 동안 온 고객의 정보만 주어집니다.
입출력 예
booked	unbooked	result
[["09:10", "lee"]]	[["09:00", "kim"], ["09:05", "bae"]]	["kim", "lee", "bae"]
[["09:55", "hae"], ["10:05", "jee"]]	[["10:04", "hee"], ["14:07", "eom"]]	["hae", "jee", "hee", "eom"]
입출력 예 설명
입출력 예 #1

앞서 설명한 예와 같습니다.

입출력 예 #2

09:55 ~ 10:05 → hae의 업무를 처리
10:05 ~ 10:15 → jee의 업무를 처리
10:15 ~ 10:25 → hee의 업무를 처리
14:07 ~ 14:17 → eom의 업무를 처리
*/
#include <string>
#include <vector>
#include <queue>

using namespace std;
//hh:mm 을 int 형식으로 변환
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
    //<시간,이름> pair로 재정렬
    for (int i = 0; i < booked_size; i++)
        convert_booked.push(make_pair(time_converter(booked[i][0]), booked[i][1]));
    for (int i = 0; i < unbooked_size; i++)
        converted_unbooked.push(make_pair(time_converter(unbooked[i][0]), unbooked[i][1]));
    //시작 시간은 1분
    int temp_time = 1;
    //큐 중에 하나가 비면 더 계산할 필요없이 반복문 break -> 큐는 시간순으로 정렬되어있기때문에 나열하면 완료
    while (!convert_booked.empty() && !converted_unbooked.empty())
    {
        //예약한사람의 방문시간이 현재시간보다 적을 경우 -> answer에 예약한사람 push_back
        if (convert_booked.front().first <= temp_time)
        {
            answer.push_back(convert_booked.front().second);
            convert_booked.pop();
            temp_time += 10;
        }
        // 위 조건이 아니면서 예약안한사람의 방문시간이 현재시간보다 적을 경우 -> answer에 예약안한사람 push_back
        else if (converted_unbooked.front().first <= temp_time)
        {
            answer.push_back(converted_unbooked.front().second);
            converted_unbooked.pop();
            temp_time += 10;
        }
        //모두 아닌경우 time을 10더하기 보다는 그 다음 시간에 방문한사람으로 현재 시간 초기화.(처음 반복문 시작에도 해당구문 실행)
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
    //반복문 break시 남은 큐 비우기
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