//탈옥
//https://www.acmicpc.net/problem/9376
#include<iostream>
#include<queue>
using namespace std;

#define MAX 100
char map[MAX][MAX];
int R, C;

void BFS(int rs, int cs){
    int p[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    bool check[MAX][MAX];
    int value[MAX][MAX];

    queue<int> r, c;

    r.push(rs); c.push(cs);
    check[rs][cs] = true;
    value[rs][cs] = 0;

    int value = 0;

    while (!r.empty())
    {
        int r1 = r.front();
        int c1 = c.front();
        r.pop(); c.pop();
        
        for(int i=0; i<4;i++){
            int r2 = r1 + p[i][0];
            int c2 = c1 + p[i][1];
            if( r2 >= 0 && c2 >= 0 && r2 < R && c2 < C ){
                if(map[r2][c2] != '*' ){
                    if(map[r2][c2] == '#'){
                        
                        value[r2][c2] = value[r1][c1] + 1;      
                    }else{

                    }



                }
            }else{ //탈출 성공시

            }
        }
    }
    

    



}

void escapePrizon(){

    cin >> R >> C;

    for(int i=0; i < R ;i++){
        for(int j=0; j<C ;j++){
            cin >> map[i][j];
        }
    }
}


void MySolution(){
    int N;
    cin >> N ;

    for(int i=0; i<N;i++){

    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

}