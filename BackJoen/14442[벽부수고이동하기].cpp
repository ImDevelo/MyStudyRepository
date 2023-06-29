//벽 부수고 이동하기 2
//https://www.acmicpc.net/problem/14442
#include<iostream>
#include<queue>
#include<utility>
#include<vector>
#include<string.h>
using namespace std;
#define MAX 1000

int R, C, K;
int visited[MAX][MAX][10] = { 0 };

int bfs(vector<string>& grape) {
    queue<pair<pair<int, int>, int>> q;
    int d[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
    q.push({ {0,0},0 });

    visited[0][0][0] = 1;

    while (!q.empty())
    {
        int r_current = q.front().first.first;
        int c_current = q.front().first.second;
        int w_current = q.front().second;
        q.pop();

        if (r_current == R - 1 && c_current == C - 1) {
            return visited[r_current][c_current][w_current];
        }

        for (int i = 0; i < 4; i++) {
            int r_next = r_current + d[i][0];
            int c_next = c_current + d[i][1];


            if (r_next >= 0 && c_next >= 0 && r_next < R && c_next < C) {
                //만약 벽을 만났다면
                if (grape[r_next][c_next] == '1' && w_current < K) {
                    visited[r_next][c_next][w_current + 1] = visited[r_current][c_current][w_current] + 1;
                    q.push({ {r_next,c_next}, w_current + 1 });

                }
                //아니라면 계속 진행
                else if (grape[r_next][c_next] == '0' && visited[r_next][c_next][w_current] == 0) {
                    visited[r_next][c_next][w_current] = visited[r_current][c_current][w_current] + 1;
                    q.push({ {r_next,c_next}, w_current });
                }

            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> R >> C >> K;
    vector<string> grape(R);

    for (int i = 0; i < R; i++) {
         cin >> grape[i];
    }

    cout << bfs(grape);

}