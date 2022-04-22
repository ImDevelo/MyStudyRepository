#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

// 깊이 탐색 알고리즘
// 재귀 방식
void DFS_recursion(int start, vector<int> graph[], bool check[]) {
    check[start] = true;

    cout << start << " ";

    for (int i = 0; i < graph[start].size(); i++) {
        if (check[start] != false)
            DFS_recursion(start, graph, check);
    }

}

// 스택 방식
void DFS_stack(int start, vector<int> graph[], bool check[]) {
    stack<int> s;
    s.push(start);
    check[start] = true;

    cout << start << " ";

    int current_node = start;
    while (!s.empty())
    {
        current_node = s.top();
        //다음 노드를 탐색, 방문하였다면 패스 방문하지 않았다면 스택에 넣고 출력하고 끝냅니다.
        s.pop();

        for (int index = 0; index < graph[current_node].size(); index++) {
            int nextnode = graph[current_node][index];
            if (check[nextnode] == false) {
                cout << nextnode << " ";
                s.push(current_node);
                s.push(nextnode);
                check[nextnode] = true;
                break;
            }
        }

    }
}

//넓이 우선 탐색
void BFS_queue(int start, vector<int> graph[], bool check[]) {
    queue<int> q;
    q.push(start);
    check[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i];
            if (check[next_node] == false) { //만약 노드를 망문하지 않았으면
                check[next_node] = true;
                q.push(next_node);
            }
        }
    }
}


int main() {
    int node, line, start; // 노드 , 간선
    cin >> node >> line >> start;
    vector<int>* graph = new vector<int>[node + 1];

    bool* check = new bool[node + 1]; //노드 방문 체크 리스트
    fill(check, check + node + 1, false);

    int n, l;
    for (int i = 0; i < line; i++) {
        cin >> n >> l;
        graph[n].push_back(l);
        graph[l].push_back(n); //양방향시 추가
    }

    for (int i = 0; i < line; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    //깊이탐색
    /* 
    //DFS_recursion(start, graph, check);
    fill(check, check + node + 1, false);
    cout << endl;*/
    
    DFS_stack(start, graph, check);
    fill(check, check + node + 1, false);
    cout << endl;
    //넓이탐색
    BFS_queue(start, graph, check);
}