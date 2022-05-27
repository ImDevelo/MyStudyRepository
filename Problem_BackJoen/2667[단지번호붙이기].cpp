//단지번호붙이기
//https://www.acmicpc.net/problem/2667
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 25
int N;
char map[MAX][MAX];
bool check[MAX][MAX];
int p[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
vector<int> AreaList;


bool overflow(int r, int c){
    if(r < 0 || r >= N || c < 0 || c >= N){
        return false;
    }
    return true;
}

void BFS(int rStart, int cStart){
    queue<int> R;
    queue<int> C;
    int count = 1;
    R.push(rStart); C.push(cStart);
    check[rStart][cStart] = true;

    while (!R.empty())
    {

        int r = R.front();
        int c = C.front();

        R.pop(); C.pop();

        for(int i =0; i<4;i++){
            int r1 = r + p[i][0];
            int c1 = c + p[i][1];
            if(overflow(r1,c1)){//범위 검사
                
                if( map[r1][c1] == '1' && check[r1][c1] == false ){
                    R.push(r1); C.push(c1);
                    check[r1][c1] = true;
                    count++;
                }
            }
        }
    }

    AreaList.push_back(count);
}

void MySolution(){
    cin >> N;

    for(int i = 0; i < N ; i++){
        for(int j = 0; j < N ; j++){
            cin >> map[i][j];
            check[i][j] = false;
        }
    }

    for(int i =0; i<N;i++){
        for(int j=0;j<N;j++){
            if(check[i][j] == false && map[i][j] == '1' ){
                BFS(i,j);
            }
        }
    }
    
    sort(AreaList.begin(),AreaList.end());

    cout << AreaList.size() << endl;
    for(int i =0; i<AreaList.size();i++){
        cout << AreaList[i] << endl;
    }
    // 찾고
    // 찾은 첫부분을 시작으로 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();
}