#include<iostream>
#include<queue>
using namespace std;

#define MAX 1500
int R, C;
char map[MAX][MAX];

int LPoint[2][2];
int p[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };


bool BFS(int startX, int startY) {
    bool** check = new bool* [R];
    for (int i = 0; i < R; i++) {
        check[i] = new bool[C];
    }
    queue<int> r, c;
    r.push(startX);
    c.push(startY);
    check[startX][startY] = true;

    while (!r.empty())
    {
        int r1 = r.front();
        int c1 = c.front();
        r.pop(); c.pop();

        for (int i = 0; i < 4; i++) {
            int r2 = r1 + p[i][0];
            int c2 = c1 + p[i][1];

            if (r2 >= 0 && c2 >= 0 && r2 < R && c2 < C) {
                if (map[r2][c2] == '.' && check[r2][c2] != true) {
                    r.push(r2); c.push(c2);
                    check[r2][c2] = true;
                    
                }
                else if (map[r2][c2] == 'X') {
                    map[r2][c2] = '.';
                }
                else if (map[r2][c2] == 'L' && check[r2][c2] != true) {
                    return true;
                }
            }
        }
    }

    return false;
}

bool MeltIce() {
    for (int i = 0; i < 2; i++) {
        if (BFS(LPoint[i][0], LPoint[i][1])) {
            return true;
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << map[i][j];
        }
        cout << endl;
    }
    return false;
}

void MySolution() {
    cin >> R >> C;

    int temp = 0;
    for (int i = 0; i < R; i++) {
        
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'L') {
                LPoint[temp][0] = i;
                LPoint[temp][1] = j;
                temp++;
            }
        }
    }

    int count = 0;
    
    while (!MeltIce())
    {
        count++;
    }
    


    cout << count << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();
}