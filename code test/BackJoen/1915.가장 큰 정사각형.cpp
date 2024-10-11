//https://www.acmicpc.net/problem/1915
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int find_squre(const vector<vector<int>>& dp, int N, int M, int size) {

    int targetSize = (size * size);
    for (int i = 0; i <= N - size; i++) {
        for (int j = 0; j <= M - size; j++) {
            int box = dp[i + size][j + size] - dp[i + size][j] - dp[i][j + size] + dp[i][j];
            if (box == targetSize) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> arr(N + 1, vector<int>(M + 1)), dp(N + 1, vector<int>(M + 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            char c;
            cin >> c;
            arr[i][j] = (c == '0') ? 0 : 1;
        }
    }
    for (int i = 0; i <= N; i++) arr[i][0] = 0;
    for (int i = 0; i <= M; i++) arr[0][i] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            dp[i][j] = arr[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }

    int max_size = min(N, M);
    int size;
    for (size = max_size; size >= 1; size--) {
        if (find_squre(dp, N, M, size)) {
            break;
        }
    }

    cout << (size * size);
}
