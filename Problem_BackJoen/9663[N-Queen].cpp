//N-Queen
//https://www.acmicpc.net/problem/9663
#include<iostream>
using namespace std;
#define MAX 15

int N;
int counting = 0;
int line[MAX];

void NQueen(int cnt){
    if(cnt == N){
        counting++;
        return;
    }
    bool q[MAX] = {0};
    for(int i=0; i<N; i++){
        
        if(line[i] != -1){

            q[i] = true; // i가 0일때

            if(i + (cnt - line[i]) < N){ // 0+1-0 < N성립
                q[i + (cnt - line[i])] = true; // q 0+1-0
            }
            if( i - (cnt - line[i]) >= 0){//1-
                q[i - (cnt - line[i])] = true;
            }
        }
    }

    for(int i=0;i<N;i++){
        if(q[i] != true){
            line[i] = cnt;
            NQueen(cnt+1);
            line[i] = -1;
        }
    }
}

void MySolution(){
    cin >> N;
    for(int i=0; i<N;i++){
        line[i] = -1;
    }
    NQueen(0);    
    cout << counting;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

}