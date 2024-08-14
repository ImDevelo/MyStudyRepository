//점프
//https://www.acmicpc.net/problem/1890
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    
    int N;
    cin >> N;
    vector<vector<int>> arr(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    vector<vector<long>>dp(N, vector<long>(N, 0));
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            
            int jump_point = arr[i][j];
            long count_point = dp[i][j];

            if (jump_point == 0) {
                continue;
            }

            if (i+ jump_point < N) {
                dp[i + jump_point][j] += count_point;
            }
            if (j + jump_point < N) {
                dp[i][j + jump_point] += count_point;
            }
        }
    }

    cout << dp[N-1][N-1];
}