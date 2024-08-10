//빙산  시간오래걸림(시간복잡도 n(2O^2))
//https://www.acmicpc.net/problem/2573
#include<iostream>
#include<queue>
using namespace std;
#define MAX 300

int R, C;
int map[MAX][MAX];
int years = 1;

void bfs(pair<int, int> start, bool visited[][MAX], bool findMode) {
    queue<pair<int, int>> q;
    int d[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
    q.push({ start.first,start.second });
    visited[start.first][start.second] = true;

    while (!q.empty())
    {
        int r_current = q.front().first;
        int c_current = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int r_next = r_current + d[i][0];
            int c_next = c_current + d[i][1];

            if (r_next >= 0 && c_next >= 0 && r_next < R && c_next < C) {
                if (findMode) {
                    if (map[r_next][c_next] == 0 && visited[r_next][c_next] == false) {
                        q.push({ r_next, c_next });
                        visited[r_next][c_next] = true;
                    }
                    else if (map[r_next][c_next] != 0) {
                        map[r_next][c_next] -= 1;
                        if (map[r_next][c_next] == 0) {
                            visited[r_next][c_next] = true;
                        }
                    }
                }else {
                    if (map[r_next][c_next] != 0 && visited[r_next][c_next] == false) {
                        q.push({ r_next, c_next });
                        visited[r_next][c_next] = true;
                    }
                }

            }
        }
    }
}

bool iceMelt() {
    bool visited[MAX][MAX] = { false };

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j] == 0 && visited[i][j] == false) {
                bfs({i,j},visited, true);
            }
        }
    }

    int icebergCount = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if(map[i][j] != 0 && visited[i][j] ==false){
                bfs({i,j},visited,false);
                icebergCount++;
            }
        }
    }
    if (icebergCount >= 2) {
        cout << years;
        return false;
    }
    else if (icebergCount == 0) {
        cout << 0;
        return false;
    }
    years++;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
        }
    }

    while (iceMelt());
    
}