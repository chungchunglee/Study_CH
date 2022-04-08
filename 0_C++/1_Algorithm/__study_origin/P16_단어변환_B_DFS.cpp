/*https://programmers.co.kr/learn/courses/30/lessons/43163
�ܾ� ��ȯ
���� ����
�� ���� �ܾ� begin, target�� �ܾ��� ���� words�� �ֽ��ϴ�. �Ʒ��� ���� ��Ģ�� �̿��Ͽ� begin���� target���� ��ȯ�ϴ� ���� ª�� ��ȯ ������ ã������ �մϴ�.

1. �� ���� �� ���� ���ĺ��� �ٲ� �� �ֽ��ϴ�.
2. words�� �ִ� �ܾ�θ� ��ȯ�� �� �ֽ��ϴ�.
���� ��� begin�� "hit", target�� "cog", words�� ["hot","dot","dog","lot","log","cog"]��� "hit" -> "hot" -> "dot" -> "dog" -> "cog"�� ���� 4�ܰ踦 ���� ��ȯ�� �� �ֽ��ϴ�.

�� ���� �ܾ� begin, target�� �ܾ��� ���� words�� �Ű������� �־��� ��, �ּ� �� �ܰ��� ������ ���� begin�� target���� ��ȯ�� �� �ִ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
�� �ܾ�� ���ĺ� �ҹ��ڷθ� �̷���� �ֽ��ϴ�.
�� �ܾ��� ���̴� 3 �̻� 10 �����̸� ��� �ܾ��� ���̴� �����ϴ�.
words���� 3�� �̻� 50�� ������ �ܾ ������ �ߺ��Ǵ� �ܾ�� �����ϴ�.
begin�� target�� ���� �ʽ��ϴ�.
��ȯ�� �� ���� ��쿡�� 0�� return �մϴ�.
����� ��
begin	target	words	return
"hit","cog",	{"hot", "dot", "dog", "lot", "log", "cog"}	4
"hit","cog",	{"hot", "dot", "dog", "lot", "log"}	            0
����� �� ����
���� #1
������ ���� ���� �����ϴ�.

���� #2
target�� "cog"�� words �ȿ� ���� ������ ��ȯ�� �� �����ϴ�.
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
    //���� ���� ���� �� ���� ���� Ž���� ��� return
    if (min_v <= step)
        return;
    // ���� �Ǻ�
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
    //�����Ϸ�����ȭ �����ȯX (int , vector<int>& dest)�Ͱ���
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
    int difCount = 0;//��ٸ���üũ
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
