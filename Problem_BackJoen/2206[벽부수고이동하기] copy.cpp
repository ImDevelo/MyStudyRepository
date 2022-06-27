//벽 부수고 이동하기
//https://www.acmicpc.net/problem/2206

#include<iostream>
#include<queue>
#include<utility>
using namespace std;
#define MAX 1000

int N, M;
int map[MAX][MAX];


void print(){
    for(int i=0; i<N;i++){
        for(int j=0; j<M; j++){
            if(map[i][j] == -1){
                cout << "# ";
            }else{
                cout << map[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void BFS(){
    int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    queue<pair<int,bool>> r, c;
    r.push({0,false}); 
    c.push({0,false});
    map[0][0] = 1;

    //전부 부셔버리기
    while (!r.empty())
    {
        int r1 = r.front().first;
        int c1 = c.front().first;
        bool broken = r.front().second; 
        r.pop(); c.pop();
    
        cout << "( " << r1 << " , " << c1 << " ) ->" << broken <<"\n";
        print();
        
        for(int i=0;i<4;i++){
            int r2 = r1 + d[i][0];
            int c2 = c1 + d[i][1];

            if(r2 >= 0 && c2 >= 0 && r2 < N && c2 < M){
                if(!broken){
                    if(map[r2][c2] == 0 || (map[r1][c1]< map[r2][c2])){ // 빈구역 채우기
                        r.push({r2,false}); c.push({c2,false});
                        map[r2][c2] = map[r1][c1]+1;
                    }else if(map[r2][c2] == -1){
                        r.push({r2,true}); c.push({c2,true});
                        map[r2][c2] = map[r1][c1]+1;
                    }
                }else{
                    if(map[r2][c2] == 0 || (map[r1][c1] < map[r2][c2])){ // 빈구역 채우기
                        r.push({r2,true}); c.push({c2,true});
                        map[r2][c2] = map[r1][c1]+1;
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
    char c;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> c;
            if(c == '1'){
                map[i][j] = -1;
            }else{
                map[i][j] = 0;
            }
        }
    }
    BFS();

    if(map[N-1][M-1] == 0){
        cout << -1;
    }else{
        cout << map[N-1][M-1];
    }

}