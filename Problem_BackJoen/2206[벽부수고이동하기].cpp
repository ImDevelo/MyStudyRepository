//벽 부수고 이동하기
//https://www.acmicpc.net/problem/2206
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
#define MAX 1000

int N, M;
int map[MAX][MAX];
int visited[MAX][MAX][2];
short d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
queue<pair<pair<short,short>,bool>> q;

void BFS(){
    q.push({0,0},false);
    visited[0][0][0];

    while (q.empty())
    {
        int r1 = q.front().first.first;
        int c1 = q.front().first.second;
        int wall = q.front().second;

        if(r1 == N-1 && c2 == M-1){
            return 1;
        }

        for(int i=0 ;i<4; i++){
            int r2 = r1 + d[i][0];
            int c2 = c1 + d[i][1];

            if(r2 >= 0 && c2 >= 0 && r2 < N && c2 < M){
                if(wall && map[r2][c2] == -1){ //벽을 부술수 있을때 벽수수고 다음칸
                    

                }else if(){// 이동 가능할 때 이동

                }

            }

        }
    
    }
    return -1;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> N >> M;
    char c;
    for(short i=0; i<N; i++){
        for(short j=0; j<M; j++){
            cin >> c;
            if(c == '1'){
                map[i][j][0] = -1;
            }else{
                map[i][j][0] = 0;
            }
        }
    }
    BFS();
}