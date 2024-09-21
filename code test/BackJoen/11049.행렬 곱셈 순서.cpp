//https://www.acmicpc.net/problem/11049
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int best_metrix(vector<vector<int>>& dp, int N, int level, int start) {
    int best = INT_MAX;

    for (int i = 0; i < level; i++) {
        cout << dp[start][level - i - 1] * dp[start + level - i][i] << " ";
        best = min(best, dp[start][level - i - 1] * dp[start + level - i][i]);
        
    }

    cout << "best = " << best << "\n";
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    vector<vector<int>> dp(N+1, vector<int>(N+1));
    for (int i = 0, a , b; i < N; i++) {
        cin >> a >> b;
        dp[i][0] = a; 
        dp[i+1][0] = b;
    }

    // 3 이면 높이는 2까지 즉 3

    for (int lv = 1; lv <= N; lv++) {
        for (int i = 0; i <= N - lv; i++) {
            dp[i][lv] = best_metrix(dp, N, lv, i);
        }
    }

    cout << "\n";
    for (auto d : dp) {
        for (auto p : d) {
            cout << p << " ";
        }
        cout << "\n";
    }
}



