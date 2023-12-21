#include<iostream>
#include<queue>
using namespace std;

#define MAX 100
int R, C;
char cave[MAX][MAX];
int p[4][2] = {{1,0},{0,1},{0,-1},{-1,0}};

void trowStick(int, int);
char BFS(int, int, int);
bool overflow(int, int);

bool overflow(int r, int c) {
    if (r < 0 || r >= R || c < 0 || c >= C) {
        return false;
    }
    return true;
}


void trowStick(int n, int rl) { //막대기를 던져 크리스탈 파괴
    int c;
    if (rl) {
        for (c = C; c > 0; c--) {
            if (cave[n][c] == 'x') {
                cave[n][c] = '.';
                break;
            }
        }
    } else {
        for (c = 0; c < C; c++) {
            if (cave[n][c] == 'x') {
                cave[n][c] = '.';
                break;
            }
        }
    }

    char skyInCristal = 'x';
    for (int i = 0; i < 4; i++) {
        int r1 = n + p[i][0];
        int c1 = c + p[i][1];
        if (overflow(r1, c1)) {
            if (cave[r1][c1] == 'x') {
                skyInCristal = BFS(r1, c1,i);
                if (skyInCristal != 'x') {
                    break;
                }
            }
        }
    }
    

    
    for(int i=R; i>0;i--){
        for(int j=0;j<C;j++){
            if(cave[i][j] =='1'||cave[i][j] =='2'||cave[i][j] =='3'||cave[i][j] =='4'){
                cave[i][j] = 'x';
            }
        }
    }
    
}

char BFS(int rPoint, int cPoint, int i) {
    queue<int> r, c;
    char chr;
    if(i==0){chr = '1';}
    else if(i==1){chr = '2';} 
    else if(i==2){chr = '3';} 
    else if(i==3){chr = '4';}

    r.push(rPoint); c.push(cPoint);
    cave[rPoint][cPoint] = chr;

    while (!r.empty()) {
        int r1 = r.front();
        int c1 = c.front();
        r.pop(); c.pop();

        for (int i = 0; i < 4; i++) {
            int r2 = r1 + p[i][0];
            int c2 = c1 + p[i][1];
            if (overflow(r2, c2)) {
                if (cave[r2][c2] == 'x') {
                    cave[r2][c2] = chr;
                    r.push(r2); c.push(c2);
                    if (r2 == 1) {
                        return 'x';
                    }
                }
            }
        }
    }
    return chr;
}

void MySolution() {
    //입력
    cin >> R >> C;
    for (int i = R; i > 0; i--) {
        for (int j = 0; j < C; j++) {
            cin >> cave[i][j];
        }
    }

    //알고리즘
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int stickR;
        cin >> stickR;
        trowStick(stickR, i % 2);
    }

    //출력
    for (int i = R; i > 0; i--) {
        for (int j = 0; j < C; j++) {
            cout << cave[i][j];
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

}