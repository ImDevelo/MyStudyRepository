//N-Queen
//https://www.acmicpc.net/problem/9663
#include<iostream>
#include<math.h>
using namespace std;

#define MAX 15
int N;
int counting;

void NQueen(int queen,int rPoint, int cPoint, const bool chess[][MAX]){
    bool broad[MAX][MAX]; 
    for(int i=0; i<N;i++){
        for(int j=0; j<N;j++){
            broad[i][j] = chess[i][j];
        }
    }
    if(queen == 1){
        counting++;
        return;
    }else{
        //퀸배치
        for(int r=0; r < N; r++){
            broad[r][cPoint] = true;
            for(int c=0; c < N; c++){
                broad[rPoint][c] = true;
                if(abs(r - rPoint) == abs(c - cPoint)){
                    broad[r][c] = true;
                }
            }
        }
        for(int r=rPoint; r<N;r++){
            for(int c=0; c<N;c++){
                if(broad[r][c] != true){
                    NQueen(queen-1,r,c, broad);
                }
            }
        }
    }
}


void MySolution(){
    cin >> N;
    bool chess[MAX][MAX];
    for(int i=0; i<N;i++){
        for(int j=0; j<N;j++){
            chess[i][j] = false;
        }
    }
    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){

            NQueen(N, r,c,chess);
        }
        
    }

    cout << counting;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();
}