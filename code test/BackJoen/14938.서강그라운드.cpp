//https://www.acmicpc.net/problem/14938
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int E, V, K;
    cin >> E >> K >> V;

    vector<int> value(E);
    for (int i = 0; i < E; i++) {
        cin >> value[i];
    }

    vector < vector<int>> dp(E, vector<int>(E, INT_MAX));
    
    for (int i = 0; i < V; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        dp[s-1][e-1] = w;
        dp[e-1][s-1] = w;
    }

    for(int k=0; k < E; k++){
        for (int i = 0; i < E; i++) {
            for (int j = 0; j < E; j++)
            {
                if (dp[i][k] != INT_MAX && dp[k][j] != INT_MAX && i != j) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
    }

    int ans_max = 0;
    for (int i = 0; i < E; i++) {
        int sum = value[i];
        for (int j = 0; j < E; j++)
        {
            if (dp[i][j] <= K) {
                sum += value[j];
            }
        }
        ans_max = max(sum, ans_max);
    }

    cout << ans_max;
}
