//
//https://www.acmicpc.net/problem/
#include<iostream>
#include<queue>
#include<utility>
using namespace std;
#define MAX 0

int bfs(pair<int,int> start){
    queue<pair<int,int>> q;
    bool visited[MAX][MAX];
    int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    q.push({start.first,start.second});
    visited[start.first][start.second] = true;

    while (!q.empty())
    {
        int r_current = q.front().first;
        int c_current = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int r_next = r_current + d[i][0];
            int c_next = c_current + d[i][1];

            if(r_next >= 0 && c_next >= 0 && r_next < R && c_next < C){
                if(map[r_next][c_next] != true && visited[r_next][c_next] == false){
                    //노드 이동
                    q.push({r_next, c_next});
                    visited[r_next][c_next] = true;
                }
            }
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int map[MAX][MAX];
    int R,C;

    cin >> R >> C;
    for(int i=0 ;i<R; i++){
        for(int j=0; j<C; j++){
            cin >> map[i][j];
        }
    }
    bfs({0,0}{R,C},map);
}