//https://www.acmicpc.net/problem/14503
#include <iostream>
#include<iostream>
#define MAX 50
using namespace std;

int area[MAX][MAX];

void MySolution() {
    int N, M;
    int pos_r, pos_c, direction; 
    int cleanning = 1; 
    int d[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };

    cin >> N >> M;
    cin >> pos_r >> pos_c >> direction;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> area[i][j];
        }
    }
    area[pos_r][pos_c] = 2;
    
    while (true)
    {
        int point_r = pos_r;
        int point_c = pos_c;
        bool move = false;

        for (int i = 0; i < 4; i++) {
            direction =  (3 + direction) % 4;

            int next_point_r = point_r + d[direction][0];
            int next_point_c = point_c + d[direction][1];

            if (area[next_point_r][next_point_c] == 0) {
                pos_r = next_point_r;
                pos_c = next_point_c;
                area[next_point_r][next_point_c] = 2;
                cleanning++;
                move = true;
                i = 4;
                continue;
            }
        }
        if (!move) {
            int back_point_r = point_r - d[direction][0];
            int back_point_c = point_c - d[direction][1];
            if (area[back_point_r][back_point_c] == 1) { //후진 하는 곳이 벽이라면 종료
                break;
            }
            pos_r = back_point_r;
            pos_c = back_point_c;
        }
    }
    cout << cleanning;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    MySolution();
}