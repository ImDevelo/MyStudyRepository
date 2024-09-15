//https://www.acmicpc.net/problem/7579
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> m(N+1), v(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> m[i];
    }
    int R = 0;
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
        R += v[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(R + 1));
    for (int i = 0; i <= N; i++) dp[i][0] = 0;
    for (int i = 0; i <= R; i++) dp[0][i] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= R; j++) {
            if (v[i] <= j) {
                dp[i][j] = max(m[i] + dp[i - 1][j - v[i]], dp[i - 1][j]);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
            
        }
    }

    int value = 0;
    for (int i = 1; i <= R; i++) {
        if (dp[N][i] >= M) {
            value = i;
            break;
        }
    }

    cout << value;

}
