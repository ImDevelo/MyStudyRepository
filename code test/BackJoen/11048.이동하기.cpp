//이동하기
//https://www.acmicpc.net/problem/11048
#include <iostream>

using namespace std;

int room[1001][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
   
    int R, C;

    cin >> R >> C;
    
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> room[i][j];
        }
    }

    for (int i = 0; i < R; i++) {
        room[i][0] = 0;
    }
    for (int i = 0; i < C; i++) {
        room[0][i] = 0;
    }


    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            room[i][j] = room[i][j] + max(room[i - 1][j], room[i][j - 1]);
        }
    }

    cout << room[R][C];
}