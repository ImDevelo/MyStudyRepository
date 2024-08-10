//미세먼지 안녕! 
//https://www.acmicpc.net/problem/17144
#include <iostream>
#include <vector>
#include <queue>
#define MAX 50
using namespace std;

int R, C, T;
vector<int> air_pos;
int arr[MAX][MAX];


void AirClear() {
    int up_air = air_pos[0];
    int down_air = air_pos[1];

    for (int i = up_air - 1; i > 0; i--) {
        arr[i][0] = arr[i-1][0];
        
    }
    for (int i = 0; i < C - 1; i++) {
        arr[0][i]  = arr[0][i + 1];
    }
    for (int i = 0; i < up_air; i++) {
        arr[i][C-1] = arr[i + 1][C-1];
    }
    for (int i = C-1; i > 1; i--) {
        arr[up_air][i]= arr[up_air][i-1];
    }
    arr[up_air][1] = 0;

    for (int i = down_air + 1; i < R; i++) {
        arr[i][0] = arr[i + 1][0];
    }
    for (int i = 0; i < C - 1; i++) {
        arr[R-1][i] = arr[R - 1][i + 1];
    }
    for (int i = R-1; i > down_air; i--) {
        arr[i][C - 1] = arr[i - 1][C - 1];
    }
    for (int i = C - 1; i > 1; i--) {
        arr[down_air][i] = arr[down_air][i - 1];
    }
    arr[down_air][1] = 0;

}


void spreadDust(queue<pair<pair<int, int>, int>>& q, int r, int c, int a) {
    int dr[4] = { 1,-1,0,0 };
    int dc[4] = { 0 ,0, 1, -1 };

    int dust_amount = a;
    int spread_dust_amount = dust_amount / 5;
    int spread_dust_count = 0;

    for (int i = 0; i < 4; i++) {
        int r_next = dr[i] + r;
        int c_next = dc[i] + c;

        if (r_next >= 0 && r_next < R && c_next >= 0 && c_next < C && arr[r_next][c_next] != -1) {
            arr[r_next][c_next] += spread_dust_amount;
            spread_dust_count++;
        }
    }
    arr[r][c] -= (spread_dust_amount * spread_dust_count);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> R >> C >> T;

    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == -1) {
                air_pos.push_back(i);
            }
            else {
                q.push({ {i,j} , arr[i][j] });
            }
        }
    }
    
    for (int t = 0; t < T; t++) {
        //먼지 확산
        int dust_count = q.size();
        for (int i = 0; i < dust_count; i++) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int a = q.front().second;
            q.pop();
            spreadDust(q, r, c, a);
        }

        // 공기 청정기 가동
        AirClear();

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (arr[i][j] != -1) {
                    q.push({ {i,j}, arr[i][j]});
                }
            }
        }
    }

    int remaining_dust = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            remaining_dust += arr[i][j];
        }
    }
    remaining_dust += 2;
    cout << remaining_dust << "\n";

    return 0;
}