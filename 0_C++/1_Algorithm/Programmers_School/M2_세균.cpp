/*
문제 설명
세균이 증식할 수 있는 rows행 columns열의 칸으로 구성된 격자가 있습니다. 각 칸은 최대 max_virus마리의 세균이 있을 수 있으며, 초기에는 이 격자에 아무런 세균이 없습니다. 당신은 일련의 쿼리 목록을 전달받았습니다. 하나의 쿼리는 r과 c 두 정수로 이루어져 있으며, 이는 r행 c열의 칸에서 "세균 증식"을 하라는 것을 의미합니다. 세균 증식이란 다음과 같습니다.

만약 r행 c열의 칸에 있는 세균이 max_virus마리 미만이라면, 세균을 1마리 더 늘립니다.
만약 r행 c열의 칸에 있는 세균이 max_virus마리라면, 이 칸에 인접한 상하좌우 모든 칸에서 "세균 증식"을 시킵니다. 이때,
세균 증식이 여러 칸에 걸쳐서 연쇄적으로 일어날 수 있습니다.
한 쿼리에서 동일한 칸에는 최대 한 번의 세균 증식만 일어납니다.
정수 rows, columns, max_virus, 그리고 쿼리를 의미하는 2차원 정수 배열 queries가 매개변수로 주어집니다. queries에 들어있는 쿼리들에 의한 세균 증식을 순서대로 실행시켰을 때, 격자의 최종 상태(각 칸에 세균이 몇 마리씩 있는지)를 2차원 정수 배열로 return 하도록 solution 함수를 완성해주세요.

제한사항
1 ≤ rows, columns ≤ 20
1 ≤ max_virus ≤ 100
1 ≤ queries의 행의 개수 ≤ 400
queries의 각 행은 [r,c] 2개의 정수로 이루어져 있으며, 이는 r행 c열에 세균 증식을 하라는 의미입니다.
1 ≤ r ≤ rows
1 ≤ c ≤ columns
return 해야 하는 배열의 행 길이 = rows
return 해야 하는 배열의 열 길이 = columns
입출력 예
rows	columns	max_virus	queries	result
3	4	2	[[3,2],[3,2],[2,2],[3,2],[1,4],[3,2],[2,3],[3,1]]	[[0,2,1,1],[2,2,2,1],[2,2,2,1]]
입출력 예 설명
입출력 예 #1

다음 그림은 주어진 쿼리대로 3행 4열의 격자에 세균 증식을 시키는 과정을 나타낸 것입니다.
ex1.png

빨간색 숫자는 쿼리가 해당 격자에 세균 증식을 시킨 것을 의미하며, 보라색 숫자는 해당 격자에 세균 증식이 연쇄적으로 발생했음을 의미합니다.
따라서, 격자의 최종 상태(각 칸에 세균이 몇 마리씩 있는지)인 [[0,2,1,1],[2,2,2,1],[2,2,2,1]]를 return 해야 합니다
*/
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int rows, int columns, int max_virus, vector<vector<int>> queries) {
    vector<vector<int>> answer;
    return answer;
}