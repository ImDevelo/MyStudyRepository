//https://www.acmicpc.net/problem/1904
#include <iostream>
#include <vector>
using namespace std;

#define MOD 15746

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int N; 
    cin >> N;
    vector<int> dp(N + 1);
    dp[0] = 1;   dp[1] = 2;
    for (int i = 2; i < N; i++) {
        dp[i] = (dp[i - 2] + dp[i - 1]) % MOD;
    }
    cout << dp[N-1];
}