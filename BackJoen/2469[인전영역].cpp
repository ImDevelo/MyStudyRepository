//안전영역
//https://www.acmicpc.net/problem/2468
#include<iostream>
#include<algorithm>
#include<utility>
#include<queue>
#include<set>
using namespace std;
#define MAX 100

int N;
int arr[MAX][MAX];

void bfs(pair<int,int> start, bool visited[][MAX], int hight){
    queue<pair<int,int>> q;
    int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    q.push({start.first,start.second});
    visited[start.first][start.second] = true;

    while (!q.empty()){
        int r_current = q.front().first;
        int c_current = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int r_next = r_current + d[i][0];
            int c_next = c_current + d[i][1];

            if(r_next >= 0 && c_next >= 0 && r_next < N && c_next < N){
                if(visited[r_next][c_next] != true && arr[r_next][c_next] > hight){
                    q.push({r_next, c_next});
                    visited[r_next][c_next] = true;
                }else if(arr[r_next][c_next] <= hight){
                    visited[r_next][c_next] = true;
                }
            }
        }
    }
}

int area(int hight){
    bool visited[MAX][MAX] = {0};
    int areaCount = 0;

    for(int i=0; i<N;i++){
        for(int j=0; j<N; j++){
            if(visited[i][j] == false){
                if(arr[i][j] <= hight){
                    visited[i][j] = true;
                }else{
                    bfs({i,j},visited,hight);
                    areaCount++;
                }
            }
        }
    }
    return areaCount;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int ans = 1;
    set<int> s;

    cin >> N;
    for(int i=0; i<N;i++){
        for(int j = 0,t; j<N; j++){
            cin >> t;
            arr[i][j] = t;
            s.insert(t);
        }
    }
    set<int>::iterator iter;
    for(iter = s.begin(); iter != s.end(); iter++){
        ans = max(ans,area(*iter));
    }
    cout << ans;
}