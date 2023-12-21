//백조의 호수
//https://www.acmicpc.net/problem/3197
#include<iostream>
#include<queue>
using namespace std;

#define MAX_HORIZON 1500
#define MAX_VERTICAL 1500

char map[MAX_VERTICAL][MAX_HORIZON];
bool check[MAX_VERTICAL][MAX_HORIZON];
int R, C;
int LpointR, LpointC;

void resetCheck() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            check[i][j] = false;
        }
    }
}

bool serch_X(int x, int y) {
    if (x + 1 < C && map[y][x + 1] == '.')//right
        return true;
    else if (x - 1 >= 0 && map[y][x + 1] == '.')//left
        return true;
    else if (y + 1 < R && map[y + 1][x] == '.')//down
        return true;
    else if (y - 1 >= 0 && map[y - 1][x] == '.')//up
        return true;
    return false;
}

void meltIce() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j]=='X' && serch_X(j, i)) {
                map[i][j] = 'o';
            }
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j] == 'o') {
                map[i][j] = '.';
            }
        }
    }
}

void print() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << map[i][j];
        }
        cout << endl;
    }
}



bool findRoad() {
    queue<int> r, c;

    r.push(LpointR); c.push(LpointC);
    check[LpointR][LpointC] = true;

    while (!r.empty() && !c.empty()) {
        int rl = r.front();
        int cl = c.front();
        r.pop(); c.pop();
        //아래
        if (rl + 1 < R && map[rl + 1][cl] != 'X' && check[rl + 1][cl] == false) {//아래
            r.push(rl + 1); c.push(cl);
            check[rl+1][cl] = true;
            if (map[rl + 1][cl] == 'L') {
                return true;
            }
        }
        //위
        if (rl - 1 >= 0 && map[rl - 1][cl] != 'X' && check[rl - 1][cl] == false) {
            r.push(rl - 1); c.push(cl);
            check[rl - 1][cl] = true;
            if (map[rl - 1][cl] == 'L') {
                return true;
            }
        }
        //오른쪽
        if (cl + 1 < C && map[rl][cl + 1] != 'X' && check[rl][cl + 1] == false) {
            r.push(rl); c.push(cl + 1);
            check[rl][cl+1] = true;
            if (map[rl][cl+1] == 'L') {
                return true;
            }
        }
        //왼쪽
        if (cl - 1 >= 0 && map[rl][cl - 1] != 'X' && check[rl][cl - 1] == false) {
            r.push(rl); c.push(cl - 1);
            check[rl][cl-1] = true;
            if (map[rl][cl-1] == 'L') {
                return true;
            }
        }
    }


    //찾지 못했을 때
    resetCheck();
    return false;
}

void MySolution() {
    cin >> R >> C;
    for (int i = 0; i < R ; i++) {
        for (int j = 0; j < C ; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'L') { //백조 위치 등록
                LpointC = j; LpointR = i;
            }
        }
    }
    
    int Count = 0;
    while(!findRoad()){
        meltIce();
        Count++;
    }
    cout << Count << endl;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    MySolution();
}