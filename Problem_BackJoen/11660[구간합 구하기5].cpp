//11660
//https://www.acmicpc.net/problem/11660
#include<iostream>
using namespace std;


void MySolution(){
    int N, M;
    cin >> N >> M;

    int** map = new int*[N];

    for(int i=0; i<N; i++){
        map[i] = new int[N];
        for(int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }

    int r1,c1,r2,c2;
    int sum = 0;
    for(int i=0; i<M; i++){
        cin >> r1 >> c1 >> r2 >> c2;        
        for(int r=r1-1; r < r2; r++){
            for(int c=c1-1; c < c2 ;c++){
                sum += map[r][c];
            }
        }
        cout << sum << " ";
        sum = 0;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

}