//
//https://www.acmicpc.net/problem/
#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
#define MAX 8

int map[MAX][MAX];
int R,C;
int secure = 0;
int bestAns = 0;
vector<pair<int,int>> v;

int bfs(){
    queue<pair<int,int>> q;
    bool visited[MAX][MAX] = {false};
    int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int area = 0;

    for(int i=0; i<v.size(); i++){
        q.push({v.at(i).first,v.at(i).second});
        visited[v.at(i).first][v.at(i).second] = true;
    }
    
    while (!q.empty())
    {
        int r_current = q.front().first;
        int c_current = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int r_next = r_current + d[i][0];
            int c_next = c_current + d[i][1];

            if(r_next >= 0 && c_next >= 0 && r_next < R && c_next < C){
                if(map[r_next][c_next] == 0 && visited[r_next][c_next] == false){
                    //노드 이동
                    q.push({r_next, c_next});
                    visited[r_next][c_next] = true;
                    area++;
                }
            }
        }
    }
    return area;
}


void combination(int count){
    if(count == 3){
        bestAns = max(bestAns, (secure - bfs() - 3));
        return;
    }else{
        for(int i=0; i<R;i++){
            for(int j=0; j<C; j++){
                if(map[i][j] == 0){
                    map[i][j] = 1;
                    combination(count + 1);
                    map[i][j] = 0;
                }
            }
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> R >> C;
    for(int i=0 ;i<R; i++){
        for(int j=0,t; j<C; j++){
            cin >> t;
            map[i][j] = t;
            if(t == 2){
                v.push_back({i,j});
            }else if(t == 0){
                secure++;
            }
        }
    }

    combination(0);
    cout << bestAns;
}