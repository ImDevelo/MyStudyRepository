//
//https://www.acmicpc.net/problem/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int V; // 노드 수
    vector<vector<int>> adjList; // 인접 리스트

public:
    Graph(int vertices) : V(vertices) {
        adjList.resize(V);
    }

    // 무방향 그래프를 가정하고 간선을 추가합니다.
    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src); // 무방향 그래프에서는 양방향으로 연결합니다.
    }

    // DFS (깊이 우선 탐색)
    void DFS(int start) {
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
    }

    void DFSUtil(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    // BFS (너비 우선 탐색)
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            cout << node << " ";
            q.pop();

            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};



void MySolution(){
    Graph g(6); // 노드 수가 6인 그래프 생성

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);

    cout << "DFS 탐색 결과: ";
    g.DFS(0);
    cout << endl;

    cout << "BFS 탐색 결과: ";
    g.BFS(0);
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
}