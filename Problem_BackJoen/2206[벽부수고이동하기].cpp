//벽 부수고 이동하기
//https://www.acmicpc.net/problem/2206

#include<iostream>
#include<queue>
using namespace std;
#define MAX 1000

int N, M;
int map[MAX][MAX];
int d[4][2] = {{1,0},{-1,0},{0,1},{1,0}};


void BFS(){
    queue<int> r, c;
    r.push(0); c.push(0);

    while (!r.empty())
    {
        int r1 = r.front();
        int c1 = c.front();
        r.pop(); c.pop();

        for(int i=0; i<4; i++){
            int r2 = r1 + d[i][0];
            int c2 = c1 + d[i][1];

            if(r2 >= 0 && c2 >= 0 && r2 < N && c2 < M){ // 범위검사
                if(map[r2][c2] != -1){
                    r.push(r2); c.push(c2);
                    map[r2][c2] = map[r1][c1] + 1;
                    

                    if(r2 == (N-1) && c2 == (M-1)){
                        return map[N-1][M-1];
                    }
                }
            }
        }


    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0, temp; j<M; j++){
            cin >> temp;
            if(temp == 1){
                temp = -1;
            }
            map[i][j] = temp;
        }
    }

    //어쩔 수 없이 뚫는 상황
    //최단거리를 위해 뚫는 상황





    
}