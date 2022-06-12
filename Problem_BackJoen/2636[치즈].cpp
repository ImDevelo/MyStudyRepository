//치즈
//https://www.acmicpc.net/problem/2636
#include<iostream>
#include<queue>
using namespace std;
#define MAX 100
int box[MAX][MAX];
int N, M, cheese = 0;
int d[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int leaveCheese = 0;

void BFSCheese(int h) {
    queue<int> r, c;
    bool check[MAX][MAX];
    r.push(h); c.push(h);

    while (!r.empty())
    {
        int r1 = r.front();
        int c1 = c.front();
        r.pop(); c.pop();
        for (int i = 0; i < 4; i++) {
            int r2 = r1 + d[i][0];
            int c2 = c1 + d[i][1];
            if (r2 >= (0+h) && c2 >= (0+h) && r2 < (N-h) && c2 < (M-h)) {
                if (check[r2][c2] != true) {
                    if (box[r2][c2] == 1) {
                        check[r2][c2] = true;
                        box[r2][c2] = h+2;
                        cheese--;
                    }else if (box[r2][c2] < h+2) {
                        check[r2][c2] = true;
                        r.push(r2); c.push(c2);
                    }
                }
            }
        }
    }
}

void MySolution() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0, temp; j < M; j++) {
            cin >> temp;
            if (temp == 1) {
                cheese++;
            }
            box[i][j] = temp;
        }
    }
    int hour = 0;
    while (cheese > 0)
    {
        leaveCheese = cheese;
        BFSCheese(hour++);
    }
    cout << hour << " " << leaveCheese;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
    return 0;
}