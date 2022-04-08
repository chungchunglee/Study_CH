/*https://programmers.co.kr/learn/courses/30/lessons/43163
단어 변환
문제 설명
두 개의 단어 begin, target과 단어의 집합 words가 있습니다. 아래와 같은 규칙을 이용하여 begin에서 target으로 변환하는 가장 짧은 변환 과정을 찾으려고 합니다.

1. 한 번에 한 개의 알파벳만 바꿀 수 있습니다.
2. words에 있는 단어로만 변환할 수 있습니다.
예를 들어 begin이 "hit", target가 "cog", words가 ["hot","dot","dog","lot","log","cog"]라면 "hit" -> "hot" -> "dot" -> "dog" -> "cog"와 같이 4단계를 거쳐 변환할 수 있습니다.

두 개의 단어 begin, target과 단어의 집합 words가 매개변수로 주어질 때, 최소 몇 단계의 과정을 거쳐 begin을 target으로 변환할 수 있는지 return 하도록 solution 함수를 작성해주세요.

제한사항
각 단어는 알파벳 소문자로만 이루어져 있습니다.
각 단어의 길이는 3 이상 10 이하이며 모든 단어의 길이는 같습니다.
words에는 3개 이상 50개 이하의 단어가 있으며 중복되는 단어는 없습니다.
begin과 target은 같지 않습니다.
변환할 수 없는 경우에는 0를 return 합니다.
입출력 예
begin	target	words	return
"hit","cog",	{"hot", "dot", "dog", "lot", "log", "cog"}	4
"hit","cog",	{"hot", "dot", "dog", "lot", "log"}	            0
입출력 예 설명
예제 #1
문제에 나온 예와 같습니다.

예제 #2
target인 "cog"는 words 안에 없기 때문에 변환할 수 없습니다.
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int min_v = 50;

bool comp_str(string a, string b)
{
    int dif = 0;
    for (int i = 0; i < a.size(); i++)
        if (a[i] != b[i])
            if (++dif > 1) return false;
    return true;
}

void DFS(string& from, string& target, vector<string>& words, vector<int> visited, int step)
{
    //현재 까지 구한 답 보다 깊이 탐색할 경우 return
    if (min_v <= step)
        return;
    // 정답 판별
    if (from == target)
    {
        min_v = min(min_v, step);
        return;
    }
    for (int i = 0; i < words.size(); i++)
    {
        if (visited[i] == 1 || !comp_str(from,words[i]))
            continue;

        visited[i] = 1;
        DFS(words[i], target, words, visited, step+1);
        visited[i] = 0;
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    auto iter = find(words.begin(), words.end(), target);
    if (iter == words.end())
        return 0;
    vector<int> visited(words.size());
    DFS(begin, target, words, visited, answer);
    
    return min_v -1;
}
int main()
{
    int s1;
    s1 = solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" });
    s1 = solution("hit", "cog", { "hot", "dot", "dog", "lot", "log" });
    return 0;
}
#ifdef __OTHERS1__
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>

using namespace std;
class Graph;




class Graph {
private:
    enum { NON_CONNECT = 0, CONNECT = 1 };
    vector <vector<int>> adjacencyMatrix;
    int vertexCount;
    vector<bool> isvisited;
    unordered_map<int, string> idxToKeyMap;
    unordered_map<string, int> keyToidxMap;

    int generateIdxForKey = 0;
    int generateIdx() {
        int cur = generateIdxForKey;
        generateIdxForKey++;
        return cur;
    }

    void insertVertexToMaps(const string& vertex) {
        if (keyToidxMap.find(vertex) == keyToidxMap.end()) {
            int idx = generateIdx();
            keyToidxMap[vertex] = idx;
            idxToKeyMap[idx] = vertex;
        }
    }

    class Payload {
    public:
        int level;
        Payload(int level) {
            this->level = level;
        }
    };

    void BFS(int startVtxId, int startLevel) {
        queue<int> bfsQueue;
        queue<Payload> payloadQueue;
        bfsQueue.push(startVtxId);
        payloadQueue.push(Payload(startLevel));
        isvisited[startVtxId] = true;
        DoVisited(startVtxId, startLevel);
        while (!bfsQueue.empty()) {

            int vertexId = bfsQueue.front(); Payload payload = payloadQueue.front();
            bfsQueue.pop(); payloadQueue.pop();
            auto adjacents = GetAdjacents(vertexId);

            for (auto adjacentVtxId : adjacents) {
                if (!isvisited[adjacentVtxId]) {
                    isvisited[adjacentVtxId] = true;
                    DoVisited(adjacentVtxId, payload.level + 1);
                    bfsQueue.push(adjacentVtxId);
                    payloadQueue.push(Payload(payload.level + 1));
                }
            }

        }
    }


    void DFS(int vertexId, int level) {
        isvisited[vertexId] = true;
        DoVisited(vertexId, level);
        auto adjacents = GetAdjacents(vertexId);
        for (auto adjacentVtxId : adjacents) {
            if (!isvisited[adjacentVtxId]) {
                DFS(adjacentVtxId, level + 1);
            }
        }

    }
    //컴파일러최적화 복사반환X (int , vector<int>& dest)와같음
    vector<int> GetAdjacents(int vertexId) {
        vector<int> adjacents;
        for (int i = 0; i < vertexCount; i++) {
            if (adjacencyMatrix[vertexId][i] == CONNECT) {
                adjacents.push_back(i);
            }
        }
        return adjacents;
    }

    void InitVisited() {
        std::fill(isvisited.begin(), isvisited.end(), false);
    }

    void DoVisited(int vertexId, int level) {
        cout << "visited" << vertexId << endl;
        if (vertexId == endIdx) {
            if (minimulPath > level) {
                minimulPath = level;
            }
        }
    }

public:
    Graph(int vertexCount) {
        adjacencyMatrix = vector<vector<int>>(vertexCount, vector<int>(vertexCount));
        isvisited = vector<bool>(vertexCount);
        this->vertexCount = vertexCount;
    }

    void insertEdge(string vertexId1, string vertexId2) {
        int vertexIdx1, vertexIdx2;
        vertexIdx1 = keyToidxMap[vertexId1];
        vertexIdx2 = keyToidxMap[vertexId2];
        adjacencyMatrix[vertexIdx1][vertexIdx2] = CONNECT;
        adjacencyMatrix[vertexIdx2][vertexIdx1] = CONNECT;
    }

    void insertVertex(string vertexId) {
        insertVertexToMaps(vertexId);
    }


    void SolveBFS() {
        InitVisited();
        for (int vertexId = 0; vertexId < vertexCount; vertexId++) {
            if (!isvisited[vertexId]) {
                int level = 0;
                BFS(vertexId, level);
            }
        }
    }
    void SolveDFS() {
        InitVisited();
        for (int vertexId = 0; vertexId < vertexCount; vertexId++) {
            if (!isvisited[vertexId]) {
                int level = 0;
                DFS(vertexId, level);
            }
        }
    }

    int minimulPath = 999999999;
    int endIdx;
    void setEnd(const string& end) {
        endIdx = -1;
        if (keyToidxMap.find(end) != keyToidxMap.end()) {
            this->endIdx = keyToidxMap[end];
        }
    }
    void SolveBFS2(const string& begin) {
        InitVisited();
        BFS(keyToidxMap[begin], 0);
    }

    bool isContainVertex(const string& a) {
        if (keyToidxMap.find(a) != keyToidxMap.end()) {
            return true;
        }
        return false;
    }
};


bool isConnected(const string& a, const string& b) {
    int difCount = 0;//몇개다른지체크
    for (int i = 0; i < a.size(); i++) {
        char c = a[i] - b[i];
        if (c != 0) {
            difCount++;
            if (difCount > 1)
                return false;
        }

    }
    return true;
}



int solution(string begin, string target, vector<string> words) {
    words.push_back(begin);
    Graph graph(words.size());
    for (const auto& word : words) {
        graph.insertVertex(word);
    }
    for (int i = 0; i < words.size(); i++) {
        for (int j = i + 1; j < words.size(); j++) {
            if (isConnected(words[i], words[j])) {
                graph.insertEdge(words[i], words[j]);
            }
        }
    }

    graph.setEnd(target);
    graph.SolveBFS2(begin);

    int answer = 0;
    if (graph.minimulPath != 999999999)
        answer = graph.minimulPath;

    return answer;
}

#endif // __OTHERS1__
#ifdef __OTHERS2__
#include <string>
#include <vector>
#include <queue>

using namespace std;

int visited[50];

int possible(string a, string b)
{
    int i;
    int cnt = 0;

    for (i = 0; i < a.length(); i++)
    {
        if (a[i] != b[i]) cnt++;
    }

    if (cnt == 1) return 1;
    else return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue<pair<string, int>> Q;
    int i;
    string temp;
    int num;

    Q.push(make_pair(begin, 0));
    while (!Q.empty())
    {
        temp = Q.front().first;
        num = Q.front().second;
        Q.pop();

        if (temp.compare(target) == 0)
        {
            answer = num;
            break;
        }

        for (i = 0; i < words.size(); i++)
        {
            if (visited[i]) continue;
            if (possible(temp, words[i]))
            {
                visited[i] = 1;
                Q.push(make_pair(words[i], num + 1));
            }
        }
    }

    return answer;
}
#endif
