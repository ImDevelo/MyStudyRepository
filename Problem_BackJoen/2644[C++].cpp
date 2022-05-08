//촌수 계산
//https://www.acmicpc.net/problem/2644
#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;


//넓이 우선 탐색
int BFS(int start, vector<int> graph[], int check[], int target) {
    queue<int> q;
    q.push(start);
    check[start] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i];
            if (check[next_node] == 0) { //만약 노드를 망문하지 않았으면
                check[next_node] = check[node] + 1;
                q.push(next_node);

                if(next_node == target){
                    return check[next_node];
                }
            }
            
        }
    }
    return -1;
}

void MySolution(){
    int node, line, start, target; // 노드 , 간선
    cin >> node; 
    cin >> start >> target;
    cin >> line;
    vector<int>* graph = new vector<int>[node + 1];

    int* check = new int[node + 1]; //노드 방문 체크 리스트
    fill(check, check + node + 1, 0);

    int n, l;
    for (int i = 0; i < line; i++) {
        cin >> n >> l;
        graph[n].push_back(l);
        graph[l].push_back(n); //양방향시 추가
    }

    cout << BFS(start,graph,check,target) << endl;
    
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

}