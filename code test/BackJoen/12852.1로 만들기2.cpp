//https://www.acmicpc.net/problem/12852
#include <iostream>
#include <vector>
#include <stack>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int>> dp(N + 1, {0,0});

    dp[N] = { 1, N };
    for (int k = N; k > 0; k--) {
        int count = dp[k].first;
        int prev = dp[k].second;

        int next;
        if (k % 3 == 0) {
            next = k / 3;
            if (dp[next].first == 0 || dp[next].first > count + 1) {
                dp[next] = { count + 1, k };
            }
        }
        if (k % 2 == 0) {
            next = k / 2;
            if (dp[next].first == 0 || dp[next].first > count + 1) {
                dp[next] = { count + 1, k };
            }
        }
        next = k - 1;
        if (dp[next].first == 0 || dp[next].first > count + 1) {
            dp[next] = { count + 1, k };
        }
    }


    int index = 1;
    stack<int> result;
    while (!(index == N))
    {
        result.push(index);
        index = dp[index].second;
    }
    result.push(N);

    cout << result.size() - 1 << "\n";
    while(!result.empty()) {
        cout << result.top() << " ";
        result.pop();
    }

}