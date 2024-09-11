//https://www.acmicpc.net/problem/1005
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int N, K;
        
        cin >> N >> K;
        vector<vector<int>> g(N);
        vector<int> parent(N, 0);
        vector<int> time(N);

        for (int i = 0; i < N; i++) {
            cin >> time[i];
        }

        for (int i = 0; i < K; i++) {
            int s, e;
            cin >> s >> e;
            g[s-1].push_back(e-1);
            parent[e-1]++;
        }

        queue<int> q;
        vector<int> dp(N, 0);
        for (int i = 0; i < N; i++) {
            if (parent[i] == 0) {
                q.push(i);
                dp[i] = time[i];
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (int end : g[node]) {

                --parent[end];

                dp[end] = max(dp[end], dp[node] + time[end]);
                if (parent[end] == 0) {
                    q.push(end);
                }
            }
        }
        int target;
        cin >> target;

        cout << dp[target-1] << "\n";
    }

    return 0;
}
