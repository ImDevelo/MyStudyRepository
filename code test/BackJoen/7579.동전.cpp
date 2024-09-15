//https://www.acmicpc.net/problem/7579
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int N, K;
        cin >> N;
        vector<int> v(N + 1);
        for (int i = 1; i <= N; i++) {
            cin >> v[i];
        }
        cin >> K;
        vector<int> dp(K + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= N; i++) {
            int cost = v[i];
            for (int j = cost; j <= K; j++) {
                dp[j] = dp[j - cost] + dp[j];
                
            }
        }
        cout << dp[K] << "\n";
    }


}
