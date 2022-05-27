//미로찾기
//https://www.acmicpc.net/problem/2178
#include<iostream>
#include<queue>
using namespace std;

#define MAX 100
int N , M;
char map[MAX][MAX];
int p[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int counting[MAX][MAX];

//범위 검사
bool overflow(int i, int j){
    if( i < 0  || i >= N || j < 0 || j >= M ){
        return false;
    }
    return true;
}

void BFS(){
    queue<int> R;
    queue<int> C;
    map[0][0] = '0';
    counting[0][0] = 1;
    R.push(0); C.push(0);

    while(!R.empty()){
        int r = R.front();
        int c = C.front();
        R.pop(); C.pop();
        
        for(int i=0; i<4;i++){
            int r1 = r + p[i][0];
            int c1 = c + p[i][1];
            if(overflow(r1,c1)){
                if(map[r1][c1] == '1'){
                    R.push(r1); C.push(c1);
                    map[r1][c1] = '0';
                    counting[r1][c1] = counting[r][c] + 1;
                }
            }
        }
    }
}

void MySolution(){
    cin >> N >> M;

    for(int i = 0; i<N;i++){
        for(int j =0; j<M;j++){
            cin >> map[i][j];
        }
    }

    BFS();
    cout << counting[N-1][M-1] << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();
}

/* 파이썬
from collections import deque
import sys
input = sys.stdin.readline

n, m = map(int, input().split())

graph = [(list(map(int, input().rstrip()))) for _ in range(n)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

q = deque([(0, 0)])

while q:
    x, y = q.popleft()
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < n and 0 <= ny < m:
            if graph[nx][ny] == 1:
                graph[nx][ny] = graph[x][y] + 1
                q.append((nx, ny))

print(graph[n-1][m-1])
*/