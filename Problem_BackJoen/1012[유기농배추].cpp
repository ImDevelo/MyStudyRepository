//유기농 배추
//https://www.acmicpc.net/problem/1012
#include<iostream>
#include<utility>
#include<queue>
#include<stack>
using namespace std;
#define MAX 50

void MySolution() {
    int X, Y, K;
    stack<pair<int, int>> cabbage; //배추위치
    int arr[MAX][MAX] = {0}; 
    bool visited[MAX][MAX] = { false };
    int earthworm = 0;
    cin >> X >> Y >> K;
    for (int i = 0, x, y; i < K; i++) {
        cin >> x >> y;
        arr[x][y] = 1;
        cabbage.push({ x,y });
    }

    while (!cabbage.empty())
    {
        int start_x = cabbage.top().first;
        int start_y = cabbage.top().second;
        cabbage.pop();

        if (visited[start_x][start_y] == false) { //지렁이가 없다면 bfs탐색
            int d[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
            queue<pair<int, int>> q;
            q.push({ start_x,start_y });
            visited[start_x][start_y] = true;

            while (!q.empty()){
                int current_x = q.front().first;
                int current_y = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int next_x = d[i][0] + current_x;
                    int next_y = d[i][1] + current_y;
                    if (next_x >= 0 && next_y >= 0 && next_x < X && next_y < Y) {
                        if ( visited[next_x][next_y] == false && arr[next_x][next_y] == 1 ) {
                            q.push({next_x,next_y});
                            visited[next_x][next_y] = true;
                        }
                    }
                }
            }
            earthworm++;
        }
    }
    cout << earthworm << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        MySolution();
    }
}