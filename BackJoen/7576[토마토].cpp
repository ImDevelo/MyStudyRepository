//토마토
//https://www.acmicpc.net/problem/7576
#include<iostream>
#include<queue>
using namespace std;
#define MAX 1000

int N, M;
int map[MAX][MAX];
int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int noRipen = 0, days = 0;
queue<int> r, c;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    
    cin >> M >> N;

    for(int i=0; i<N; i++){
        for(int j=0, temp; j<M; j++){
            cin >> temp;
            if(temp == 0){
                noRipen++;    
            }else if(temp == 1){
                r.push(i); c.push(j);
            }
            map[i][j] = temp;
        }
    }

    if(noRipen == 0){
        cout << 0;
        return 0;
    }
        
    while (!r.empty())
    {
        int r1 = r.front();
        int c1 = c.front();
        r.pop(); c.pop();

        for(int i=0; i<4; i++){
            int r2 = r1 + d[i][0];
            int c2 = c1 + d[i][1];

            if(r2 >= 0 && c2 >= 0 && r2 < N && c2 < M){ // 범위검사
                if(map[r2][c2] == 0){
                    r.push(r2); c.push(c2);
                    map[r2][c2] = map[r1][c1] + 1;
                    noRipen -= 1;
                    if(map[r2][c2] > days){
                        days = map[r2][c2];
                    }
                }
            }
        }
    }
    if(noRipen == 0){
        cout << days - 1;
    }else{
        cout << -1;
    }
}