//https://www.acmicpc.net/problem/1562
#include <iostream>
#include <vector>
using namespace std;

#define MOD 1000000000

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    vector<vector<vector<long long>>> dp(N, vector<vector<long long>>(10, vector<long long>(1024, 0)));
    for (int i = 1; i < 10; i++) {
        dp[0][i][1 << i] = 1;
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 1024; k++) {
                int bit = k | (1 << j);
                if (j - 1 >= 0 && dp[i - 1][j - 1][k] != 0) {
                    dp[i][j][bit] += dp[i - 1][j - 1][k];
                }
                if (j + 1 < 10 && dp[i - 1][j + 1][k] != 0) {
                    dp[i][j][bit] += dp[i - 1][j + 1][k];
                }
                dp[i][j][bit] %= MOD;
            }
        }
    }

    long long sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += dp[N - 1][i][1023];
        sum %= MOD;
    }
    cout << sum << endl;
}
