//https://www.acmicpc.net/problem/1986
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

char arr[1001][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    
    int R, C;
    cin >> R >> C;

    int Q, N, P;
    vector<vector<int>> arr(R+1, vector<int>(C+1, 0));
    vector<pair<int, int>> q;

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int r, c;
        cin >> r >> c;
        arr[r][c] = 2;
        q.push_back({ r,c });
    }

    int move_r[8] = {2,2,1,1,-1,-1,-2,-2};
    int move_c[8] = { 1,-1, 2,-2, 2,-2,1,-1 };

    cin >> N;
    for (int i = 0; i < N; i++) {
        int r, c;
        cin >> r >> c;
        arr[r][c] = 2;

        for (int k = 0; k < 8; k++) {
            int next_r = r + move_r[k];
            int next_c = c + move_c[k];

            if (next_r > 0 && next_r <= R && next_c > 0 && next_c <= C && arr[next_r][next_c] <= 1) {
                arr[next_r][next_c] = 1;
            }
        }
    }

    cin >> P;
    for (int i = 0; i < P; i++) {
        int r, c;
        cin >> r >> c;
        arr[r][c] = 2;
    }

    int move_q_r[8] = { 0,0,1,-1,-1,-1,1,1 };
    int move_q_c[8] = { 1,-1, 0,0, 1,-1,1,-1 };

    for (int i = 0; i < Q; i++) {
        int r = q[i].first; 
        int c = q[i].second;

        for (int k = 0; k < 8; k++) {
            int next_r = r, next_c = c;
            while (true)
            {
                next_r = next_r + move_q_r[k];
                next_c = next_c + move_q_c[k];

                if (next_r > 0 && next_r <= R && next_c > 0 && next_c <= C && arr[next_r][next_c] <= 1) {
                    arr[next_r][next_c] = 1;
                    continue;
                }
                break;
            }
        }
    }

    int  count = 0;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (arr[i][j] == 0) {
                count++;
            }
        }
    }

    cout << count;
}