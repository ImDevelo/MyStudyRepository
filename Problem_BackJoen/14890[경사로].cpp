//경사로
//https://www.acmicpc.net/problem/14890
#include<iostream>
#include<math.h>
using namespace std;
#define MAX 100 

int road[MAX][MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int N, L;
    int open_road;

    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> road[i][j];
        }
    }
    open_road = N*2;
   
    for (int i = 0; i < 2; i++) {
        for (int line = 0; line < N; line++) {
            int prev_hight, current_hight;
            bool down_check = false;
            int level_road = 1;

            if (i == 0) prev_hight = road[line][0];
            else prev_hight = road[0][line];

            for (int step = 1; step < N; step++) {

                if (i == 0 ) current_hight = road[line][step];
                else current_hight = road[step][line];

                if (abs(prev_hight - current_hight) > 1) {
                    step = N; open_road--; continue;
                }else if (prev_hight == current_hight) {
                    level_road++;
                    if (down_check && L == level_road) {
                        level_road = 0;
                        down_check = false;
                    }
                }else if (prev_hight < current_hight) {
                    if (down_check || level_road < L) {
                        step = N; open_road--; continue;
                    } 
                    level_road = 1;
                }else if (prev_hight > current_hight) {
                    if (down_check || N-L < step) {
                        step = N; open_road--; continue;
                    }
                    if (L == 1) {
                        down_check = false; level_road = 0;
                    }
                    else {
                        down_check = true;  level_road = 1;
                    }
                }
                prev_hight = current_hight;
            }
        }
    }
    cout << open_road;
}