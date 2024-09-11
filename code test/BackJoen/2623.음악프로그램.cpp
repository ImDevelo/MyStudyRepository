//https://www.acmicpc.net/problem/2623
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    cin.ignore();
    vector<vector<int>> g(N);
    vector<int> parent(N, 0), result;
    for (int i = 0, n; i < K; ++i) {
        cin >> n;
        int s, e;
        for (int j = 0; j < n; j++) {
            cin >> s;
            if (j != 0) {
                g[s - 1].push_back(e - 1);
                parent[e - 1]++;
            }
            e = s;
        }
    }

    queue<int> q;

    for (int i = 0; i < N; i++) {
        if (parent[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for (int n : g[node]) {
            if (--parent[n] == 0) {
                q.push(n);
            }
        }
    }

    if (result.size() == N) {
        reverse(result.begin(), result.end());
        for (int n : result) {
            cout << n + 1 << " ";
        }
    }
    else {
        cout << 0;
    }

    return 0;
}
