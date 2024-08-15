//https://www.acmicpc.net/problem/10844
#include <iostream>
#include <vector>
using namespace std;

#define MOD 1000000000

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int N, sum = 0;
    cin >> N;
    vector<vector<int>> dp(N, vector<int> (10,0));
    
    for (int i = 1; i < 10; i++) dp[0][i] = 1;
    

    for (int i = 1; i < N; i++) {
        dp[i][0] = dp[i - 1][1];
        for (int k = 1; k <= 8; k++) {
            dp[i][k] = (dp[i - 1][k + 1] + dp[i - 1][k - 1]) % MOD;
        }
        dp[i][9] = dp[i - 1][8];
    }

    for (int i = 0; i < 10; i++) sum = (sum + dp[N-1][i]) % MOD;
    
    cout << sum;
}