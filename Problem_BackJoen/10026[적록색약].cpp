//적록색약 
//https://www.acmicpc.net/problem/10026
#include<iostream>
#include<queue>
#include<utility>
using namespace std;
#define MAX 100
 
int N;
char arr[MAX][MAX];

int bfs(pair<int,int> start, bool visited[][MAX], bool blindness){
    queue<pair<int,int>> q;
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
            if(r_next >= 0 && c_next >= 0 && r_next < N && c_next < N && visited[r_next][c_next] == false){
                if(arr[r_next][c_next] == arr[r_current][c_current]){
                    q.push({r_next, c_next});
                    visited[r_next][c_next] = true;
                }
                if(blindness && (arr[r_next][c_next] == 'R' || arr[r_next][c_next] == 'G') && (arr[r_next][c_next] == 'R' || arr[r_next][c_next] == 'G')){
                    q.push({r_next, c_next});
                    visited[r_next][c_next] = true;
                }
            }
        }
    }
    return -1;
}

void MySolution(){
    bool visited[MAX][MAX] = {false};
    int count_nomal = 0;
    int count_blindness = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(visited[i][j] == false){
                bfs({i,j},visited,false);
                count++;           
            }       
        }
    }

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    cin >> N;


    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }
    MySolution();
}