//컴퓨터 바이러스
//https://www.acmicpc.net/problem/2606
#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

int Solution = 0;

//넓이 우선 탐색
void BFS(int start, vector<int> graph[], bool check[]) {
    queue<int> q;
    q.push(start);
    check[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        Solution++;

        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i];
            if (check[next_node] == false) { //만약 노드를 망문하지 않았으면
                check[next_node] = true;
                q.push(next_node);
            }
        }
    }
}

void MySolution(){
    int node, line; // 노드 , 간선
    cin >> node >> line;
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
    } //정렬

    BFS(1,graph,check);
    if(Solution != 0){
        cout << (Solution - 1) << endl;
    }else{
        cout << 0 << endl;
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

}