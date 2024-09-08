//https://www.acmicpc.net/problem/2252
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> g(N+1);
    vector<int> in_g(N + 1, 0);
    for(int i=0, s, e; i<M; i++){
        cin >> s >> e;
        g[s].push_back(e);
        in_g[e]++;
    }

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (in_g[i] == 0) {
            q.push(i);
        }
    }

    vector<int> result;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for (int a : g[node]) {
            in_g[a]--;
            if (in_g[a] == 0) {
                q.push(a);
            }
        }
    }

    for (int a : result) {
        cout << a << " ";
    }

    return 0;
}
