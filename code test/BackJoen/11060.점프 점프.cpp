//https://www.acmicpc.net/problem/11060
#include <iostream>
#include <vector>

using namespace std;

void dfs(const vector<int>& arr, vector<int>& dp, int N, int pos, int count, int& best) {
    if (N-1 <= pos) {
        if (best == 0 || best > count) {
            best = count;
        }
        return;
    }

    for (int i = arr[pos]; i > 0 ; i--) {
        int next = i + pos;
        if (next >= N) {
            continue;
        }
        else if (dp[next] == 0 || dp[next] > count) {
            dp[next] = count;
            dfs(arr, dp, N, next, count + 1, best);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int N, result = 0;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<int> dp(N, 0);
    dfs(arr, dp, N, 0, 1, result);

    cout << result-1;
}