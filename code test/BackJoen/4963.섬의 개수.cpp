//https://www.acmicpc.net/problem/4963
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(const vector<vector<int>>& arr, vector<vector<bool>>& check, int R, int C, pair<int, int> start) {

    int dr[8] = { 1,-1,0,0,1,1,-1,-1 };
    int dc[8] = { 0,0,1,-1, 1,-1,1,-1 };
    queue<pair<int, int>> q;

    q.push(start);
    check[start.first][start.second] = true;

    while (!q.empty())
    {
        int c_r = q.front().first;
        int c_c = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int n_r = dr[i] + c_r;
            int n_c = dc[i] + c_c;

            if (n_r >= 0 && n_c >= 0 && n_r < R && n_c < C) {

                if (check[n_r][n_c] == false && arr[n_r][n_c] == 1) {
                    check[n_r][n_c] = true;
                    q.push({ n_r,n_c });
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    while (true)
    {
        int R, C, ans = 0;
        cin >> C >> R;

        if (R == 0 && C == 0) {
            break;
        }

        vector<vector<int>> arr(R, vector<int>(C, 0));
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> arr[i][j];
            }
        }

        vector<vector<bool>> check(R, vector<bool>(C, false));
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (check[i][j] == false && arr[i][j] == 1) {
                    BFS(arr, check, R, C, { i, j });
                    ans++;

                }
            }
        }

        cout << ans << "\n";
    }
}