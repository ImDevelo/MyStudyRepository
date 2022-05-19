//미네랄
#include<iostream>
#include<queue>
using namespace std;

#define MAX 100
int R, C;
char cave[MAX][MAX];
int p[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void fallCristal(int,int);
void trowStick(int,int);

void trowStick(int n,int rl){
    int i;
    if(rl){
        for(i =C; i>0 ; i--){
            if(cave[n][i] == 'x' ){
                cave[n][i] = '.';
                break;
            }       
        }
    }
    else{
        for(i = 0; i < C;i++){
            if(cave[n][i] == 'x' ){
                cave[n][i] = '.';
                break;
            }
        }
    }

    if(n+1<R && cave[n+1][i] == 'x' ){
        fallCristal(n+1,i);
    }else if(i+1 && cave[n][i+1] == 'x'){
        fallCristal(n,i+1);
    }else if(cave[n][i-1] == 'x'){
        fallCristal(n,i-1);
    }
}


void fallCristal(int rPoint, int cPoint){
    queue<int> r, c;
    bool doSkyCristal = true;
    r.push(rPoint); c.push(cPoint);
    cave[rPoint][cPoint] = 'O';

    while (!r.empty()){
        int r1 = r.front();
        int c1 = c.front();
        r.pop(); c.pop();

        for(int i =0; i<4 ;i++){
            int r2 = r1 + p[i][0];
            int c2 = c1 + p[i][1];
            if(r2 >= 0 && r2 < R && c2 >= 0 && c2 < C){
                if(cave[r2][c2] == 'x'){
                    cave[r2][c2] = 'O';
                    r.push(r2); c.push(c2);
                    if(r2 == 1){
                        doSkyCristal = false;
                    }
                }
            }
        }
    }
    
    while(doSkyCristal){ //크리스탈 다운이 필요한 경우
        for(int i =0; i < C; i++){
            bool first = false;
            int tempPoint = 0;
            for(int j = 1; j <= R ; j++){
                if((cave[j][i] == 'O')&& !first){
                    first = true;
                    tempPoint = j-1;
                    char temp = cave[j][i];
                    cave[j][i] = cave[j-1][i];
                    cave[j-1][i] = temp;
                }
                else if(first == true){
                    char temp = cave[j][i];
                    cave[j][i] = cave[j-1][i];
                    cave[j-1][i] = temp;
                }
            }

            first = false;
            if((tempPoint - 1) != -1 ){
                if(((tempPoint - 1) == 0 || cave[tempPoint - 1][i] == 'x') ){
                    doSkyCristal = false;
                }
            }
        }
    }

    for(int i=R; i>0;i--){
        for(int j=0;j<C;j++){
            if(cave[i][j]=='O'){
                cave[i][j] = 'x';
            }
        }
    }
}


void MySolution(){
    //입력
    cin >> R >> C;
    for(int i = R; i>0; i--){
        for(int j =0; j<C;j++){
            cin >> cave[i][j];
        }
    }

    //알고리즘
    int N;
    cin >> N;
    for(int i=0; i<N;i++){
        int stickR;
        cin >> stickR;
        trowStick(stickR,i%2);
    } 

    //출력
    for(int i=R; i>0;i--){
        for(int j=0;j<C;j++){
            cout << cave[i][j];
        }
        cout << endl;
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

}