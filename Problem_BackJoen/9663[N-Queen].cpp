//N-Queen
//https://www.acmicpc.net/problem/9663
#include<iostream>
#include<utility>
#include<stack>
#include<math.h>
using namespace std;

#define MAX 15
int N;
int counting;

void NQueen(){
    for(int r=0; r < N; r++){
        broad[r][cPoint] = true;
        for(int c=0; c < N; c++){
            broad[rPoint][c] = true;
            if(abs(r - rPoint) == abs(c - cPoint)){
                broad[r][c] = true;
            }
        }
    }
}

void MySolution(){
    cin >> N;
    for(int i=0; i<N;i++){
        for(int j=0; j<N;j++){
            chess[i][j] = false;
        }
    }
    NQueen();    
    cout << counting;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

}